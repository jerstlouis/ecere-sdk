import "bgen"
import "cgenc"
import "cgenh"

class CBindingsGenerator : BindingsGenerator
{
   char cFileName[MAX_LOCATION];
   char hFileName[MAX_LOCATION];

   AST astH;
   AST astC;

   void generate()
   {
      File f;
      f = FileOpen(hFileName, write);
      if(f)
      {
         writeHardCodedHeader(f, this);
/*
         Module mod = homeModule; //componentsApp;
         fC.PrintLn("#include \"", bindingName, ".h\"");
         fC.PrintLn("");

            PrintLn(" *** Classes");
         fH.PrintLn("\n// Classes\n");
         //walkModule(mod, false, allClasses, classNameDef, true);
         fH.PrintLn("");

            PrintLn(" *** Defines");
         fH.PrintLn("\n// Defines\n");
         //walkModule(mod, false, defines, normal, true);
         fH.PrintLn("");

            PrintLn(" *** C Functions");
         fH.PrintLn("\n// C Functions\n");
         //walkModule(mod, false, functions, easyFuncName, true);
         fH.PrintLn("");

            PrintLn(" *** Virtual Methods Imports");
         fH.PrintLn("\n// Virtual Methods Imports\n");
         //walkModule(mod, false, virtualMethods, virtualMethodImport, true);
         fC.PrintLn("");
         fH.PrintLn("");

            PrintLn(" *** Properties Imports");
         fH.PrintLn("\n// Properties Imports\n");
         //walkModule(mod, false, properties, propertyImport, true);
         fC.PrintLn("");
         fH.PrintLn("");

            PrintLn(" *** Virtual Method Calls");
         fH.PrintLn("\n// Virtual Method Calls\n");
         //walkModule(mod, false, virtualMethods, virtualMethodDefs, true);
         fH.PrintLn("");

            PrintLn(" *** Types");
         fH.PrintLn("\n// Types\n");
         //walkModule(mod, false, typedefs, normal, true);
         //walkModule(mod, false, all, normal, true);
         initParser(null, fH);
         astH.topoSort();
         fH.PrintLn("");
         astH.print();
         fH.PrintLn("");

            PrintLn(" *** Imports");
         fH.PrintLn("\n// Imports\n");
         //walkModule(mod, false, functions, funcImport, true);
         fH.PrintLn("");

            PrintLn(" *** Global Functions");
         fH.PrintLn("\n// Global Functions\n");
         //walkModule(mod, false, functions, globalFunc, true);
         fH.PrintLn("");

            PrintLn(" *** Classes");
         fC.PrintLn("\n// Classes\n");
         fH.PrintLn("\n// Classes Import\n");
         //walkModule(mod, false, allClasses, classImport, true);
         fC.PrintLn("");
         fH.PrintLn("");

            PrintLn(" *** Virtual Method IDs");
         fC.PrintLn("\n// Virtual Method IDs\n");
         fH.PrintLn("\n// Virtual Method IDs Import\n");
         //walkModule(mod, false, virtualMethods, virtualMethodIDs, true);
         fC.PrintLn("");
         fH.PrintLn("");

         //fH.PrintLn("");
         //writeHardCodedEcereComFooter(fH);
         fH.PrintLn("");
         fH.PrintLn("#ifdef __cplusplus");
         fH.PrintLn("");
         //walkModule(mod, false, allClasses, classNameUndef, true);
         fH.PrintLn("");
         fH.PrintLn("};");
         fH.PrintLn("");
         fH.PrintLn("#endif");
         fH.PrintLn("");
         fH.PrintLn("#endif");

         //walkModule(mod, false, functions, globalFunc, false);

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
         delete f;
      }
      f = FileOpen(cFileName, write);
      if(f)
      {
/*
         Module mod = homeModule; //componentsApp;
         fC.PrintLn("#include \"", bindingName, ".h\"");
         fC.PrintLn("");

            PrintLn(" *** Classes");
         fH.PrintLn("\n// Classes\n");
         //walkModule(mod, false, allClasses, classNameDef, true);
         fH.PrintLn("");

            PrintLn(" *** Defines");
         fH.PrintLn("\n// Defines\n");
         //walkModule(mod, false, defines, normal, true);
         fH.PrintLn("");

            PrintLn(" *** C Functions");
         fH.PrintLn("\n// C Functions\n");
         //walkModule(mod, false, functions, easyFuncName, true);
         fH.PrintLn("");

            PrintLn(" *** Virtual Methods Imports");
         fH.PrintLn("\n// Virtual Methods Imports\n");
         //walkModule(mod, false, virtualMethods, virtualMethodImport, true);
         fC.PrintLn("");
         fH.PrintLn("");

            PrintLn(" *** Properties Imports");
         fH.PrintLn("\n// Properties Imports\n");
         //walkModule(mod, false, properties, propertyImport, true);
         fC.PrintLn("");
         fH.PrintLn("");

            PrintLn(" *** Virtual Method Calls");
         fH.PrintLn("\n// Virtual Method Calls\n");
         //walkModule(mod, false, virtualMethods, virtualMethodDefs, true);
         fH.PrintLn("");

            PrintLn(" *** Types");
         fH.PrintLn("\n// Types\n");
         //walkModule(mod, false, typedefs, normal, true);
         //walkModule(mod, false, all, normal, true);
         initParser(null, fH);
         astH.topoSort();
         fH.PrintLn("");
         astH.print();
         fH.PrintLn("");

            PrintLn(" *** Imports");
         fH.PrintLn("\n// Imports\n");
         //walkModule(mod, false, functions, funcImport, true);
         fH.PrintLn("");

            PrintLn(" *** Global Functions");
         fH.PrintLn("\n// Global Functions\n");
         //walkModule(mod, false, functions, globalFunc, true);
         fH.PrintLn("");

            PrintLn(" *** Classes");
         fC.PrintLn("\n// Classes\n");
         fH.PrintLn("\n// Classes Import\n");
         //walkModule(mod, false, allClasses, classImport, true);
         fC.PrintLn("");
         fH.PrintLn("");

            PrintLn(" *** Virtual Method IDs");
         fC.PrintLn("\n// Virtual Method IDs\n");
         fH.PrintLn("\n// Virtual Method IDs Import\n");
         //walkModule(mod, false, virtualMethods, virtualMethodIDs, true);
         fC.PrintLn("");
         fH.PrintLn("");

         //fH.PrintLn("");
         //writeHardCodedEcereComFooter(fH);
         fH.PrintLn("");
         fH.PrintLn("#ifdef __cplusplus");
         fH.PrintLn("");
         //walkModule(mod, false, allClasses, classNameUndef, true);
         fH.PrintLn("");
         fH.PrintLn("};");
         fH.PrintLn("");
         fH.PrintLn("#endif");
         fH.PrintLn("");
         fH.PrintLn("#endif");

         //walkModule(mod, false, functions, globalFunc, false);

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
         delete f;
      }
   }

   bool init()
   {
      char path[MAX_LOCATION];
      strcpy(path, "generated");
      if(!FileExists(path))
         MakeDir(path);
      if(FileExists(path))
      {
         strcat(path, "/new");
         if(!FileExists(path))
            MakeDir(path);
         if(FileExists(path))
         {
            strcat(path, "/");
            strcat(path, bindingName);
            ChangeExtension(path, "c", path);
            strcpy(cFileName, path);
            ChangeExtension(path, "h", path);
            strcpy(hFileName, path);

            if(FileExists(cFileName))
               DeleteFile(cFileName);
            if(FileExists(hFileName))
               DeleteFile(hFileName);

            if(!FileExists(cFileName) && !FileExists(hFileName))
            {
               astC = { };
               astH = { };
               //Platform os = __runtimePlatform;
               ec1init();
            }
            return true;
         }
      }
      return false;
   }

   void reset()
   {
      delete astC;
      delete astH;
      ec1terminate();
   }
}
