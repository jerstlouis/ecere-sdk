import "cgen"

define cw = 64; //84; // column width

void generateH(File f, CBindingsGenerator g, Module m)
{
   WalkerGenerator w;

   writeHardCodedHeader(f, g);

   PrintLn(" *** Classes");
   f.PrintLn("\n// Classes\n");
   w = { inSubNamespaces = true, inClasses = true, f = f; // allClasses, classNameDef
      void onClass(Class cl, NameSpace space, const char * name, Module module)
      {
#if 0 // if(!cl.templateClass) skipped stuff:
#define AVLNode<AT>                                                                          eC_AVLNode<AT>
#define AVLNode<KT>                                                                          eC_AVLNode<KT>
#define Container<BT, I = KT>                                                                eC_Container<BT, I = KT>
#define Container<LT>                                                                        eC_Container<LT>
#define CustomAVLTree<BT = ecere::com::AVLNode<AT>, KT = AT, T = AT, D = AT>                 eC_CustomAVLTree<BT = ecere::com::AVLNode<AT>, KT = AT, T = AT, D = AT>
#define CustomAVLTree<ecere::com::MapNode<MT, V>, I = MT, D = V, KT = MT>                    eC_CustomAVLTree<ecere::com::MapNode<MT, V>, I = MT, D = V, KT = MT>
#define Iterator<V, IT = KT>                                                                 eC_Iterator<V, IT = KT>
#define LinkList<ecere::com::Link, T = LLT, D = LLT>                                         eC_LinkList<ecere::com::Link, T = LLT, D = LLT>
#define Map<const String, const String>                                                      eC_Map<const String, const String>
#define Map<const String, ecere::com::Map<const String, const String> >                      eC_Map<const String, ecere::com::Map<const String, const String> >
#define MapNode<MT, V>                                                                       eC_MapNode<MT, V>
#define MapNode<const String, const String, T = const String>                                eC_MapNode<const String, const String, T = const String>
#define MapNode<const String, ecere::com::Map<const String, const String>, T = const String> eC_MapNode<const String, ecere::com::Map<const String, const String>, T = const String>
#endif
         if(!cl.templateClass)
         switch(cl.type)
         {
            case normalClass: case structClass: case noHeadClass: // bitClass, unitClass, enumClass, unionClass, systemClass
            {
               bool skip = skipTypes.Find(cl.name) || !strcmp(cl.name, "unichar") || !strcmp(cl.name, "bool"); //bool skip = !strcmp(cl.name, "unsigned int");// || !strcmp(cl.name, "unichar"); || !strcmp(cl.name, "bool");
               if(strcmp(cl.name, "char *"))
                  f.PrintLn(skip ? "// SKIPPED // " : "", "#define ", cl.name, spaces(skip ? cw-14 : cw, strlen(cl.name)), " eC_", cl.name);
               break;
            }
         }
      }
   };
   w.walk(m, false); delete w;
   f.PrintLn("");

   PrintLn(" *** Defines");
   f.PrintLn("\n// Defines\n");
   w = { inSubNamespaces = true, inDefines = true, f = f; // defines, normal
      void onDefine(DefinedExpression df, NameSpace space, const char * name, Module module)
      {
         const char * n = ( name = RSearchString(df.name, "::", strlen(df.name), false, false), name ? name + 2 : df.name);
         if(!strcmp(n, "null"))
         {
            f.PrintLn("#if defined(__cplusplus)");
            f.PrintLn("#define ", n, " 0");
            f.PrintLn("#else");
         }
         f.PrintLn("#define ", n, " ", df.value);
         if(!strcmp(n, "null"))
         {
            f.PrintLn("#endif");
            f.PrintLn("#define ", n, " ", df.value);
         }
      }
   };
   w.walk(m, false); delete w;
   f.PrintLn("");

   PrintLn(" *** C Functions");
   f.PrintLn("\n// C Functions\n");
   w = { inSubNamespaces = true, inFunctions = true, f = f; // functions, easyFuncName
      void onFunction(GlobalFunction fn, NameSpace space, const char * name, Module module)
      {
         if(!(module && fn.module && fn.module != homeModule/* && !(!strcmp(module.name, "ecereCOM") && !fn.module)*/))
         if(strstr(fn.dataTypeString, "dllexport") == fn.dataTypeString)
         {
            char * name = getMangledFunctionName(fn.name);
            char * fname = getNoNamespaceString(fn.name, null);
            const char * easy = easyFuncNames[name];
            if(easy)
               f.PrintLn("#define ", easy, spaces(32, strlen(easy)), " ", name);
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
                  f.PrintLn("#define ", s, spaces(32, strlen(s)), " ", name);
               }
            }
            delete fname;
         }
      }
   };
   w.walk(m, false); delete w;
   f.PrintLn("");

   PrintLn(" *** Virtual Methods Imports");
   f.PrintLn("\n// Virtual Methods Imports\n");
   w = { inSubNamespaces = true, inClasses = true, inMethods = true, f = f; // virtualMethods, virtualMethodImport
      void onClass(Class cl, NameSpace space, const char * name, Module module)
      {
         classClass = !strcmp(cl.name, "class");
         if(classClass)
         {
            Method md;
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
                     //if(!md.dataType) ProcessMethodType(md);
                     haveContent = true;
                     cgenPrintVirtualMethodDefs(f, cl, md, mname, classClass, assumeTypedObject, true);
                  }
               }
            }
         }
      }
      void onMethod(Method md, Class cl, NameSpace space, const char * name, Module module)
      {
#if 0 // if(!cl.templateClass) skipped stuff: all container methods for
extern Method * method_Container<BT, I = KT>_*
extern Method * method_Container<LT>_*
extern Method * method_Container<T>_*
#endif
         if(!cl.templateClass)
         if(md.memberAccess == publicAccess/* || (md.memberAccess == privateAccess && showPrivate)*/ && md.type == virtualMethod)
         {
            char * mname = copyCamelCaseString(md.name);
            if(!md.dataType) ProcessMethodType(md);
            f.PrintLn("extern Method * method_", cl.name, "_", mname, ";");
            haveContent = true;
            delete mname;
         }
      }
      void endClass(Class cl, NameSpace space, const char * name, Module module)
      {
         if(haveContent) { f.PrintLn(""); haveContent = false; }
      }
   };
   w.walk(m, false); delete w;
   f.PrintLn("");

   PrintLn(" *** Properties Imports");
   f.PrintLn("\n// Properties Imports\n");
   w = { inSubNamespaces = true, inClasses = true, inMembers = true, f = f; // properties, propertyImport
      void onClass(Class cl, NameSpace space, const char * name, Module module)
      {
         if(!cl.dataType) cl.dataType = ProcessTypeString(cl.dataTypeString, false);
      }
      void onMember(Property pt, Class cl, NameSpace space, const char * name, Module module)
      {
         if(!cl.templateClass)
         if(pt.isProperty) //if(pt.memberAccess == publicAccess || (pt.memberAccess == privateAccess && showPrivate))
         {
            char * pname = copySpecialSingleCharName(cl.name);
            char typeString[8192];
            bool structValue = false;
            bool ptr = false;
            if(!pt.dataType) pt.dataType = ProcessTypeString(pt.dataTypeString, false);
            typeString[0] = 0;
            PrintType(pt.dataType, typeString, false, false);
            //if(strcmp(typeString, pt.dataTypeString)) PrintLn("fail");
            f.PrintLn("extern Property * property_", cl.name, "_", pt.name, ";");
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
               case voidType: case structType: case unionType: case functionType: case ellipsisType: case arrayType:
               case methodType: case vaListType: //case typedObjectType: case anyObjectType: case classPointerType: case int128Type:
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
                        case voidType: case shortType: case intType: case int64Type: case longType: case floatType: case doubleType:
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
               f.PrintLn("extern void (* ", cl.name, "_set_", pt.name, ")(", cl.name, " ", pname, ", ", typeString, ptr ? " *" : "", " v);");
            if(pt.Get)
            {
               if(structValue)
                  f.PrintLn("extern void (* ", cl.name, "_get_", pt.name, ")(", cl.name, " ", pname, ", ", typeString, ptr ? " *" : "", " v);");
               else
                  f.PrintLn("extern ", typeString, " (* ", cl.name, "_get_", pt.name, ")(", cl.name, " ", pname, ");");
            }
            if(pt.IsSet)
               f.PrintLn("extern bool (* ", cl.name, "_isSet_", pt.name, ")(", cl.name, " ", pname, ");");
            f.PrintLn("");
            delete pname;
         }
      }
   };
   w.walk(m, false); delete w;
   f.PrintLn("");

   PrintLn(" *** Virtual Method Calls");
   f.PrintLn("\n// Virtual Method Calls\n");
   w = { inSubNamespaces = true, inClasses = true, inMethods = true, f = f; // virtualMethods, virtualMethodDefs
#if 0
      void onClass(Class cl, NameSpace space, const char * name, Module module)
      {
         classClass = !strcmp(cl.name, "class");
         if(classClass)
         {
            Method md;
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
                     //if(!md.dataType) ProcessMethodType(md);
                     haveContent = true;
                     cgenPrintVirtualMethodDefs(f, cl, md, mname, classClass, assumeTypedObject, true);
                  }
               }
            }
         }
      }
#endif // 0
      void onMethod(Method md, Class cl, NameSpace space, const char * name, Module module)
      {
         if(!cl.templateClass)
         if(md.memberAccess == publicAccess/* || (md.memberAccess == privateAccess && showPrivate)*/ && md.type == virtualMethod)
         {
            bool assumeTypedObject = false;
            char * mname = copyCamelCaseString(md.name);
            if(!md.dataType) ProcessMethodType(md);
            if(md.dataType && md.dataType.thisClass && md.dataType.thisClass.string && !strcmp(md.dataType.thisClass.string, "class"))
               assumeTypedObject = true;
            haveContent = true;
            cgenPrintVirtualMethodDefs(f, cl, md, mname, classClass, assumeTypedObject, false);
            delete mname;
         }
      }
      void endClass(Class cl, NameSpace space, const char * name, Module module)
      {
         if(haveContent) { f.PrintLn(""); haveContent = false; }
      }
   };
   w.walk(m, false); delete w;
   f.PrintLn("");

   PrintLn(" *** Types");
   f.PrintLn("\n// Types\n");
   w = { inSubNamespaces = true, inClasses = true, inMembers = true, f = f, ast = g.ast_H; // typedefs, normal
      void onMember(Property pt, Class cl, NameSpace space, const char * name, Module module)
      {
         if(!pt.isProperty)
         switch(pt.memberAccess)
         {
            case publicAccess:
            case privateAccess:
               if(pt.name && pt.dataTypeString)
               {
                  ASTClassDef def = null;
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
                  if(def)
                     defs.Add(def);
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
      void endClass(Class cl, NameSpace space, const char * name, Module module)
      {
         if(declStruct)
            ast.Add(declStruct);
      }
   };
   w.walk(m, false); delete w;
   w = { inSubNamespaces = true, inClasses = true, f = f; // all, normal
   };
   w.walk(m, false); delete w;
   initParser(null, f);
   g.ast_H.topoSort();
   f.PrintLn("");
   g.ast_H.print();
   f.PrintLn("");

   PrintLn(" *** Imports");
   f.PrintLn("\n// Imports\n");
   w = { inSubNamespaces = true, inFunctions = true, f = f; // functions, funcImport
      void onFunction(GlobalFunction fn, NameSpace space, const char * name, Module module)
      {
         if(!(module && fn.module && fn.module != homeModule/* && !(!strcmp(module.name, "ecereCOM") && !fn.module)*/))
         if(strstr(fn.dataTypeString, "dllexport") == fn.dataTypeString)
         {
            char * name = getMangledFunctionName(fn.name);
            bool done = false;
            char * dataTypeString = getNoNamespaceString(fn.dataTypeString, null);
            char * type = strstr(dataTypeString, " ");
            //if(!fn.dataType) fn.dataType = ProcessTypeString(fn.dataTypeString, false);
            if(type)
            {
               char * fname = strstr(type + 1, " ");
               char * params = strstr(type, "(");
               type++;
               *fname = 0;
               if(params)
               {
                  f.PrintLn("extern __attribute__((dllimport)) ", type, " ", name, params, ";");
                  done = true;
               }
            }
            if(!done)
               PrintLn("functions / funcImport >>>>>>>>> ", name, " -- ", dataTypeString);
            delete dataTypeString;
            delete name;
         }
      }
   };
   w.walk(m, false); delete w;
   f.PrintLn("");

   PrintLn(" *** Global Functions");
   f.PrintLn("\n// Global Functions\n");
   w = { inSubNamespaces = true, inFunctions = true, f = f; // functions, globalFunc
      void onFunction(GlobalFunction fn, NameSpace space, const char * name, Module module)
      {
         if(!(module && fn.module && fn.module != homeModule/* && !(!strcmp(module.name, "ecereCOM") && !fn.module)*/))
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
                  f.PrintLn("extern ", dataTypeString, " (*", fname, ")(", params, ";");
                  done = true;
               }
            }
            if(!done)
               PrintLn("functions / globalFunc >>>>>>>>> ", fn.name, " -- ", dataTypeString);
            delete dataTypeString;
         }
      }
   };
   w.walk(m, false); delete w;
   f.PrintLn("");

   PrintLn(" *** Classes");
   f.PrintLn("\n// Classes Import\n");
   w = { inSubNamespaces = true, inClasses = true, f = f; // allClasses, classImport
      void onClass(Class cl, NameSpace space, const char * name, Module module)
      {
         bool skip = !strcmp(cl.name, "unsigned int");
         f.PrintLn(skip ? "// SKIPPED // " : "", "extern Class * class_", cl.name, ";");
      }
   };
   w.walk(m, false); delete w;
   f.PrintLn("");

   PrintLn(" *** Virtual Method IDs");
   f.PrintLn("\n// Virtual Method IDs Import\n");
   w = { inSubNamespaces = true, inClasses = true, inMethods = true, f = f; // virtualMethods, virtualMethodIDs
      void onClass(Class cl, NameSpace space, const char * name, Module module)
      {
         classClass = !strcmp(cl.name, "class");
      }
      void onMethod(Method md, Class cl, NameSpace space, const char * name, Module module)
      {
         if(!cl.templateClass)
         if(md.memberAccess == publicAccess/* || (md.memberAccess == privateAccess && showPrivate)*/ && md.type == virtualMethod)
         {
            char * mname = copyCamelCaseString(md.name);
            if(!md.dataType) ProcessMethodType(md);
            f.PrintLn("extern int ", classClass ? "" : cl.name, classClass ? "" : "_", mname, "_vTblID;");
            haveContent = true;
            delete mname;
         }
      }
      void endClass(Class cl, NameSpace space, const char * name, Module module)
      {
         if(haveContent) { f.PrintLn(""); haveContent = false; }
      }
   };
   w.walk(m, false); delete w;
   f.PrintLn("");

/*
   w = { inSubNamespaces = true, inClasses = true, f = f; //
   };
   w.walk(m, false); delete w;
*/

/*
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
   //walkModule(mod, false, allClasses, dynamicBinding, false);
   fC.PrintLn("         // Set up all the function pointers, ...");
   fC.PrintLn("");
   //walkModule(mod, false, functions, dynamicBinding, false);
   fC.PrintLn("      }");
   fC.PrintLn("   }");
   fC.PrintLn("   return app;");
   fC.PrintLn("}");
   fC.PrintLn("");
   fC.PrintLn("Module __thisModule;");
*/

   //f.PrintLn("");
   //writeHardCodedEcereComFooter(f);
   //walkModule(mod, false, allClasses, classNameUndef, true);

   //walkModule(mod, false, functions, globalFunc, false);

   //PrintLn("listEnumDataTypes:");
   //for(s : listEnumDataTypes)
   //   PrintLn("  " , s);

   PrintLn(" *** Classes (undef)");
   f.PrintLn("");
   f.PrintLn("#ifdef __cplusplus");
   f.PrintLn("");
   w = { inSubNamespaces = true, inClasses = true, f = f; // allClasses, classNameUndef
      void onClass(Class cl, NameSpace space, const char * name, Module module)
      {
         if(!cl.templateClass)// && (!module || !cl.module || cl.module == homeModule))
         switch(cl.type)
         {
            case normalClass: case structClass: case noHeadClass: // bitClass, unitClass, enumClass, unionClass, systemClass
            {
               bool skip = skipTypes.Find(cl.name) || !strcmp(cl.name, "unichar") || !strcmp(cl.name, "bool"); //bool skip = !strcmp(cl.name, "unsigned int");// || !strcmp(cl.name, "unichar"); || !strcmp(cl.name, "bool");
               if(strcmp(cl.name, "char *"))
                  f.PrintLn(skip ? "// SKIPPED // " : "", "#undef ", cl.name);
               break;
            }
         }
      }
   };
   w.walk(m, false); delete w;
   f.PrintLn("");
   f.PrintLn("};");
   f.PrintLn("");
   f.PrintLn("#endif");
   f.PrintLn("");
   f.PrintLn("#endif");
}

void writeHardCodedHeader(File f, CBindingsGenerator g)
{
   f.PrintLn("/****************************************************************************");
   f.PrintLn("===========================================================================");
   if(g.ecereCOM)
      f.PrintLn("   Core eC Library");
   else
      f.PrintLn("   ", g.moduleName, " Module");
   f.PrintLn("===========================================================================");
   f.PrintLn("****************************************************************************/");
   f.PrintLn("");
   f.PrintLn("#if !defined(__", g.defineName, "_H__)");
   f.PrintLn("#define __", g.defineName, "_H__");
   f.PrintLn("");
   f.PrintLn("#define CPP11 (defined(__cplusplus) && __cplusplus >= 201103L)");
   f.PrintLn("");
   f.PrintLn("#ifdef __cplusplus");
   f.PrintLn("extern \"C\"");
   f.PrintLn("{");
   f.PrintLn("#endif");
   f.PrintLn("");
   if(g.ecereCOM)
   {
      f.PrintLn("#include <stdint.h>");
      f.PrintLn("#include <stdio.h>");
      f.PrintLn("#include <string.h>");
   }
   else
   {
      if(!strcmp(g.moduleName, "ecere"))
         f.PrintLn("#include \"eC.h\"");
      else
         f.PrintLn("#include \"ecere.h\"");
   }
   f.PrintLn("");

   if(g.ecereCOM)
   {
      // Syntactic Sugar
      f.PrintLn("#define $(x)      (constString)getTranslatedString(MODULE_NAME, x, null)");
      f.PrintLn("#define $$(x, c)  (constString)getTranslatedString(MODULE_NAME, x, c)");
      f.PrintLn("");
      f.PrintLn("#define _IPTR(x, c, s) ((struct s *)((x) ? (((char *)(x)) + c->offset) : 0))");
      f.PrintLn("#define IPTR(x, c) _IPTR(x, class_ ## c, c)");
      f.PrintLn("");
      f.PrintLn("#define incref(x) (x)->_refCount++;");
      f.PrintLn("");
      f.PrintLn("#define newb(c) eC_new(c)");
      f.PrintLn("#define newi(c) ({ eC_Instance i = Instance_new(c); incref(i); i; })");
      f.PrintLn("#define newc(t, c) (t *)eC_new(class_ ## t->structSize * c)");
      f.PrintLn("#define newt(t, c) (t *)eC_new(sizeof(t) * c)");
      f.PrintLn("");
      f.PrintLn("#define deletei(v) Instance_decref(v), v = null");
      f.PrintLn("#ifndef __cplusplus");
      f.PrintLn("   #define delete(v) eC_delete(v), v = null");
      f.PrintLn("#endif");
      f.PrintLn("");
      f.PrintLn("#ifndef __cplusplus");
      f.PrintLn("   #define registerClass(a, n, b)  \\");
      f.PrintLn("      eC_registerClass(normalClass, #n, #b, sizeof(struct n), 0, \\");
      f.PrintLn("         (void *)n ## _constructor, (void *)n ## _destructor, a, privateAccess, publicAccess)");
      f.PrintLn("#endif");
      f.PrintLn("");
      f.PrintLn("#define addMethod(c, n, m) \\");
      f.PrintLn("   Class_addMethod(c, n, null, (void *)m, publicAccess)");
      f.PrintLn("");
      f.PrintLn("#if defined(__WIN32__) && !defined(__CONSOLE_APP__)");
      f.PrintLn("   typedef void * HINSTANCE;");
      f.PrintLn("   #define WINAPI __stdcall");
      f.PrintLn("   #define MAIN_DECLARATION int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, char * cmdLine, int show)");
      f.PrintLn("   #define eC_init_CALL eC_init(true, 0, null)");
      f.PrintLn("#else");
      f.PrintLn("   #define MAIN_DECLARATION int main(int argc, char * argv[])");
      f.PrintLn("   #ifdef __cplusplus");
      f.PrintLn("      #if defined(__CONSOLE_APP__)");
      f.PrintLn("         #define eC_init_CALL eC_init(false, null, null)");
      f.PrintLn("      #else");
      f.PrintLn("         #define eC_init_CALL eC_init(true, null, null)");
      f.PrintLn("      #endif");
      f.PrintLn("   #else");
      f.PrintLn("      #if defined(__CONSOLE_APP__)");
      f.PrintLn("         #define eC_init_CALL eC_init(false, argc, argv)");
      f.PrintLn("      #else");
      f.PrintLn("         #define eC_init_CALL eC_init(true, argc, argv)");
      f.PrintLn("      #endif");
      f.PrintLn("   #endif");
      f.PrintLn("#endif");
      f.PrintLn("");
      f.PrintLn("#define APP_INTRO \\");
      f.PrintLn("   MAIN_DECLARATION \\");
      f.PrintLn("   { \\");
      f.PrintLn("      eC_Application app = eC_init_CALL;");
      f.PrintLn("");
      f.PrintLn("#define APP_OUTRO \\");
      f.PrintLn("      int exitCode = _IPTR(app, class_Application, class_members_Application)->exitCode; \\");
      f.PrintLn("      deletei(app); \\");
      f.PrintLn("      return exitCode; \\");
      f.PrintLn("   }");
   }
   else
   {
      f.PrintLn("#define ", g.defineName, "_APP_INTRO(c) \\");
      f.PrintLn("      APP_INTRO \\");
      f.PrintLn("      ", g.moduleName, "_init(app); \\");
      f.PrintLn("      loadTranslatedStrings(null, MODULE_NAME); \\");
      f.PrintLn("      Instance_evolve(&app, class_ ## c);");
      f.PrintLn("");
      f.PrintLn("#define ", g.defineName, "_APP_OUTRO \\");
      f.PrintLn("      unloadTranslatedStrings(MODULE_NAME); \\");
      f.PrintLn("      APP_OUTRO");
      f.PrintLn("");
      f.PrintLn("#define GUIAPP_INTRO ", g.defineName, "_APP_INTRO(GuiApplication)");
   }
   f.PrintLn("");
}
