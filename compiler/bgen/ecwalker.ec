import "ecere"
import "ec"

static Context globalContext { };
static OldList defines { };
static OldList imports { };
static NameSpace globalData;
static OldList excludedSymbols { offset = (uint)(uintptr)&((Symbol)0).left };

Application componentsApp;
Module homeModule;

void ec1init()
{
   SetGlobalContext(globalContext);
   SetExcludedSymbols(&excludedSymbols);
   SetDefines(&::defines);
   SetImports(&imports);
   SetInDocumentor(true);
   SetGlobalData(globalData);
}

void ec1terminate()
{
   FreeContext(globalContext);
   FreeExcludedSymbols(excludedSymbols);
   ::defines.Free(FreeModuleDefine);
   imports.Free(FreeModuleImport);
   FreeGlobalData(globalData);
   FreeTypeData(componentsApp);
   FreeIncludeFiles();
   delete componentsApp;
}

void openModule(const char * filePath)
{
   char moduleName[MAX_FILENAME];
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
   if(!strcmp(filePath, "ecereCOM"))
      ImportModule("ecere", normalImport, publicAccess, false);

   if(extension[0] && strcmpi(extension, "so") && strcmpi(extension, "dll") && strcmpi(extension, "dylib"))
      componentsApp.name = CopyString(filePath);

   PrintLn("");
   PrintLn("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
   PrintLn("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
   PrintLn("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||");
   PrintLn("");
   PrintLn("openModule(", filePath, "|", componentsApp.name, ")");
   for(module = componentsApp.allModules.first; module; module = module.next)
   {
      PrintLn("   module(", module.importType, "): ", module.name);
      //if(module.modules.first)
      {
         //Module m = null;
         //for(m = module.modules.first; m; m = m.next)
         {
            // crashing // PrintLn("       submodule(", m.importType, "): ", m.name);
         }
      }
   }
   PrintLn("");
   for(module = componentsApp.allModules.first; module; module = module.next)
   {
      if(module.name && (!strcmp(module.name, "ecere") || !strcmp(module.name, "ecereCOM")))
         break;
   }
   if(!module)
      eModule_LoadStrict(componentsApp, "ecereCOM", publicAccess /*privateAccess*/);

   GetLastDirectory(filePath, moduleName);
   PrintLn("   moduleName: ", moduleName);
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
   PrintLn("   homeModule: ", module.name);

   SetSymbolsDir(null);
}

class eC_RTTI_Walker
{
   bool inSubNamespaces;
   bool inDefines;
   bool inFunctions;
   bool inClasses;
   bool inMethods;
   bool inMembers;
   //bool inProperties;
   bool inConversions;

   virtual void onNamespace(NameSpace space, const char * name, Module module);
   virtual void onDefine(DefinedExpression df, NameSpace space, const char * name, Module module);
   virtual void onFunction(GlobalFunction fn, NameSpace space, const char * name, Module module);
   virtual void onClass(Class cl, NameSpace space, const char * name, Module module);
   virtual void onMethod(Method md, Class cl, NameSpace space, const char * name, Module module);
   virtual void onMember(Property pt, Class cl, NameSpace space, const char * name, Module module);
   //virtual void onProperty(Property pt, Class cl, NameSpace space, const char * name, Module module);
   virtual void onConversion(Property pt, Class cl, NameSpace space, const char * name, Module module);

   // question: should we get rid of isDll here?
   void walk(Module module, bool isDll)
   {
      if(module.name)
      {
         if(!strcmp(module.name, "ecereCOM"))
            walkNamespace(null, module.application.systemNameSpace, "", !isDll);
         else
            walkNamespace(module, module.publicNameSpace, "", !isDll);
      }
   }

   // question: should we get rid of showPrivate here?
   void walkNamespace(Module module, NameSpace space, const char * parentName, bool showPrivate)
   {
      char nname[1024];
      strcpy(nname, parentName ? parentName : "");
      if(space.name)
      {
         if(nname[0])
            strcat(nname, "::");
         strcat(nname, space.name);
      }
      onNamespace(space, nname, module);
      if(inDefines && space.defines.first)
      {
         BTNamedLink link;
         DefinedExpression df;
         for(link = (BTNamedLink)space.defines.first; link; link = (BTNamedLink)((BTNode)link).next)
         {
            df = link.data;
            onDefine(df, space, nname, module);
         }
      }
      if(inFunctions && space.functions.first)
      {
         BTNamedLink link;
         GlobalFunction fn;
         for(link = (BTNamedLink)space.functions.first; link; link = (BTNamedLink)((BTNode)link).next)
         {
            fn = link.data;
            onFunction(fn, space, nname, module);
         }
      }
      if(inClasses && space.classes.first)
      {
         BTNamedLink link;
         Class cl;
         for(link = (BTNamedLink)space.classes.first; link; link = (BTNamedLink)((BTNode)link).next)
         {
            Property pt;
            cl = link.data;
            onClass(cl, space, nname, module);
            if(inMethods && cl.methods.first)
            {
               Method md;
               for(md = (Method)cl.methods.first; md; md = (Method)((BTNode)md).next)
               {
                  onMethod(md, cl, space, nname, module);
               }
            }
            if(inMembers && cl.membersAndProperties.first)
            {
               for(pt = (Property)cl.membersAndProperties.first; pt; pt = pt.next)
               {
                  //if(pt.isProperty) continue;
                  onMember(pt, cl, space, nname, module);
               }
            }
            /*if(inProperties && cl.membersAndProperties.first)
            {
               for(pt = (Property)cl.membersAndProperties.first; pt; pt = pt.next)
               {
                  if(!pt.isProperty) continue;
                  onMember(pt, cl, space, nname, module);
               }
            }*/
            if(inConversions && cl.conversions.first)
            {
               for(pt = cl.conversions.first; pt; pt = pt.next)
               {
                  onConversion(pt, cl, space, nname, module);
               }
            }
         }
      }
      if(inSubNamespaces)
      {
         NameSpace * ns;
         for(ns = (NameSpace *)space.nameSpaces.first; ns; ns = (NameSpace *)((BTNode)ns).next)
         {
            walkNamespace(module, ns, nname, showPrivate);
         }
      }
   }
}
