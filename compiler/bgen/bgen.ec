import "ecere"
import "ec"
import "ec2"

ConsoleFile console { };

File fH;
File fC;

AST astH;
AST astC;

static Context globalContext { };
static OldList defines { };
static OldList imports { };
static NameSpace globalData;
static OldList excludedSymbols { offset = (uint)(uintptr)&((Symbol)0).left };

Application componentsApp;
Module homeModule;

define app = (GuiApplication)__thisModule.application;

enum WalkSelection
{
   all,
      defines,
      functions,
      virtualMethods,
      allClasses,
         normalClass,
         structClass,
         bitClass,
         unitClass,
         enumClass,
         noHeadClass,
         unionClass, // Temporary only in firstPass
         systemClass,
      typedefs;

   property bool classes
   {
      get
      {
         switch(this)
         {
            case allClasses:
            case normalClass:
            case structClass:
            case bitClass:
            case unitClass:
            case enumClass:
            case noHeadClass:
            case unionClass:
            case systemClass:
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
            case normalClass:
            case structClass:
            case bitClass:
            case unitClass:
            case enumClass:
            case noHeadClass:
            case unionClass:
            case systemClass:
            case virtualMethods:
            case typedefs:
               return true;
         }
         return false;
      }
   };
};
enum WalkMode { normal, easyFuncName, classNameDef, classNameUndef, classImport, funcImport, globalFunc, virtualMethodDefs, virtualMethodIds };

define ecereNameSpace = "__ecereNameSpace__";
const char * spaces = \
      "                                                                " \
      "                                                                " \
      "                                                                " \
      "                                                                " \
      "                                                                " \
      "                                                                " \
      "                                                                " \
      "                                                                ";

const char * getColumnRemainSpaces(int colSize, int stringSize)
{
   return spaces + strlen(spaces) - Min(Max(0, colSize - stringSize), strlen(spaces));
}

Map<const String, const String> easyFuncNames
{
   [
      { "__ecereNameSpace__ecere__com____ecere_COM_Initialize", "eC_initApp" },
      { "__ecereNameSpace__ecere__com__eSystem_SetArgs", "eC_setArgs" },
      { "__ecereNameSpace__ecere__com__eSystem_FindClass", "eC_findClass" },
      { "__ecereNameSpace__ecere__com__eClass_IsDerived", "Class_isDerived" },
      { "__ecereNameSpace__ecere__com__eInstance_NewEx", "Instance_newEx" },
      { "__ecereNameSpace__ecere__com__eInstance_DecRef", "Instance_decref" },
      { "__ecereNameSpace__ecere__com__eSystem_RegisterClass", "eC_registerClass" },
      { "__ecereNameSpace__ecere__com__eSystem_New", "eC_new" },
      { "__ecereNameSpace__ecere__com__eSystem_New0", "eC_new0" },
      { "__ecereNameSpace__ecere__com__eSystem_Delete", "eC_delete" },
      { "__ecereNameSpace__ecere__com__eSystem_FindFunction", "eC_findFunction" },
      { "__ecereNameSpace__ecere__com__eClass_AddMethod", "Class_addMethod" },
      { "__ecereNameSpace__ecere__com__eClass_FindMethod", "Class_findMethod" },
      { "__ecereNameSpace__ecere__com__eClass_FindProperty", "Class_findProperty" },
      { "__ecereNameSpace__ecere__com__eModule_Load", "Module_load" },
      { "__ecereNameSpace__ecere__com__eInstance_New", "Instance_new" },
      { "__ecereNameSpace__ecere__com__eInstance_Delete", "Instance_delete" },
      { "__ecereNameSpace__ecere__com__eInstance_Evolve", "Instance_evolve" },
      { "__ecereNameSpace__ecere__com__eInstance_SetMethod", "Instance_setMethod" },
      { "__ecereNameSpace__ecere__GetTranslatedString", "getTranslatedString" },
      { "__ecereNameSpace__ecere__LoadTranslatedStrings", "loadTranslatedStrings" },
      { "__ecereNameSpace__ecere__UnloadTranslatedStrings", "unloadTranslatedStrings" }
   ]
};

static void openModule(const char * filePath)
{
   char moduleName[MAX_LOCATION];
   char extension[MAX_EXTENSION];
   Module module = null;
   static char symbolsDir[MAX_LOCATION];

   FreeContext(globalContext);
   FreeExcludedSymbols(excludedSymbols);
   ::defines.Free(FreeModuleDefine);
   imports.Free(FreeModuleImport);
   FreeGlobalData(globalData);
   FreeIncludeFiles();
   if(componentsApp)
   {
      FreeTypeData(componentsApp);
      delete componentsApp;
   }

   componentsApp = __ecere_COM_Initialize(false, 1, null);
   SetPrivateModule(componentsApp);
   StripLastDirectory(filePath, symbolsDir);
   SetSymbolsDir(symbolsDir);
   GetExtension(filePath, extension);

   ImportModule(filePath, normalImport, publicAccess, false);

   if(extension[0] && strcmpi(extension, "so") && strcmpi(extension, "dll") && strcmpi(extension, "dylib"))
      componentsApp.name = CopyString(filePath);

   for(module = componentsApp.allModules.first; module; module = module.next)
   {
      if(module.name && (!strcmp(module.name, "ecere") || !strcmp(module.name, "ecereCOM")))
         break;
   }
   if(!module)
      eModule_LoadStrict(componentsApp, "ecereCOM", publicAccess /*privateAccess*/);

   GetLastDirectory(filePath, moduleName);
   // Extension, path and lib prefix get removed in Module::name
   if(extension[0])
   {
      StripExtension(moduleName);
      if((!strcmpi(extension, "so") || !strcmpi(extension, "dylib")) && strstr(moduleName, "lib") == moduleName)
      {
         int len = strlen(moduleName) - 3;
         memmove(moduleName, moduleName + 3, len);
         moduleName[len] = 0;
      }
   }

   for(module = componentsApp.allModules.first; module; module = module.next)
   {
      if(module.name && (!strcmp(module.name, moduleName)))
         break;
   }
   if(!module) module = componentsApp;
   homeModule = module;

   SetSymbolsDir(null);
}

static void walkModule(Module module, bool isDll, WalkSelection selection, WalkMode mode, bool forHeader)
{
   SubModule m;

   PrintLn("walkModule(", module ? module.name : "", ", ", isDll ? "isDll" : "", ", ", selection, ", ", mode, ", ", forHeader, ")");

   if(module.name && (!strcmp(module.name, "ecere") || !strcmp(module.name, "ecereCOM")))
   {
      if(selection == typedefs)
      {
         addTypedefToAST("void *", "Type", false);
         addTypedefToAST("void *", "Instantiation", false);
         addTypedefToAST("void *", "ClassDefinition", false);
         addTypedefToAST("uint64_t", "eC_TemplatizedType", false);
      }
      walkNamespace(null, module.application.systemNameSpace, null, "", !isDll, selection, mode, forHeader);
   }

   for(m = module.modules.first; m; m = m.next)
   {
      if(m.importMode == publicAccess || !isDll)
         walkModule(m.module, true, selection, mode, forHeader);
   }

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
      for(nameSpace = mainNameSpace ; nameSpace; nameSpace = (nameSpace == mainNameSpace) ? comNameSpace : null)
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
                  bool skip = skipTypes[cl.name];
                  PrintLn("", skip);
               }
               if(!strcmp(cl.name, "bool"))
               {
                  bool skip = skipTypes[cl.name];
                  PrintLn("", skip);
               }*/
               if(!cl.templateClass && (!module || cl.module == module || (!cl.module.name && !strcmp(module.name, "ecere"))))
                  walkClass(module, cl, nsName, showPrivate, selection, mode, forHeader);
               /*{
                  if(selection == all || selection == typedefs)
                  else if(selection == classes)
                  {
                     fH.PrintLn();
                  }
               }*/
               else if(selection == all)
                  PrintLn("SKIPPED CLASS: ", cl.name);
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
               if(mode == easyFuncName || mode == funcImport)
               {
                  if(strstr(fn.dataTypeString, "dllexport") == fn.dataTypeString)
                  {
                     char * name = getMangledFunctionName(fn.name);
                     if(mode == easyFuncName)
                     {
                        const char * easy = easyFuncNames[name];
                        if(easy)
                           fH.PrintLn("#define ", easy, getColumnRemainSpaces(32, strlen(easy)), " ", name);
                     }
                     else if(mode == funcImport)
                     {
                        bool done = false;
                        char * dataTypeString = getNoNamespaceString(fn.dataTypeString);
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
                  if(!strstr(fn.dataTypeString, "dllexport") && !((!module || !module.name) && skipFunctionMap[fn.name]))
                  {
                     bool done = false;
                     char * dataTypeString = getFuncTypeString(fn.dataTypeString); //getNoNamespaceString(fn.dataTypeString);
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
               else
               if(!module || fn.module == module || (!fn.module.name && !strcmp(module.name, "ecere")))
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
      for(nameSpace = mainNameSpace ; nameSpace; nameSpace = (nameSpace == mainNameSpace) ? comNameSpace : null)
      {
         if(nameSpace->defines.first)
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

Map<const String, bool> skipFunctionMap { [
   { "acos", true },
   { "acosh", true },
   { "asin", true },
   { "asinh", true },
   { "atan", true },
   { "atan2", true },
   { "atanh", true },
   { "atof", true },
   { "atoi", true },
   { "ceil", true },
   { "cos", true },
   { "cosh", true },
   { "exp", true },
   { "fabs", true },
   { "floor", true },
   { "fmod", true },
   { "fputs", true },
   { "getenv", true },
   { "isalnum", true },
   { "isalpha", true },
   { "isblank", true },
   { "isdigit", true },
   { "islower", true },
   { "isprint", true },
   { "isspace", true },
   { "isupper", true },
   { "isxdigit", true },
   { "log", true },
   { "log10", true },
   { "memcmp", true },
   { "memcpy", true },
   { "memmove", true },
   { "memset", true },
   { "pow", true },
   { "printf", true },
   { "puts", true },
   { "qsort", true },
   { "rename", true },
   { "sin", true },
   { "sinh", true },
 //{ "sprintf", true },
   { "sprintf", true },
   { "sqrt", true },
   { "strcasecmp", true },
   { "strcat", true },
   { "strchr", true },
   { "strcmp", true },
   { "strcpy", true },
   { "strcspn", true },
   { "strlen", true },
   { "strlwr", true },
   { "strncasecmp", true },
   { "strncat", true },
   { "strncmp", true },
   { "strncpy", true },
   { "strpbrk", true },
   { "strspn", true },
   { "strstr", true },
   { "strtod", true },
   { "strtol", true },
   { "strtoll", true },
   { "strtoul", true },
   { "strtoull", true },
   { "strupr", true },
   { "system", true },
   { "tan", true },
   { "tanh", true },
   { "tolower", true },
   { "toupper", true },
   { "vsnprintf", true },
   { "vsprintf", true }
] };

static bool skipFunction(const char * name, const char * moduleName, NameSpace * ns)
{
   if(!moduleName && skipFunctionMap[name])
      return true;
   if(islower(name[0]) && strstr(name, "eClass") != name && strstr(name, "eSystem") != name && strstr(name, "eEnum") != name &&
          strstr(name, "eInstance") != name && strstr(name, "eMember") != name && strstr(name, "eModule") != name &&
          strstr(name, "eProperty") != name)
      PrintLn("SHOULD WE SKIP FUNCTION: ", name, moduleName ? " from " : "", moduleName ? moduleName : "",
            (ns && ns->name) ? " / " : "", (ns && ns->name) ? ns->name : "");
   return false;
}

Map<String, bool> skipTypes { [
   { "char", true },
   { "char *", true },
   { "double", true },
   { "float", true },
   { "int", true },
   { "short", true },
   { "unsigned int", true },
   { "enum", true },
   { "struct", true },
   { "cclass", true }
] };

Map<const String, const String> sysTypeMap { [
   { "String", "char *" },
   { "byte", "uint8_t" },
   { "int64", "int64_t" },
   { "intptr", "intptr_t" },
   { "intsize", "ssize_t" },
   { "uint", "uint32_t" },
   { "uint16", "uint16_t" },
   { "uint32", "uint32_t" },
   { "uint64", "uint64_t" },
   { "uintptr", "uintptr_t" },
   { "uintsize", "size_t" },
   { "unichar", "uint32_t" }
] };

static const char * systemTypeSubst(const char * name, const char * dataTypeString)
{
   const char * subst = sysTypeMap[name];
   return subst ? subst : dataTypeString;
}

//Map<String, String> listEnumDataTypes { };

static void addTypedefToAST(const char * type, const char * name, bool typeStruct)
{
   DeclarationInit declTypedef { };
   if(typeStruct)
   {
      declTypedef.specifiers = { [
         SpecBase { specifier = _typedef },
         SpecClass { type = _struct, id = ASTIdentifier { string = CopyString(type) } }
      ] };
   }
   else
   {
      declTypedef.specifiers = { [
         SpecBase { specifier = _typedef },
         SpecClass { id = ASTIdentifier { string = CopyString(type) } }
      ] };
   }
   declTypedef.declarators = { [
      ASTInitDeclarator { declarator = DeclIdentifier { identifier = ASTIdentifier { string = CopyString(name) } } }
   ] };
   astH.Add(declTypedef);
}

static void walkClass(Module module, Class cl, char * nsName, bool showPrivate, WalkSelection selection, WalkMode mode, bool forHeader)
{
   Method md;
   Property pt;

   if(selection.classes)
   {
      if(mode == classNameDef || mode == classNameUndef)
      {
         if(
               (selection == normalClass && cl.type == normalClass) ||
               (selection == structClass && cl.type == structClass) || // Structs / Unions (with methods or properties?)
               (selection == bitClass && cl.type == bitClass) ||
               (selection == unitClass && cl.type == unitClass) ||
               (selection == enumClass && cl.type == enumClass) ||
               (selection == noHeadClass && cl.type == noHeadClass) || // class : struct (with methods or properties?)
               (selection == unionClass && cl.type == unionClass) ||
               (selection == systemClass && cl.type == systemClass)
            )
         {
            bool skip = selection == systemClass || selection == unionClass || skipTypes[cl.name] || !strcmp(cl.name, "unichar") || !strcmp(cl.name, "bool");
            if(mode == classNameDef)
               fH.PrintLn(skip ? "// SKIPPED // " : "", "#define ", cl.name, getColumnRemainSpaces(skip ? 32-14 : 32, strlen(cl.name)), " eC_", cl.name);
            else
               fH.PrintLn(skip ? "// SKIPPED // " : "", "#undef ", cl.name);
         }
         return;
      }
      else if(mode == classImport)
      {
         bool skip = !strcmp(cl.name, "unsigned int");
         fH.PrintLn(skip ? "// SKIPPED // " : "", "extern Class * class_", cl.name, ";");
         return;
      }
   }
   else if(selection == virtualMethods)
   {
      if(cl.methods.first)
      {
         for(md = (Method)cl.methods.first; md; md = (Method)((BTNode)md).next)
         {
            if(md.memberAccess == publicAccess/* || (md.memberAccess == privateAccess && showPrivate)*/ && md.type == virtualMethod)
            {
               if(!md.dataType)
                  ProcessMethodType(md);
               PrintLn(cl.name, "::", md.name, " - > ", md.dataTypeString);
               // todo: use lowercased copy of md.name
               {
                  bool done = false;
                  char * dataTypeString = getNoNamespaceString(md.dataTypeString);
                  char * type = dataTypeString;
                  if(type)
                  {
                     //char * fname = strstr(type + 1, " ");
                     char * params = strstr(type, "(");
                     //type++;
                     //*fname = 0;
                     if(params)
                     {
                        char * end = strstr(params, ")");
                        char * mname = CopyString(md.name);
                        *mname = tolower(*mname);
                        *params++ = 0;
                        if(end) *end = 0;
                        //fH.PrintLn("extern __attribute__((dllimport)) ", type, " ", name, params, ";");

                        if(mode == virtualMethodIds)
                           fH.PrintLn("extern int ", cl.name, "_", mname, "_vTblID;");
                        else if(mode == virtualMethodDefs)
                        {
                           fH.Print("#define ", cl.name, "_", mname, "(");
                           if(*params)
                           {
                              char *prms[32];
                              int count = TokenizeWith(params, 32, prms, ",", true);
                              int n;
                              for(n = 0; n < count; n++)
                              {
                                 char * pname = strstr(prms[n], " ");
                                 if(pname)
                                 {
                                 }
                                 fH.Print(n ? ", " : "", "p", n);
                              }
                              //PrintLn(" TODO: DON'T IGNORE PARAMS!");
                           }
                           fH.Print(")");
                           if(!strcmp(type, "void"))
                           {
                              //fH.PrintLn("#define ", cl.name, "_", mname, "(i) ( \\");
                              fH.PrintLn(" ( \\");
                              fH.PrintLn("      { eC_", cl.name, " i = x; \\");
                              fH.PrintLn("      void (* method)(eC_", cl.name, ") = \\");
                              fH.PrintLn("      (void (*)(eC_", cl.name, "))(i ? i->_vTbl : class_", cl.name, "->_vTbl)[", cl.name, "_", mname, "_vTblID]; \\");
                              fH.PrintLn("      if(method) method(i); })");
                           }
                           else
                           {
                              fH.PrintLn(" ({ void (* method)(", cl.name, ") = ((i) ? (i)->_vTbl : class_", cl.name, "->_vTbl)[", cl.name, "_", cl.name, "_vTblID]; \\");
                              fH.PrintLn("      return method ? method((i)) : null; })");
                           }

                           done = true;
                        }
                        delete mname;
                     }
                  }
                  delete dataTypeString;
               }
               // if(md.type == virtualMethod)
                  // if(md.dataType.thisClass)
            }
         }
      }
      return;
   }

   if(skipTypes[cl.name])
      ;
   else if(!strcmp(cl.name, "bool"))
   {
      if(selection == typedefs)
         addTypedefToAST("uint32_t", cl.name, false);
   }
   else if(cl.type == systemClass || cl.type == unitClass || !strcmp(cl.name, "String"))
   //else if(cl.type == unitClass)
   {
      if(selection == typedefs)
         addTypedefToAST(systemTypeSubst(cl.name, cl.dataTypeString), cl.name, false);
   }
   else if(cl.type == bitClass)
   {
      //PrintLn("bitClass: ", cl.name);
      PrintLn("todo");
   }
   else if(cl.type == enumClass)
   {
      /*EnumClassData enumeration = (EnumClassData)cl.data;
      NamedLink item;
      for(item = enumeration.values.first; item; item = item.next)
      {
         // enum values here?
      }*/
      if(selection == typedefs)
         addTypedefToAST(cl.dataTypeString, cl.name, false);
   }
   else // if(cl.type == d)
   {
      if(selection == typedefs)
         addTypedefToAST(cl.name, cl.name, true);
      else
      {
         ClassDefList defs = null;
         DeclarationInit declStruct = null;

         /*if(!strcmp(cl.name, "BinaryTree"))
            PrintLn("");*/

         if(cl.membersAndProperties.first)
         {
            for(pt = (Property)cl.membersAndProperties.first; pt; pt = pt.next)
            {
               if(!pt.isProperty /*&& pt.*/ && pt.memberAccess == publicAccess && pt.name && pt.dataTypeString &&
                     strcmp(pt.name, "Constructor") && strcmp(pt.name, "Destructor") &&
                     strcmp(pt.name, "function") && strcmp(pt.name, "Initialize") &&
                     strcmp(pt.name, "IsSet") && strcmp(pt.name, "Get") && strcmp(pt.name, "Set") &&
                     strcmp(pt.name, "CompareKey") && strcmp(pt.name, "FreeKey"))
               {
                  ASTClassDef def;
                  if(!declStruct)
                  {
                     defs = { };
                     declStruct =
                     {
                        specifiers = { [
                           SpecClass {
                              type = _struct, id = ASTIdentifier { string = CopyString(cl.name) },
                              definitions = defs
                           }
                        ] }
                     };
                  }
                  //if(!strcmp(cl.name, "BTNode") && !strcmp(pt.name, "parent"))
                  //   PrintLn(":");
                  if(!pt.dataType)
                     pt.dataType = ProcessTypeString(pt.dataTypeString, false);
                  def = getClassDefDeclFromMember(pt);
                  if(def) defs.Add(def);
               }
               else if(pt.name && strcmp(pt.name, "Constructor") && strcmp(pt.name, "Destructor") &&
                     strcmp(pt.name, "function") && strcmp(pt.name, "Initialize") &&
                     strcmp(pt.name, "IsSet") && strcmp(pt.name, "Get") && strcmp(pt.name, "Set") &&
                     strcmp(pt.name, "CompareKey"))
               {
                  PrintLn("SKIPPED MEMBER: ", cl.name, "::", pt.name);
               }
            }
            if(declStruct)
               astH.Add(declStruct);
         }

         if(cl.membersAndProperties.first)
         {
            for(pt = (Property)cl.membersAndProperties.first; pt; pt = pt.next)
            {
               if(pt.memberAccess == publicAccess || (pt.memberAccess == privateAccess && showPrivate))
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

static DeclarationInit getGlobalFuncDeclWhatnotFromFunction(GlobalFunction fn)
{
   DeclarationInit decl = null;
   char * name = getNoNamespaceString(fn.name);
   char * dataTypeString = getNoNamespaceString(fn.dataTypeString);
   char * pointer = getFunctionPointerDeclFromDataTypeString(dataTypeString);
   //char * n, * name = (char*)fn.name, * dataTypeString = (char*)fn.dataTypeString;
   //while((n = strstr(name, "::"))) name = n+2;
   //while((n = strstr(dataTypeString, "::"))) dataTypeString = n+2;
   //OldList ol = (fn.dataType && fn.dataType.params) ? fn.dataType.params : null;
   //int count = ol ? ol.count : -1;
   //PrintLn("FUNCITON: ", dataTypeString/*, " ", fn.name*/, " -- ", fn.dataType ? fn.dataType.name : "", " ");//, count);
   //if(function.dataType.params.first && ((Type)function.dataType.params.first).kind != voidType)
   /*if(!strstr(dataTypeString, "dllexport"))
      PrintLn("");
   if(strstr(name, "eSystem_") == name)
      PrintLn("");*/
   /*if(!strcmp(name, "acos"))
      PrintLn("d");*/
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

static ASTClassDef getClassDefDeclFromMember(Property pt)
{
   ASTClassDef def = null;
   TempFile f { };
   char * n, * dataTypeString = (char*)pt.dataTypeString;
   while((n = strstr(dataTypeString, "::"))) dataTypeString = n+2;

   //if(!strcmp(pt.name, "parent"))
   //   PrintLn(pt.dataType.type);
   //if(!strcmp(dataTypeString, "BinaryTree"))
   //   PrintLn(pt.dataType.type);
   if(pt.dataType.kind == classType)
      f.Print(dataTypeString, " * ", pt.name, ";");
   else
      f.Print(dataTypeString, " ", pt.name, ";");
   initParser(f, null);
   f.Seek(0, start);
   def = ASTClassDef::parse();
   if(!def)
      PrintLn("warning: unable to get ASTClassDef from ASTClassDef::parse(\"", dataTypeString, " ", pt.name, ";", "\")");
   delete f;
   return def;
}

static char * getFunctionPointerDeclFromDataTypeString(const char * str)
{
   uint len = strlen(str);
   char * output = new char[len+16];
   char * o = output;
   const char * i = str;
   char * part = strstr(i, "dllexport ");
   uint t;
   for(t = 0; t <= len; t++)
      output[t] = 0;
   if(part == i)
      i += 10;
   part = strstr(i, "(");
   if(part)
   {
      int n;
      for(n = part - i - 1; n >= 0 && (isalpha(i[n]) || i[n] == '_' || isdigit(i[n]))/*!isspace(i[n])*/; n--)
         ;
      n++;
      strncpy(o, i, n);
      i += n;
      o += n;
      strcpy(o, "(*");
      o += 2;
      n = part - i;
      strncpy(o, i, n);
      i = part;
      o += n;
      strcpy(o, ")");
      o += 1;
      strcpy(o, part);
      o += strlen(part);
   }
   else
      PrintLn("error");
   *o = 0;
   return output;
}

static char * getFuncTypeString(const char * str)
{
   const char * _typed_object_object = "typed_object object";
   const char * _class_class_object_object = "Class class_object, void * object";
   char * out = getNoNamespaceString(str);
   char * next;
   while((next = strstr(out, _typed_object_object)))
   {
      char * tmp = out;
      *next = 0;
      next += strlen(_typed_object_object);
      out = new char[strlen(tmp) + strlen(_class_class_object_object) + strlen(next) + 1];
      *out = 0;
      strcat(out, tmp);
      strcat(out, _class_class_object_object);
      strcat(out, next);
      delete tmp;
   }
   return out;
}

static char * getNoNamespaceString(const char * str)
{
   uint len = strlen(str);
   char * output = new char[len+1];
   char * o = output;
   const char * i = str;
   /*uint t;
   for(t = 0; t <= len; t++)
      output[t] = 0;*/
   while(*i)
   {
      uint kl; // keep length
      uint dl; // discard length
      char * part = strstr(i, "::");
      if(part)
      {
         int n;
         dl = part - i + 2;
         for(n = part - i - 1; n >= 0 && (isalpha(i[n]) || i[n] == '_' || isdigit(i[n]))/*!isspace(i[n])*/; n--)
            ;
         /*{
            PrintLn("");
         }*/
         kl = n + 1;
         for(n = dl; i[n] && (isalpha(i[n]) || i[n] == '_' || isdigit(i[n]) || i[n] == ':'); n++)
         {
            if(i[n] == ':')
            {
               if(i[n+1] == ':' && (isalpha(i[n+2]) || i[n+2] == '_'))
               {
                  n++;
                  dl = n+1;
               }
               else
               {
                  PrintLn("dD");
                  break;
               }
            }
         }
      }
      else
      {
         kl = dl = strlen(i);
      }
      if(kl)
      {
         strncpy(o, i, kl);
         o += kl;
      }
      i += dl;
      if(!part)
         break;
   }
   *o = 0;
   return output;
}

char * getMangledFunctionName(const char * functionName)
{
   int c, len;
   char * name = new char[MAX_FILENAME];
   name[0] = 0;
   strcat(name, ecereNameSpace);
   strcat(name, functionName);
   len = strlen(name);
   for(c = strlen(ecereNameSpace); c < len; c++)
   {
      if(name[c] == ':') name[c] = '_';
   }
   return name;
}

void writeHardCodedEcereComHeader(File f)
{
   f.PrintLn("/****************************************************************************");
   f.PrintLn("===========================================================================");
   f.PrintLn("   Core eC Library");
   f.PrintLn("===========================================================================");
   f.PrintLn("****************************************************************************/");
   f.PrintLn("");
   f.PrintLn("#if !defined(__EC_H__)");
   f.PrintLn("#define __EC_H__");
   f.PrintLn("");
   f.PrintLn("#define CPP11 (defined(__cplusplus) && __cplusplus >= 201103L)");
   f.PrintLn("");
   f.PrintLn("#ifdef __cplusplus");
   f.PrintLn("extern \"C\"");
   f.PrintLn("{");
   f.PrintLn("#endif");
   f.PrintLn("");
   f.PrintLn("#include <stdint.h>");
   f.PrintLn("#include <stdio.h>");
   f.PrintLn("#include <string.h>");
   f.PrintLn("");
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
   f.PrintLn("");
}

/*void writeHardCodedEcereComFooter(File f)
{
}*/

class Binder : Application
{
   bool Init()
   {
      astC = null;
      //Platform os = __runtimePlatform;
      SetGlobalContext(globalContext);
      SetExcludedSymbols(&excludedSymbols);
      SetDefines(&::defines);
      SetImports(&imports);
      SetInDocumentor(true);
      SetGlobalData(globalData);
      return true;
   }

   void Main()
   {
      //if(argc > 1)
      if(Init())
      {
         fH = FileOpen("eC.h", write);
         fC = FileOpen("eC.c", write);
         if(fH && fC)
         {
            openModule("ecereCOM");

            PrintLn("and it starts...");

            astH = { };
            astC = { };
            writeHardCodedEcereComHeader(fH);

               PrintLn("\n// Classes\n");
            fH.PrintLn("\n// Classes\n");
            fH.PrintLn("// unionClass");
            walkModule(componentsApp, false, unionClass, classNameDef, true);
            fH.PrintLn("// systemClass");
            walkModule(componentsApp, false, systemClass, classNameDef, true);
            fH.PrintLn("// bitClass");
            walkModule(componentsApp, false, bitClass, classNameDef, true);
            fH.PrintLn("// unitClass");
            walkModule(componentsApp, false, unitClass, classNameDef, true);
            fH.PrintLn("// enumClass");
            walkModule(componentsApp, false, enumClass, classNameDef, true);
            fH.PrintLn("// structClass");
            walkModule(componentsApp, false, structClass, classNameDef, true);
            fH.PrintLn("// noHeadClass");
            walkModule(componentsApp, false, noHeadClass, classNameDef, true);
            fH.PrintLn("// normalClass");
            walkModule(componentsApp, false, normalClass, classNameDef, true);
            fH.PrintLn("");

               PrintLn("\n// Defines\n");
            fH.PrintLn("\n// Defines\n");
            walkModule(componentsApp, false, defines, normal, true);
            fH.PrintLn("");

               PrintLn("\n// C Functions\n");
            fH.PrintLn("\n// C Functions\n");
            walkModule(componentsApp, false, functions, easyFuncName, true);
            fH.PrintLn("");

               PrintLn("\n// Virtual Method Calls\n");
            fH.PrintLn("\n// Virtual Method Calls\n");
            fH.PrintLn("// Base Class");
            fH.PrintLn("#define _onDisplay(c, i, s, x, y, w, d, a, f) ({ void (* method)(eC_Class *, void *, eC_Instance /*Surface*/, int, int, int, void *, Alignment, DataDisplayFlags) = (void (*)(eC_Class *, void *, eC_Instance /*eC_Surface*/, int, int, int, void *, Alignment, DataDisplayFlags))((c) ? (c)->_vTbl : class_class->_vTbl)[onDisplay_vTblID]; if(method) method((c), i, s, x, y, w, d, a, f); })");
            fH.PrintLn("#define _onCompare(c, i, o)                   ({ int (* method)(eC_Class *, void *, void *) = (int (*)(eC_Class *, void *, void *))((c) ? (c)->_vTbl : class_class->_vTbl)[onCompare_vTblID]; method ? method((c), i, o) : 1; })");
            fH.PrintLn("#define _onCopy(c, i, o)                      ({ void (* method)(eC_Class *, void *, void *) = (void (*)(eC_Class *, void *, void *))((c) ? (c)->_vTbl : class_class->_vTbl)[onCopy_vTblID]; if(method) method((c), i, o); })");
            fH.PrintLn("#define _onFree(c, i)                         ({ void (* method)(eC_Class *, void *) = (void (*)(eC_Class *, void *))((c) ? (c)->_vTbl : class_class->_vTbl)[onFree_vTblID]; if(method) method((c), i); })");
            fH.PrintLn("#define _onGetString(c, i, t, d, n)           ({ constString (* method)(eC_Class *, void *, char *, void *, bool *) = (constString (*)(eC_Class *, void *, char *, void *, bool *))((c) ? (c)->_vTbl : class_class->_vTbl)[onGetString_vTblID]; method ? method((c), i, t, d, n) : null; })");
            fH.PrintLn("#define _onGetDataFromString(c, i, s)         ({ bool (* method)(eC_Class *, void *, constString) = (bool (*)(eC_Class *, void *, constString))((c) ? (c)->_vTbl : class_class->_vTbl)[onGetDataFromString_vTblID]; method ? method((c), i, s) : 1; })");
            fH.PrintLn("#define _onEdit(c, i, b, o, x, y, w, h, u)    ({ eC_Window (* method)(eC_Class *, void *, eC_DataBox, eC_DataBox, int, int, int, int, void *) = (eC_Window (*)(eC_Class *, void *, eC_DataBox, eC_DataBox, int, int, int, int, void *))((c) ? (c)->_vTbl : class_class->_vTbl)[onEdit_vTblID]; method ? method((c), i, b, i, x, y, w, h, u) : null; })");
            fH.PrintLn("#define _onSerialize(c, i, s)                 ({ void (* method)(eC_Class *, void *, eC_IOChannel) = (void (*)(eC_Class *, void *, eC_IOChannel))((c) ? (c)->_vTbl : class_class->_vTbl)[onSerialize_vTblID]; if(method) method((c), i, s); })");
            fH.PrintLn("#define _onUnserialize(c, i, s)               ({ void (* method)(eC_Class *, void *, eC_IOChannel) = (void (*)(eC_Class *, void *, eC_IOChannel))((c) ? (c)->_vTbl : class_class->_vTbl)[onUnserialize_vTblID]; if(method) method((c), i, s); })");
            fH.PrintLn("#define _onSaveEdit(c, i, w, o)               ({ bool (* method)(eC_Class *, void *, eC_Window, void *) = (bool (*)(eC_Class *, void *, eC_Window, void *))((c) ? (c)->_vTbl : class_class->_vTbl)[onSaveEdit_vTblID]; method ? method((c), i, w, o) : 1; })");
            walkModule(componentsApp, false, virtualMethods, virtualMethodDefs, true);
            fH.PrintLn("");

               PrintLn("\n// Types\n");
            fH.PrintLn("\n// Types\n");
            //walkModule(componentsApp, false, typedefs, normal, true);
            walkModule(componentsApp, false, all, normal, true);
            initParser(null, fH);
            astH.topoSort();
            astH.print();
            fH.PrintLn("");

               PrintLn("\n// Imports\n");
            fH.PrintLn("\n// Imports\n");
            walkModule(componentsApp, false, functions, funcImport, true);
            fH.PrintLn("");

               PrintLn("\n// Global Functions\n");
            fH.PrintLn("\n// Global Functions\n");
            walkModule(componentsApp, false, functions, globalFunc, true);
            fH.PrintLn("");

               PrintLn("\n// Classes Import\n");
            fH.PrintLn("\n// Classes Import\n");
            walkModule(componentsApp, false, allClasses, classImport, true);
            fH.PrintLn("");

               PrintLn("\n// Virtual Method Ids Import\n");
            fH.PrintLn("\n// Virtual Method Ids Import\n");
            walkModule(componentsApp, false, virtualMethods, virtualMethodIds, true);
            fH.PrintLn("");

               PrintLn(" ...towards the end");

            //fH.PrintLn("");
            //writeHardCodedEcereComFooter(fH);
            fH.PrintLn("");
            fH.PrintLn("#ifdef __cplusplus");
            fH.PrintLn("");
            fH.PrintLn("// unionClass");
            walkModule(componentsApp, false, unionClass, classNameUndef, true);
            fH.PrintLn("// systemClass");
            walkModule(componentsApp, false, systemClass, classNameUndef, true);
            fH.PrintLn("// bitClass");
            walkModule(componentsApp, false, bitClass, classNameUndef, true);
            fH.PrintLn("// unitClass");
            walkModule(componentsApp, false, unitClass, classNameUndef, true);
            fH.PrintLn("// enumClass");
            walkModule(componentsApp, false, enumClass, classNameUndef, true);
            fH.PrintLn("// structClass");
            walkModule(componentsApp, false, structClass, classNameUndef, true);
            fH.PrintLn("// noHeadClass");
            walkModule(componentsApp, false, noHeadClass, classNameUndef, true);
            fH.PrintLn("// normalClass");
            walkModule(componentsApp, false, normalClass, classNameUndef, true);
            fH.PrintLn("");
            fH.PrintLn("};");
            fH.PrintLn("");
            fH.PrintLn("#endif");
            fH.PrintLn("");
            fH.PrintLn("#endif");


            fC.PrintLn("#include \"eC.h\"");
            fC.PrintLn("");
            walkModule(componentsApp, false, functions, globalFunc, false);

            //PrintLn("listEnumDataTypes:");
            //for(s : listEnumDataTypes)
            //   PrintLn("  " , s);

            initParser(null, fC);
            astC.topoSort();
            astC.print();

            delete fH;
            delete fC;

            PrintLn("end of bindings generation!");
         }
      }
      Terminate();
      system("pause");
   }

   void Terminate()
   {
      delete astH;
      delete astC;

      FreeContext(globalContext);
      FreeExcludedSymbols(excludedSymbols);
      ::defines.Free(FreeModuleDefine);
      imports.Free(FreeModuleImport);
      FreeGlobalData(globalData);
      FreeTypeData(componentsApp);
      FreeIncludeFiles();
      delete componentsApp;
   }
}
