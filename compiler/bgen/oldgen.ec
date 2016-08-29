import "bgen"

#include <math.h>

File fH;
File fC;

static AST astH;
static AST astC;

enum WalkSelection
{
   all,
      defines,
      functions,
      virtualMethods,
      properties,
      allClasses,
         //normalClass,
         //structClass,
         //bitClass,
         //unitClass,
         //enumClass,
         //noHeadClass,
         //unionClass,
         //systemClass,
      typedefs;

   property bool classes
   {
      get
      {
         switch(this)
         {
            case allClasses:
            //case normalClass:
            //case structClass:
            //case bitClass:
            //case unitClass:
            //case enumClass:
            //case noHeadClass:
            //case unionClass:
            //case systemClass:
               return true;
         }
         return false;
      }
   };

   property bool walkClasses
   {
      get
      {
         switch(this)
         {
            case all:
            case allClasses:
            //case normalClass:
            //case structClass:
            //case bitClass:
            //case unitClass:
            //case enumClass:
            //case noHeadClass:
            //case unionClass:
            //case systemClass:
            case virtualMethods:
            case properties:
            case typedefs:
               return true;
         }
         return false;
      }
   };
};
enum WalkMode
{
   normal,
   easyFuncName,
   classNameDef,
   classNameUndef,
   classImport,
   virtualMethodImport,
   propertyImport,
   funcImport,
   globalFunc,
   virtualMethodDefs,
   virtualMethodIDs,
   dynamicBinding,
   cleanup
};

define ecereNameSpace = "__ecereNameSpace__";

Map<const String, const String> easyFuncNames
{
   [
      { "__ecereNameSpace__ecere__com____ecere_COM_Initialize", "eC_initApp" }
   ]
};

static void walkModule(Module module, bool isDll, WalkSelection selection, WalkMode mode, bool forHeader)
{
   //SubModule m;

   //PrintLn("walkModule(", module ? module.name : "", ", ", isDll ? "isDll" : "", ", ", selection, ", ", mode, ", ", forHeader, ")");

   if(module.name && (/*!strcmp(module.name, "ecere") || */!strcmp(module.name, "ecereCOM")))
   {
      if(selection == typedefs)
      {
         addTypedefToAST("void *", "Type", normalClass);
         addTypedefToAST("void *", "Instantiation", normalClass);
         addTypedefToAST("void *", "ClassDefinition", normalClass);
         addTypedefToAST("uint64_t", "eC_TemplatizedType", normalClass);
      }
      walkNamespace(null, module.application.systemNameSpace, null, "", !isDll, selection, mode, forHeader);
   }

   /*for(m = module.modules.first; m; m = m.next)
   {
      if(m.importMode == publicAccess || !isDll)
         PrintLn("   submodule:", m.module.name); //walkModule(m.module, true, selection, mode, forHeader);
   }*/

   if(module.name && strcmp(module.name, "ecereCOM"))
   {
      walkNamespace(module, module.publicNameSpace, null /*module.application.systemNameSpace*/, "", !isDll, selection, mode, forHeader);
      if(!isDll)
         walkNamespace(module, module.privateNameSpace, null /*module.application.systemNameSpace*/, "", !isDll, selection, mode, forHeader);
   }
}

static void walkNamespace(Module module, NameSpace mainNameSpace, NameSpace comNameSpace, const char * parentName, bool showPrivate, WalkSelection selection, WalkMode mode, bool forHeader)
{
   char nsName[1024];
   NameSpace * ns;
   NameSpace * nameSpace = mainNameSpace;

   // this func contains stuff to not walk the ecereCOM parts of ecere... keep or lose?
   strcpy(nsName, parentName ? parentName : "");
   if(nameSpace->name)
   {
      if(nsName[0])
         strcat(nsName, "::");
      strcat(nsName, nameSpace->name);
   }

   if(comNameSpace != null)
      PrintLn("stop");

   for(ns = (NameSpace *)mainNameSpace.nameSpaces.first; ns; ns = (NameSpace *)((BTNode)ns).next)
   {
      NameSpace * comNS = (comNameSpace != null) ? (NameSpace *)comNameSpace.nameSpaces.FindString(ns->name) : null;
      walkNamespace(module, ns, comNS, nsName, showPrivate, selection, mode, forHeader);
   }
   if(comNameSpace != null)
   {
      for(ns = (NameSpace *)comNameSpace.nameSpaces.first; ns; ns = (NameSpace *)((BTNode)ns).next)
      {
         if(!mainNameSpace.nameSpaces.FindString(ns->name))
            walkNamespace(module, ns, null, nsName, showPrivate, selection, mode, forHeader);
      }
   }

   if(selection.walkClasses && (mainNameSpace.classes.first || (comNameSpace && comNameSpace.classes.first)))
   {
      for(nameSpace = mainNameSpace; nameSpace; nameSpace = (nameSpace == mainNameSpace) ? comNameSpace : null)
      {
         if(nameSpace->classes.first)
         {
            BTNamedLink link;
            Class cl;
            for(link = (BTNamedLink)nameSpace->classes.first; link; link = (BTNamedLink)((BTNode)link).next)
            {
               cl = link.data;
               /*if(!strcmp(cl.name, "Type"))
               {
                  bool skip = skipTypes.Find(cl.name);
                  PrintLn("", skip);
               }
               if(!strcmp(cl.name, "bool"))
               {
                  bool skip = skipTypes.Find(cl.name);
                  PrintLn("", skip);
               }*/
               //if(!cl.templateClass && (!module || cl.module == module || (!cl.module.name/* && !strcmp(module.name, "ecere")*/)))
               if(!cl.templateClass && (!module || !cl.module || cl.module == homeModule))
                  walkClass(module, cl, nsName, showPrivate, selection, mode, forHeader);
               /*{
                  if(selection == all || selection == typedefs)
                  else if(selection == classes)
                  {
                     fH.PrintLn();
                  }
               }*/
               else if(selection == all)
                  fH.PrintLn("// SKIPPED CLASS: ", cl.name);
            }
         }
      }
   }

   if(selection == functions && (mainNameSpace.functions.first || (comNameSpace && comNameSpace.functions.first)))
   {
      for(nameSpace = mainNameSpace ; nameSpace; nameSpace = (nameSpace == mainNameSpace) ? comNameSpace : null)
      {
         if(nameSpace->functions.first)
         {
            BTNamedLink link;
            GlobalFunction fn;
            for(link = (BTNamedLink)nameSpace->functions.first; link; link = (BTNamedLink)((BTNode)link).next)
            {
               fn = link.data;
               if(module && fn.module && fn.module != homeModule/* && !(!strcmp(module.name, "ecereCOM") && !fn.module)*/) continue;
               if(mode == easyFuncName || mode == funcImport)
               {
                  if(strstr(fn.dataTypeString, "dllexport") == fn.dataTypeString)
                  {
                     char * name = getMangledFunctionName(fn.name);
                     if(mode == easyFuncName)
                     {
                        char * fname = getNoNamespaceString(fn.name, null);
                        const char * easy = easyFuncNames[name];
                        if(easy)
                           fH.PrintLn("#define ", easy, spaces(32, strlen(easy)), " ", name);
                        else
                        {
                           strcpySubstring(fname, "eSystem", "eC");
                           {
                              char * s = strstr(fname, "_");
                              if(s && ++s) *s = (char)tolower(*s);
                              s = fname;
                              if(*fname == 'e'/* && ecere/ecereCOM*/)
                              {
                                 if(
                                       strstr(fname, "eInstance_") == fname ||
                                       strstr(fname, "eClass_") == fname ||
                                       strstr(fname, "eModule_") == fname ||
                                       strstr(fname, "eEnum_") == fname ||
                                       strstr(fname, "eMember_") == fname ||
                                       strstr(fname, "eProperty_") == fname
                                 )
                                    s++;
                                 else if(strstr(fname, "eC_") == fname)
                                    ;
                                 else
                                    PrintLn("");
                              }
                              fH.PrintLn("#define ", s, spaces(32, strlen(s)), " ", name);
                           }
                        }
                        delete fname;
                     }
                     else if(mode == funcImport)
                     {
                        bool done = false;
                        char * dataTypeString = getNoNamespaceString(fn.dataTypeString, null);
                        char * type = strstr(dataTypeString, " ");
                        //if(!fn.dataType)
                        //   fn.dataType = ProcessTypeString(fn.dataTypeString, false);
                        if(type)
                        {
                           char * fname = strstr(type + 1, " ");
                           char * params = strstr(type, "(");
                           type++;
                           *fname = 0;
                           if(params)
                           {
                              fH.PrintLn("extern __attribute__((dllimport)) ", type, " ", name, params, ";");
                              done = true;
                           }
                        }
                        if(!done)
                           PrintLn("functions / funcImport >>>>>>>>> ", name, " -- ", dataTypeString);
                        delete dataTypeString;
                     }
                     delete name;
                  }
               }
               else if(mode == globalFunc)
               {
                  if(!strstr(fn.dataTypeString, "dllexport") && !/*((!module || !module.name) && */skipFunctionTree.Find(fn.name)/*)*/)
                  {
                     bool done = false;
                     char * dataTypeString = getFuncTypeString(fn.dataTypeString); //getNoNamespaceString(fn.dataTypeString, null);
                     char * fname = strstr(dataTypeString, " ");
                     if(fname && *(fname + 1) == '*')
                        fname = strstr(fname + 1, " ");
                     if(fname)
                     {
                        char * params = strstr(fname + 1, "(");
                        if(params)
                        {
                           *fname++ = 0;
                           *params++ = 0;
                           if(forHeader)
                              fH.PrintLn("extern ", dataTypeString, " (*", fname, ")(", params, ";");
                           else
                              fC.PrintLn(dataTypeString, " (*", fname, ")(", params, ";");
                           done = true;
                        }
                     }
                     if(!done)
                        PrintLn("functions / globalFunc >>>>>>>>> ", fn.name, " -- ", dataTypeString);
                     delete dataTypeString;
                  }
               }
               else if(mode == dynamicBinding)
               {
                  if(!strstr(fn.dataTypeString, "dllexport") && !/*((!module || !module.name) && */skipFunctionTree.Find(fn.name)/*)*/)
                  {
                     char * fname = getNoNamespaceString(fn.name, null);
                     if(fname && *fname)
                     {
                        fC.PrintLn("");
                        fC.PrintLn("         function_", fname, " = eC_findFunction(app, \"", fname, "\");");
                        fC.PrintLn("         if(function_", fname, ")");
                        fC.PrintLn("            ", fname, " = (void *)function_", fname, "->function;");
                     }
                     else
                        PrintLn("tmp");
                  }
               }
               else
               //if(!module || fn.module == module || (!fn.module.name && !strcmp(module.name, "ecere")))
               //if(fn.module == module)
               {
                  /*if(!fn.dataType)
                     fn.dataType = ProcessTypeString(fn.dataTypeString, false);*/
                  //const char * name = ( name = RSearchString(fn.name, "::", strlen(fn.name), false, false), name ? name + 2 : fn.name);
                  // functions here?
                  DeclarationInit decl = null;
                  decl = getGlobalFuncDeclWhatnotFromFunction(fn);
                  /*
                  if(!(BTNamedLink)((BTNode)link).next)
                     PrintLn("d");
                  if(decl)
                  {
                     for(s : decl.specifiers)
                     {
                      //&& !strcmp(decl.specifiers[1][0].id.string, "sprintf"))
                        //PrintLn(s._class.name);
                        if(s._class == class(SpecBase))
                           ;
                        {
                           //SpecBase x = (SpecBase)s;
                           //PrintLn(x.specifier);
                        }
                        else if(s._class == class(SpecName))
                        {
                           SpecName x = (SpecName)s;
                           if(strstr(x.name, "sprintf"))
                              PrintLn("-");
                           PrintLn(x.name);
                        }
                        else
                           PrintLn("-");
                     }
                     //PrintLn("-");
                  }
                  for(s : decl.declarators)
                  {
                     PrintLn(s._class.name);
                     if(s._class == class(ASTInitDeclarator))
                     {
                        ASTInitDeclarator x = (ASTInitDeclarator)s;
                        if(x.initializer._class == class(ASTInitializer))
                        {
                           ASTInitializer i = x.initializer;
                        }
                        else
                        PrintLn(x.initializer._class.name);
                        PrintLn(x.declarator._class.name);
                        //if(strstr(x, "sprintf"))
                        //   PrintLn("-");
                        //PrintLn(x.name);
                        PrintLn("-");
                     }
                     else
                        PrintLn("-");
                  }*/
                  if(decl) astH.Add(decl);
               }
            }
         }
      }
   }

   if(selection == defines && (mainNameSpace.defines.first || (comNameSpace && comNameSpace.defines.first)))
   {
      for(nameSpace = mainNameSpace; nameSpace; nameSpace = (nameSpace == mainNameSpace) ? comNameSpace : null)
      {
         if(/*nameSpace->module == homeModule && */nameSpace->defines.first)
         {
            BTNamedLink link;
            DefinedExpression def;
            for(link = (BTNamedLink)nameSpace->defines.first; link; link = (BTNamedLink)((BTNode)link).next)
            {
               def = link.data;
               {
                  const char * name = ( name = RSearchString(def.name, "::", strlen(def.name), false, false), name ? name + 2 : def.name);
                  if(!strcmp(name, "null"))
                  {
                     fH.PrintLn("#if defined(__cplusplus)");
                     fH.PrintLn("#define ", name, " 0");
                     fH.PrintLn("#else");
                  }
                  fH.PrintLn("#define ", name, " ", def.value);
                  if(!strcmp(name, "null"))
                  {
                     fH.PrintLn("#endif");
                     fH.PrintLn("#define ", name, " ", def.value);
                  }
               }
            }
         }
      }
   }
}

static void addTypedefToAST(const char * typeString, const char * name, ClassType type)
{
   DeclarationInit declTypedef { };
   if(type == structClass)
   {
      declTypedef.specifiers = { [
         SpecBase { specifier = _typedef },
         SpecClass { type = _struct, id = ASTIdentifier { string = CopyString(typeString) } }
      ] };
   }
   else if(type == enumClass)
   {
      declTypedef.specifiers = { [
         SpecBase { specifier = _typedef },
         SpecClass { type = _enum, id = ASTIdentifier { string = CopyString(typeString) } }
      ] };
   }
   else if(type == normalClass)
   {
      declTypedef.specifiers = { [
         SpecBase { specifier = _typedef },
         SpecClass { id = ASTIdentifier { string = CopyString(typeString) } }
      ] };
   }
   else
      PrintLn("error: addTypedefToAST input error. unsupported ClassType ", type);
   declTypedef.declarators = { [
      ASTInitDeclarator { declarator = DeclIdentifier { identifier = ASTIdentifier { string = CopyString(name) } } }
   ] };
   astH.Add(declTypedef);
}

static void walkClass(Module module, Class cl, char * nsName, bool showPrivate, WalkSelection selection, WalkMode mode, bool forHeader)
{
   Method md;
   Property pt;
   bool haveContent;
   bool classClass = !strcmp(cl.name, "class");
   if(!cl.dataType)
      cl.dataType = ProcessTypeString(cl.dataTypeString, false);
   if(selection == typedefs)
      PrintLn("stop");

   if(selection.classes)
   {
      if(mode == cleanup)
      {
         for(md = (Method)cl.methods.first; md; md = (Method)((BTNode)md).next)
         {
            if(md.dataType)
            {
               FreeType(md.dataType);
               /*if(md._class.symbol)
                  FreeSymbol(md._class.symbol);*/
            }
         }
         for(pt = (Property)cl.membersAndProperties.first; pt; pt = pt.next)
         {
            if(pt.dataType)
               FreeType(pt.dataType);
         }
         if(cl.dataType)
            FreeType(cl.dataType);
      }
      else if(mode == classNameDef || mode == classNameUndef)
      {
         /*if(
               (selection == normalClass && cl.type == normalClass) ||
               (selection == structClass && cl.type == structClass) || // Structs / Unions (with methods or properties?)
               (selection == bitClass && cl.type == bitClass) ||
               (selection == unitClass && cl.type == unitClass) ||
               (selection == enumClass && cl.type == enumClass) ||
               (selection == noHeadClass && cl.type == noHeadClass) || // class : struct (with methods or properties?)
               (selection == unionClass && cl.type == unionClass) ||
               (selection == systemClass && cl.type == systemClass)
            )*/
         {
            switch(cl.type)
            {
               case bitClass:
               case unitClass:
               case enumClass:
               case unionClass:
               case systemClass:
                  break;
               case normalClass:
               case structClass:
               case noHeadClass:
               default:
               {
                  bool skip = skipTypes.Find(cl.name) || !strcmp(cl.name, "unichar") || !strcmp(cl.name, "bool");
                  //bool skip = !strcmp(cl.name, "unsigned int");// || !strcmp(cl.name, "unichar"); || !strcmp(cl.name, "bool");
                  if(strcmp(cl.name, "char *"))
                  {
                     if(mode == classNameDef)
                        fH.PrintLn(skip ? "// SKIPPED // " : "", "#define ", cl.name,
                              spaces(skip ? 32-14 : 32, strlen(cl.name)), " eC_", cl.name);
                     else // mode == classNameUndef
                        fH.PrintLn(skip ? "// SKIPPED // " : "", "#undef ", cl.name);
                  }
               }
            }
         }
         return;
      }
      else if(mode == classImport)
      {
         bool skip = !strcmp(cl.name, "unsigned int");
         fC.PrintLn(skip ? "// SKIPPED // " : "", "Class * class_", cl.name, ";");
         fH.PrintLn(skip ? "// SKIPPED // " : "", "extern Class * class_", cl.name, ";");
         return;
      }
      else if(mode == dynamicBinding)
      {
         bool first = true;
         fC.PrintLn("         class_", cl.name, " = eC_findClass(app, \"", cl.name, "\");");
         haveContent = false;
         if(cl.methods.first)
         {
            for(md = (Method)cl.methods.first; md; md = (Method)((BTNode)md).next)
            {
               if(md.type != virtualMethod) continue;
               if(md.memberAccess != publicAccess) continue;
               haveContent = true;
               break;
            }
            if(!haveContent)
            {
               for(pt = (Property)cl.membersAndProperties.first; pt; pt = pt.next)
               {
                  if(!pt.isProperty) continue;
                  haveContent = true;
                  break;
               }
            }
         }
         if(haveContent)
         {
            fC.PrintLn("         if(class_", cl.name, ")");
            fC.PrintLn("         {");
            //class's methods:
            if(cl.methods.first)
            {
               for(md = (Method)cl.methods.first; md; md = (Method)((BTNode)md).next)
               {
                  if(md.type != virtualMethod) continue;
                  if(md.memberAccess != publicAccess) continue;
                  {
                     char * mname = CopyString(md.name);
                     *mname = (char)tolower(*mname);
                     if(!first)
                        fC.PrintLn("");
                     else
                        first = false;
                     fC.PrintLn("            method_", cl.name, "_", mname, " = Class_findMethod(class_", cl.name, ", \"", md.name, "\", app);");
                     fC.PrintLn("            if(method_", cl.name, "_", mname, ")");
                     fC.PrintLn("               ", mname, "_vTblID = method_", cl.name, "_", mname, "->vid;");
                  }
               }
            }
            //class's properties:
            if(cl.membersAndProperties.first)
            {
               for(pt = (Property)cl.membersAndProperties.first; pt; pt = pt.next)
               {
                  if(!pt.isProperty) continue;
                  if(!first)
                     fC.PrintLn("");
                  else
                     first = false;
                  fC.PrintLn("            property_", cl.name, "_", pt.name, " = Class_findProperty(class_", cl.name, ", \"", pt.name, "\", app);");
                  //fC.PrintLn("               ", mname, "_vTblID = method_", cl.name, "_", mname, "->vid;");
                  if(pt.Set)
                     fC.PrintLn("            ", cl.name, "_set_", pt.name, " = (void *)property_", cl.name, "_", pt.name, "->Set;");
                  if(pt.Get)
                     fC.PrintLn("            ", cl.name, "_get_", pt.name, " = (void *)property_", cl.name, "_", pt.name, "->Get;");
                  if(pt.IsSet)
                     fC.PrintLn("            ", cl.name, "_isSet_", pt.name, " = (void *)property_", cl.name, "_", pt.name, "->IsSet;");
               }
            }
            fC.PrintLn("         }");
         }
      }
   }
   else if(selection == virtualMethods)
   {
      if(cl.methods.first)
      {
         haveContent = false;
         for(md = (Method)cl.methods.first; md; md = (Method)((BTNode)md).next)
         {
            if(md.memberAccess == publicAccess/* || (md.memberAccess == privateAccess && showPrivate)*/ && md.type == virtualMethod)
            {
               char * mname = copyCamelCaseString(md.name);
               if(!md.dataType)
                  ProcessMethodType(md);
               //PrintLn(cl.name, "::", md.name, " - > ", md.dataTypeString);
               // todo: use lowercased copy of md.name
               if(mode == virtualMethodImport)
               {
                  fC.PrintLn("Method * method_", cl.name, "_", mname, ";");
                  fH.PrintLn("extern Method * method_", cl.name, "_", mname, ";");
                  haveContent = true;
               }
               else if(mode == virtualMethodIDs)
               {
                  fC.PrintLn("int ", classClass ? "" : cl.name, classClass ? "" : "_", mname, "_vTblID;");
                  fH.PrintLn("extern int ", classClass ? "" : cl.name, classClass ? "" : "_", mname, "_vTblID;");
                  haveContent = true;
               }
               else if(mode == virtualMethodDefs && cl.type != structClass)
               {
                  bool assumeTypedObject = false;
                  if(md.dataType && md.dataType.thisClass && md.dataType.thisClass.string && !strcmp(md.dataType.thisClass.string, "class"))
                     assumeTypedObject = true;
                  haveContent = true;
                  printVirtualMethodDefs(cl, md, mname, classClass, assumeTypedObject, false);
               }
               delete mname;
            }
         }
         if(haveContent)
         {
            if(mode == virtualMethodIDs || mode == virtualMethodImport)
            {
               fC.PrintLn("");
               fH.PrintLn("");
            }
            else if(mode == virtualMethodDefs)
               fH.PrintLn("");
         }
         if(classClass)
         {
            for(md = (Method)cl.methods.first; md; md = (Method)((BTNode)md).next)
            {
               if(md.memberAccess == publicAccess/* || (md.memberAccess == privateAccess && showPrivate)*/ && md.type == virtualMethod)
               {
                  bool assumeTypedObject = false;
                  if(md.dataType && md.dataType.thisClass && md.dataType.thisClass.string && !strcmp(md.dataType.thisClass.string, "class"))
                     assumeTypedObject = true;
                  if(assumeTypedObject)
                  {
                     char * mname = copyCamelCaseString(md.name);
                     /*if(!md.dataType)
                        ProcessMethodType(md);*/
                     haveContent = true;
                     printVirtualMethodDefs(cl, md, mname, classClass, assumeTypedObject, true);
                  }
               }
            }
         }
      }
      return;
   }
   else if(selection == properties)
   {
      if(cl.membersAndProperties.first)
      {
         for(pt = (Property)cl.membersAndProperties.first; pt; pt = pt.next)
         {
            if(!pt.isProperty) continue;
            //if(pt.memberAccess == publicAccess || (pt.memberAccess == privateAccess && showPrivate))
            {
               if(!pt.dataType) pt.dataType = ProcessTypeString(pt.dataTypeString, false);
               if(mode == propertyImport)
               {
                  char * pname = copySpecialSingleCharName(cl.name);
                  char typeString[8192];
                  bool structValue = false;
                  bool ptr = false;
                  typeString[0] = 0;
                  PrintType(pt.dataType, typeString, false, false);
                  //if(strcmp(typeString, pt.dataTypeString)) PrintLn("fail");
                  fC.PrintLn("Property * property_", cl.name, "_", pt.name, ";");
                  fH.PrintLn("extern Property * property_", cl.name, "_", pt.name, ";");
                  switch(pt.dataType.kind)
                  {
                     case intType: case floatType: case doubleType: case int64Type: //case pointerType:
                        break;
                     case subClassType:
                        strcpy(typeString, "Class");
                        break;
                     case thisClassType:
                        typeString[0] = 0;
                        PrintType(cl.dataType, typeString, false, false);
                        break;
                     case charType: case shortType: //case intType: case int64Type:
                     case longType: //case floatType: case doubleType:
                        //break;
                     case intPtrType: case intSizeType: case _BoolType:
                        //break;
                     case enumType:
                        //break;
                     //case classType:
                        //break;
                     case dummyType: //case subClassType: case thisClassType:
                        //break;
                     case templateType:
                        //break;
                     case voidType: case structType: case unionType: case functionType:
                     case ellipsisType: case arrayType: case methodType: case vaListType:
                     //case typedObjectType: case anyObjectType: case classPointerType: case int128Type:
                        //break;
                        PrintLn("mi: how to handle all these property kinds?");
                        break;
                     case classType:
                        if(pt.dataType._class.registered)
                        {
                           switch(pt.dataType._class.registered.type)
                           {
                              case normalClass:
                                 if(pt.dataType._class.registered.module != homeModule)
                                 {
                                    // TODO: improve this?
                                    /*if(homeModule.name && !strcmp(homeModule.name, "ecereCOM") && param._class.registered.module.name &&
                                          !strcmp(param._class.registered.module.name, "ecere"))
                                       strcpy(typeString, "Instance");*/
                                    PrintLn("ddd");
                                 }
                                 break;
                              case structClass:
                                 ptr = true;
                                 break;
                              case noHeadClass:
                                 ptr = true;
                                 break;
                              case enumClass: case bitClass: case unitClass:
                              // unionClass: // Temporary only in firstPass
                              case systemClass:
                                 break;
                              default:
                                 PrintLn("error: Unknown ClassType?");
                           }
                        }
                        break;
                     case pointerType:
                        if(pt.dataType.type)
                        {
                           switch(pt.dataType.type.kind)
                           {
                              case charType:
                                 if(!strcmp(typeString, "const char *"))
                                    strcpy(typeString, "constString");
                                 else if(!strcmp(typeString, "char *"))
                                    ;//
                                 else
                                    PrintLn("tmp");
                                 break;
                              case voidType: case shortType: case intType: case int64Type:
                              case longType: case floatType: case doubleType:
                                 break;
                              case pointerType: // typeString == "char * *" // is there a charType deeper in?
                                 PrintLn("tmp");
                                 break;
                              case classType:
                                 getNoNamespaceString(pt.dataType.type._class.string, typeString);
                                 break;
                              default:
                                 PrintLn("error: unknown TypeKind ", pt.dataType.type.kind, " for property datatype's type kind.");
                           }
                        }
                        else
                           PrintLn("tmp");
                        break;
                     default:
                        PrintLn("error: unknown TypeKind ", pt.dataType.kind, " for property datatype kind.");
                  }
                  if(pt.Set)
                  {
                     fC.PrintLn(       "void (* ", cl.name, "_set_", pt.name, ")(", cl.name, " ", pname, ", ", typeString, ptr ? " *" : "", " v);");
                     fH.PrintLn("extern void (* ", cl.name, "_set_", pt.name, ")(", cl.name, " ", pname, ", ", typeString, ptr ? " *" : "", " v);");
                  }
                  if(pt.Get)
                  {
                     if(structValue)
                     {
                        fC.PrintLn(       "void (* ", cl.name, "_get_", pt.name, ")(", cl.name, " ", pname, ", ", typeString, ptr ? " *" : "", " v);");
                        fH.PrintLn("extern void (* ", cl.name, "_get_", pt.name, ")(", cl.name, " ", pname, ", ", typeString, ptr ? " *" : "", " v);");
                     }
                     else
                     {
                        fC.PrintLn(           typeString, " (* ", cl.name, "_get_", pt.name, ")(", cl.name, " ", pname, ");");
                        fH.PrintLn("extern ", typeString, " (* ", cl.name, "_get_", pt.name, ")(", cl.name, " ", pname, ");");
                     }
                  }
                  if(pt.IsSet)
                  {
                     fC.PrintLn(       "bool (* ", cl.name, "_isSet_", pt.name, ")(", cl.name, " ", pname, ");");
                     fH.PrintLn("extern bool (* ", cl.name, "_isSet_", pt.name, ")(", cl.name, " ", pname, ");");
                  }
                  fC.PrintLn("");
                  fH.PrintLn("");
                  delete pname;
               }
            }
         }
      }
   }

   if(skipTypes.Find(cl.name))
      ;
   else if(!strcmp(cl.name, "bool"))
      ; // todo
   else if(cl.type == systemClass || cl.type == unitClass || !strcmp(cl.name, "String"))
   {
      if(selection == typedefs)
         addTypedefToAST(systemTypeSubst(cl.name, cl.dataTypeString), cl.name, normalClass);
   }
   else if(cl.type == bitClass)
   {
      if(selection == typedefs)
         addTypedefToAST("uint32", cl.name, normalClass); // todo?: support multiple size?
   }
   else if(cl.type == enumClass)
   {
      /**/
      if(selection == typedefs)
         addTypedefToAST(cl.name/*dataTypeString*/, cl.name, enumClass);
      else// if(selection == enumValues)
      {
         EnumClassData enumeration = (EnumClassData)cl.data;
         NamedLink item;
         fH.Print("enum ", cl.name, " {");
         for(item = enumeration.values.first; item; item = item.next)
         {
            // enum values here?
            fH.Print(item == enumeration.values.first ? "\n" : ",\n", "   ", item.name);
            PrintLn(item.data);
         }
         fH.PrintLn("\n};");
      }
   }
   else // if(cl.type == d)
   {
      if(selection == typedefs)
      {
         if(!strcmp(cl.name, "Window"))
            PrintLn("stop");
         if(cl.type == noHeadClass || cl.type == structClass)
            addTypedefToAST(cl.name, cl.name, structClass);
         else if(cl.type == normalClass)
         {
            if(cl.base)
               addTypedefToAST(cl.base.name, cl.name, normalClass);
            else
               PrintLn("stop");
         }
      }
      else if(selection == all)
      {
         ClassDefList defs = null;
         DeclarationInit declStruct = null;

         /*if(!strcmp(cl.name, "BinaryTree"))
            PrintLn("");*/

         if(cl.membersAndProperties.first)
         {
            for(pt = (Property)cl.membersAndProperties.first; pt; pt = pt.next)
            {
               if(pt.isProperty) continue;
               switch(pt.memberAccess)
               {
                  case publicAccess:
                  case privateAccess:
                     if(pt.name && pt.dataTypeString)
                     {
                        ASTClassDef def;
                        if(!declStruct)
                        {
                           defs = { };
                           declStruct =
                           {
                              specifiers = { [
                                 SpecClass {
                                    type = _struct, id =
                                       ASTIdentifier
                                       {
                                          string = cl.type == normalClass ?
                                                PrintString("class_members_", cl.name) : CopyString(cl.name)
                                       },
                                    definitions = defs
                                 }
                              ] }
                           };
                        }
                        if(!pt.dataType)
                           pt.dataType = ProcessTypeString(pt.dataTypeString, false);
                        def = getClassDefDeclFromMember(pt, pt.memberAccess == privateAccess);
                        if(def) defs.Add(def);
                     }
                     else if(pt.name)
                     {
                        if(!pt.isProperty)
                           fH.PrintLn("// SKIPPED MEMBER: ", cl.name, "::", pt.name);
                     }
                     break;
                  case defaultAccess:
                  case staticAccess:
                  case baseSystemAccess:
                     PrintLn("tmp");
                     break;
                  default:
                     PrintLn("tmp");
                     break;
               }
            }
            if(declStruct)
               astH.Add(declStruct);
         }

         if(cl.membersAndProperties.first)
         {
            for(pt = (Property)cl.membersAndProperties.first; pt; pt = pt.next)
            {
               if(!pt.isProperty) continue;
               //if(pt.memberAccess == publicAccess || (pt.memberAccess == privateAccess && showPrivate))
               {
                  if(!pt.dataType)
                     pt.dataType = ProcessTypeString(pt.dataTypeString, false);
                  // properties here?
                  // if(pt.isProperty)
               }
            }
         }

         if(cl.conversions.first)
         {
            for(pt = cl.conversions.first; pt; pt = pt.next)
            {
               const char * name;
               name = RSearchString(pt.name, "::", strlen(pt.name), true, false);
               if(name) name += 2; else name = pt.name;
               // conversions here?
            }
         }
      }
   }
}

static void printVirtualMethodDefs(Class cl, Method md, const char * mname, bool classClass, bool assumeTypedObject, bool forInstance)
{
   int charCount = 0;
   int ap;
   const char * thisClassName = null;
   bool prev;
   Type param;
   if(md.dataType/* && md.dataType.kind == functionType*/)
      thisClassName = md.dataType.staticMethod ? null : md.dataType.thisClass ? md.dataType.thisClass.className : cl.name;
   if(forInstance)
   {
      charCount = 23 + strlen(mname) + 2 + (thisClassName ? 3 : 0) + (assumeTypedObject ? 3 : 0);
      fH.Print("#define Instance_", mname, "(c, i");
   }
   else
   {
      charCount += 10 + 2 + (classClass ? 0 : strlen(cl.name)) + strlen(mname);
      prev = thisClassName || assumeTypedObject;
      if(prev)
      {
         charCount += 4 + md.dataType.params.count * 2;
         if(assumeTypedObject)
            charCount += 6;
      }
      fH.Print("#define ", classClass ? "" : cl.name, "_", mname, "(");
      if(thisClassName)
         fH.Print("i");
      else if(assumeTypedObject)
         fH.Print("c, i");
   }
   for(ap = 0, param = md.dataType.params.first; param; param = param.next)
   {
      //if(!param.type || (param.type.kind == voidType && !param.name))
      //   PrintLn("he"); param.
      //if(!param.type || (param.type.kind == voidType && !param.name)) continue;
      if(param.kind == voidType && !param.name) continue;
      if(prev || param.prev) fH.Print(", ");
      if(param.name)
      {
         fH.Print(param.name);
         charCount += strlen(param.name);
      }
      else
      {
         fH.Print("ap", ++ap);
         charCount += 2 + floor(log10(ap)) + 1;
      }
   }
   if(forInstance)
   {
      fH.Print(")", spaces(64, charCount), "_", mname, "((i) ? (i)->_class : c, i");
   }
   else
   {
      fH.Print(") ");
      fH.Print(spaces(64, charCount), "({ void (* method)(");
      printParamsType(thisClassName, assumeTypedObject, md.dataType.params);
      fH.Print(") = (void (*)(");
      printParamsType(thisClassName, assumeTypedObject, md.dataType.params);
      fH.Print("))");
      if(thisClassName)
         fH.Print("(i ? i->_vTbl : class_", thisClassName, "->_vTbl)");
      else if(assumeTypedObject)
         fH.Print("((c) ? (c)->_vTbl : class_", cl.name, "->_vTbl)");
      else
         fH.Print("(class_", cl.name, "->_vTbl)");
      fH.Print("[", assumeTypedObject ? "" : cl.name, assumeTypedObject ? "" : "_", mname, "_vTblID]; ");
      fH.Print("if(method) ", md.dataType.returnType.kind == voidType ? "" : "return ", "method(");
      if(thisClassName)
         fH.Print("i");
      else if(assumeTypedObject)
         fH.Print("(c), i");
   }
   for(ap = 0, param = md.dataType.params.first; param; param = param.next)
   {
      if(param.kind == voidType && !param.name) continue;
      fH.Print((prev || param.prev) ? ", " : "");
      if(param.name)
         fH.Print(param.name);
      else
         fH.Print("ap", ++ap);
   }
   if(forInstance)
      fH.PrintLn(")");
   else
      fH.PrintLn("); })");
}

static void printParamsType(const char * thisClassName, bool assumeTypedObject, OldList params)
{
   Type param;
   bool prev = thisClassName || assumeTypedObject;
   if(thisClassName)
      fH.Print("eC_", thisClassName);
   else if(assumeTypedObject)
      fH.Print("eC_Class *, void *");
   for(param = params.first; param; param = param.next)
   {
      char typeString[8192];
      //bool constCharPtr;
      bool prefix = false;
      if(param.kind == voidType && !param.name) continue;
      typeString[0] = 0;
      PrintType(param, typeString, false, false);
      //constCharPtr = strstr(typeString, "const char *") == typeString;
      //if(!strcmp(typeString, "T"))
      //   PrintLn("tmp");
      switch(param.kind)
      {
         case charType:
         case shortType:
         case intType:
         case int64Type:
         case longType:
         case floatType:
         case doubleType:
            break;
         case intPtrType:
         case intSizeType:
         case _BoolType:
            break;
         case enumType:
            PrintLn("mi: what do we do for parameters of enumType kind?");
            break;
         case classType:
            if(param._class.registered)
            {
               switch(param._class.registered.type)
               {
                  case enumClass:
                  case bitClass:
                     break;
                  case normalClass:
                     if(param._class.registered.module != homeModule)
                     {
                        // TODO: improve this?
                        if(homeModule.name && !strcmp(homeModule.name, "ecereCOM") && param._class.registered.module.name &&
                              !strcmp(param._class.registered.module.name, "ecere"))
                           strcpy(typeString, "Instance");
                     }
                  case structClass:
                  case unitClass:
                  case noHeadClass:
                  // unionClass: // Temporary only in firstPass
                  case systemClass:
                     prefix = true;
                     break;
                  default:
                     PrintLn("error: Unknown ClassType?");
               }
            }
            else
               prefix = true;
            break;
         case dummyType:
         case subClassType:
         case thisClassType:
            PrintLn("mi: what do we do for parameters of dummyType, subClassType and thisClassType kinds?");
            break;
         case templateType:
            PrintLn("mi: what do we do for parameters of templateType kind?");
            break;
         case voidType:
         case structType:
         case unionType:
         case functionType:
         case ellipsisType:
         case arrayType:
         case methodType:
         case vaListType:
         //case typedObjectType:
         //case anyObjectType:
         //case classPointerType:
         //case int128Type:
            PrintLn("mi: are these special cases or kinds that only apply to other constructs?");
            break;
         case pointerType:
            if(param.type)
            {
               switch(param.type.kind)
               {
                  case voidType:
                  case charType:
                  case shortType:
                  case intType:
                  case int64Type:
                  case longType:
                  case floatType:
                  case doubleType:
                  case pointerType: // typeString == "char * *" // is there a charType deeper in?
                     break;
                  case classType:
                     getNoNamespaceString(param.type._class.string, typeString);
                     break;
                  default:
                     PrintLn("error: unknown TypeKind for pointerType parameters of ", param.type.kind, " kind?");
               }
            }
            else
               PrintLn("tmp");
            break;
         default:
            PrintLn("error: unknown TypeKind ", param.kind, " for parameter.");
      }
      fH.Print((prev || param.prev) ? ", " : "", prefix ? "eC_" : "", typeString);
   }
}

static DeclarationInit getGlobalFuncDeclWhatnotFromFunction(GlobalFunction fn)
{
   DeclarationInit decl = null;
   char * name = getNoNamespaceString(fn.name, null);
   char * dataTypeString = getNoNamespaceString(fn.dataTypeString, null);
   char * pointer = getFunctionPointerDeclFromDataTypeString(dataTypeString);
   //char * n, * name = (char*)fn.name, * dataTypeString = (char*)fn.dataTypeString;
   //while((n = strstr(name, "::"))) name = n+2;
   //while((n = strstr(dataTypeString, "::"))) dataTypeString = n+2;
   //OldList ol = (fn.dataType && fn.dataType.params) ? fn.dataType.params : null;
   //int count = ol ? ol.count : -1;
   //PrintLn("FUNCITON: ", dataTypeString/*, " ", fn.name*/, " -- ", fn.dataType ? fn.dataType.name : "", " ");//, count);
   //if(function.dataType.params.first && ((Type)function.dataType.params.first).kind != voidType)
   /*if(!strstr(dataTypeString, "dllexport"))
      PrintLn("tmp");
   if(strstr(name, "eSystem_") == name)
      PrintLn("tmp");*/
   /*if(!strcmp(name, "acos"))
      PrintLn("tnp");*/
   if(skipFunction(name, fn.module.name, fn.nameSpace))
      ;
   else
   {
      TempFile f { };
      f.Print(pointer, ";");
      initParser(f, null);
      f.Seek(0, start);
      {
         ASTNode node = AST::parseExternalDeclaration();
         if(node)
         {
            if(node._class == class(DeclarationInit))
            {
               decl = (DeclarationInit)node;
            }
            else
               PrintLn("warning: got unexpected ", node._class.name, " from AST::parseExternalDeclaration(\"", pointer, ";", "\")");
         }
         else
            PrintLn("warning: unable to get DeclarationInit from AST::parseExternalDeclaration(\"", pointer, ";", "\")");
      }
      delete f;
   }

   delete name;
   delete dataTypeString;
   delete pointer;

   return decl;
}

void processModule(const char * moduleName, const char * moduleNameAllCaps, bool ecereCOM)
{
   CBindingsGenerator cgen { bindingName, moduleName, moduleNameAllCaps, ecereCOM };
   Module mod = homeModule; //componentsApp;
   fC.PrintLn("#include \"", bindingName, ".h\"");
   fC.PrintLn("");

   writeHardCodedHeader(fH, cgen);

      PrintLn(" *** Classes");
   fH.PrintLn("\n// Classes\n");
   walkModule(mod, false, allClasses, classNameDef, true);
   fH.PrintLn("");

      PrintLn(" *** Defines");
   fH.PrintLn("\n// Defines\n");
   walkModule(mod, false, defines, normal, true);
   fH.PrintLn("");

      PrintLn(" *** C Functions");
   fH.PrintLn("\n// C Functions\n");
   walkModule(mod, false, functions, easyFuncName, true);
   fH.PrintLn("");

      PrintLn(" *** Virtual Methods Imports");
   fH.PrintLn("\n// Virtual Methods Imports\n");
   walkModule(mod, false, virtualMethods, virtualMethodImport, true);
   fC.PrintLn("");
   fH.PrintLn("");

      PrintLn(" *** Properties Imports");
   fH.PrintLn("\n// Properties Imports\n");
   walkModule(mod, false, properties, propertyImport, true);
   fC.PrintLn("");
   fH.PrintLn("");

      PrintLn(" *** Virtual Method Calls");
   fH.PrintLn("\n// Virtual Method Calls\n");
   walkModule(mod, false, virtualMethods, virtualMethodDefs, true);
   fH.PrintLn("");

#if 0
      PrintLn(" *** Types");
   fH.PrintLn("\n// Types\n");
   walkModule(mod, false, typedefs, normal, true);
   walkModule(mod, false, all, normal, true);
   initParser(null, fH);
   astH.topoSort();
   fH.PrintLn("");
   astH.print();
   fH.PrintLn("");

      PrintLn(" *** Imports");
   fH.PrintLn("\n// Imports\n");
   walkModule(mod, false, functions, funcImport, true);
   fH.PrintLn("");

      PrintLn(" *** Global Functions");
   fH.PrintLn("\n// Global Functions\n");
   walkModule(mod, false, functions, globalFunc, true);
   fH.PrintLn("");

      PrintLn(" *** Classes");
   fC.PrintLn("\n// Classes\n");
   fH.PrintLn("\n// Classes Import\n");
   walkModule(mod, false, allClasses, classImport, true);
   fC.PrintLn("");
   fH.PrintLn("");

      PrintLn(" *** Virtual Method IDs");
   fC.PrintLn("\n// Virtual Method IDs\n");
   fH.PrintLn("\n// Virtual Method IDs Import\n");
   walkModule(mod, false, virtualMethods, virtualMethodIDs, true);
   fC.PrintLn("");
   fH.PrintLn("");
#endif // 0

   //fH.PrintLn("");
   //writeHardCodedEcereComFooter(fH);
   fH.PrintLn("");
   fH.PrintLn("#ifdef __cplusplus");
   fH.PrintLn("");
   walkModule(mod, false, allClasses, classNameUndef, true);
   fH.PrintLn("");
   fH.PrintLn("};");
   fH.PrintLn("");
   fH.PrintLn("#endif");
   fH.PrintLn("");
   fH.PrintLn("#endif");

#if 0
   walkModule(mod, false, functions, globalFunc, false);

   //PrintLn("listEnumDataTypes:");
   //for(s : listEnumDataTypes)
   //   PrintLn("  " , s);

   initParser(null, fC);
   astC.topoSort();
   fC.PrintLn("");
   astC.print();
   fC.PrintLn("");

   fC.PrintLn("Application ", bindingName, "_init(bool guiApp, int argc, char * argv[])");
   fC.PrintLn("{");
   fC.PrintLn("   Application app = eC_initApp(guiApp, argc, argv);");
   fC.PrintLn("   if(app)");
   fC.PrintLn("   {");
   fC.PrintLn("      Module module = Module_load(app, \"", homeModule.name, "\", publicAccess);");
   fC.PrintLn("      app->_refCount++;");
   fC.PrintLn("      if(module)");
   fC.PrintLn("      {");
   fC.PrintLn("         // Set up all the class_*, property, method, ...");
   fC.PrintLn("");
   walkModule(mod, false, allClasses, dynamicBinding, false);
   fC.PrintLn("         // Set up all the function pointers, ...");
   fC.PrintLn("");
   walkModule(mod, false, functions, dynamicBinding, false);
   fC.PrintLn("      }");
   fC.PrintLn("   }");
   fC.PrintLn("   return app;");
   fC.PrintLn("}");
   fC.PrintLn("");
   fC.PrintLn("Module __thisModule;");
#endif // 0

   FreeTypeData(mod);
   walkModule(mod, false, allClasses, cleanup, true);
   delete cgen;
}

const char * bindingName;
bool prepForBindingsGeneration(const char * name)
{
   char fileName[MAX_FILENAME];
   if(readyGeneratedDir(fileName, true))
   {
      bindingName = name;
      PathCatSlash(fileName, name);
      ChangeExtension(fileName, "c", fileName);
      fC = FileOpen(fileName, write);
      ChangeExtension(fileName, "h", fileName);
      fH = FileOpen(fileName, write);
      if(fC && fH)
      {
         astC = { };
         astH = { };
         //Platform os = __runtimePlatform;
         ec1init(null);
         return true;
      }
   }
   return false;
}

void terminateBindingsGeneration()
{
   delete fC;
   delete fH;
   if(astC) astC.Free();
   delete astC;
   if(astH) astH.Free();
   delete astH;
   ec1terminate();
}
