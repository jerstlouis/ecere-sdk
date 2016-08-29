import "cgen"

void generateC(File f, CBindingsGenerator g, Module m)
{
   WalkerGenerator w;

   f.PrintLn("#include \"", bindingName, ".h\"");
   f.PrintLn("");

   PrintLn(" *** Virtual Methods");
   f.PrintLn("\n// Virtual Methods\n");
   w = { inSubNamespaces = true, inClasses = true, inMethods = true, f = f; // virtualMethods, virtualMethodImport
      void onMethod(Method md, Class cl, NameSpace space, const char * name, Module module)
      {
#if 0  // if(!cl.templateClass) skipped stuff: all container methods for
extern Method * method_Container<BT, I = KT>_*
extern Method * method_Container<LT>_*
extern Method * method_Container<T>_*
#endif
         if(!cl.templateClass)
         if(md.memberAccess == publicAccess/* || (md.memberAccess == privateAccess && showPrivate)*/ && md.type == virtualMethod)
         {
            char * mname = copyCamelCaseString(md.name);
            if(!md.dataType) ProcessMethodType(md);
            f.PrintLn("Method * method_", cl.name, "_", mname, ";");
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

   PrintLn(" *** Properties");
   f.PrintLn("\n// Properties\n");
   w = { inSubNamespaces = true, inClasses = true, inMembers = true, f = f; // properties, propertyImport
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
            f.PrintLn("Property * property_", cl.name, "_", pt.name, ";");
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
               f.PrintLn(       "void (* ", cl.name, "_set_", pt.name, ")(", cl.name, " ", pname, ", ", typeString, ptr ? " *" : "", " v);");
            if(pt.Get)
            {
               if(structValue)
                  f.PrintLn(       "void (* ", cl.name, "_get_", pt.name, ")(", cl.name, " ", pname, ", ", typeString, ptr ? " *" : "", " v);");
               else
                  f.PrintLn(           typeString, " (* ", cl.name, "_get_", pt.name, ")(", cl.name, " ", pname, ");");
            }
            if(pt.IsSet)
               f.PrintLn(       "bool (* ", cl.name, "_isSet_", pt.name, ")(", cl.name, " ", pname, ");");
            f.PrintLn("");
            delete pname;
         }
      }
   };
   w.walk(m, false); delete w;
   f.PrintLn("");

/*
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
*/

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
                  f.PrintLn(dataTypeString, " (*", fname, ")(", params, ";");
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
   f.PrintLn("\n// Classes\n");
   w = { inSubNamespaces = true, inClasses = true, f = f; // allClasses, classImport
      void onClass(Class cl, NameSpace space, const char * name, Module module)
      {
         bool skip = !strcmp(cl.name, "unsigned int");
         f.PrintLn(skip ? "// SKIPPED // " : "", "Class * class_", cl.name, ";");
      }
   };
   w.walk(m, false); delete w;
   f.PrintLn("");

   PrintLn(" *** Virtual Method IDs");
   f.PrintLn("\n// Virtual Method IDs\n");
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
            f.PrintLn("int ", classClass ? "" : cl.name, classClass ? "" : "_", mname, "_vTblID;");
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
*/

   initParser(null, f);
   g.ast_C.topoSort();
   f.PrintLn("");
   g.ast_C.print();
   f.PrintLn("");

   f.PrintLn("Application ", bindingName, "_init(bool guiApp, int argc, char * argv[])");
   f.PrintLn("{");
   f.PrintLn("   Application app = eC_initApp(guiApp, argc, argv);");
   f.PrintLn("   if(app)");
   f.PrintLn("   {");
   f.PrintLn("      Module module = Module_load(app, \"", homeModule.name, "\", publicAccess);");
   f.PrintLn("      app->_refCount++;");
   f.PrintLn("      if(module)");
   f.PrintLn("      {");
   f.PrintLn("         // Set up all the class_*, property, method, ...");
   f.PrintLn("");
   w = { inSubNamespaces = true, inClasses = true, f = f; // allClasses, dynamicBinding
   };
   w.walk(m, false); delete w;
   f.PrintLn("         // Set up all the function pointers, ...");
   f.PrintLn("");
   w = { inSubNamespaces = true, inClasses = true, f = f; // functions, dynamicBinding
   };
   w.walk(m, false); delete w;
   f.PrintLn("      }");
   f.PrintLn("   }");
   f.PrintLn("   return app;");
   f.PrintLn("}");
   f.PrintLn("");
   f.PrintLn("Module __thisModule;");
}
