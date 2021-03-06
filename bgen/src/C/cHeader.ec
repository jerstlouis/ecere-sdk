import "genC"

void cHeader(AST out, CGen g)
{
   cInHeaderFileComment(out, g);
   cInHeaderProcessSourceFile(out, g, null, ":src/C/c_header_open.src"); //cInHeaderPreprocessorOpen(out, g);
   cInHeaderIncludes(out, g);

   if(g.lib.ecereCOM)
   {
      cInHeaderEcereComRuntimeFunctions(out, g);
      cInHeaderProcessSourceFile(out, g, "binding macros", ":src/C/c_header_ec_macros.src"); //cInHeaderEcereComBindingMacros(out, g);
      //cInHeaderEcereComRuntimeMacros(out, g);
   }
   else if(g.lib.ecere)
      cInHeaderEcereRuntimeMacros(out, g);
   else if(g.lib.eda)
      cInHeaderEDARuntimeMacros(out, g);

   // get rid of hardcoded things
   // todo toposort / namespace order / nice usable bindings

   //if(g.lib.ecereCOM) {
      //cInHeaderEcereBleedsIntoComHARDCODED(out, g);
      //cInHeaderTemplateParametersHARDCODED(out, g); }
   if(g.lib.ecereCOM)
      cInHeaderProcessSourceFile(out, g, "HARDCODED", ":src/C/c_header_ec_hardcoded.src");

   cInHeaderTypes(out, g);
   if(g.lib.ecereCOM)
      cInHeaderProcessSourceFile(out, g, "HARDCODED", ":src/C/c_header_ec_hardcoded_after.src");

   cInHeaderDynamicLinkFunctionImports(out, g);
   if(g.lib.ecereCOM)
      cInHeaderThisModule(out, g);
   cInHeaderLibraryInitPrototype(out, g); // needed? here?
   cInHeaderProcessSourceFile(out, g, null, ":src/C/c_header_close.src"); //cInHeaderPreprocessorClose(out, g);
}

static void cInHeaderTypes(AST out, CGen g)
{
   AVLTree<UIntPtr> nodes { };
   for(nn : g.bmod.orderedNamespaces)
   {
      BNamespace n = nn;
      for(a : n.output)
         out.Add(a);
      if(n.orderedBackwardsOutputs.count)
      {
         out.Add(ASTRawString { string = CopyString("// start -- moved backwards outputs") });
         for(optr : n.orderedBackwardsOutputs)
         {
            BOutput o = (BOutput)optr;
            for(node : o.output)
            {
               if(!nodes.Find((UIntPtr)node)) // damn it! why is this needed? :S
               {
                  nodes.Add((UIntPtr)node);
                  out.Add(node);
               }
            }
         }
         out.Add(ASTRawString { string = CopyString("// end -- moved backwards outputs") });
      }
      for(optr : n.orderedOutputs)
      {
         BOutput o = (BOutput)optr;
         //o.print();
         if(o.kind == vmanual || o.kind == vdefine || o.kind == vfunction ||
               o.kind == vclass || o.kind == vtemplaton || o.kind == vmethod || o.kind == vproperty)
         {
            for(node : o.output)
            {
               if(!nodes.Find((UIntPtr)node)) // damn it! why is this needed? :S
               {
                  nodes.Add((UIntPtr)node);
                  out.Add(node);
               }
            }
         }
         else check();
      }
   }
   delete nodes;
   for(nn : g.bmod.orderedNamespaces)
   {
      BNamespace n = nn;
      for(vv : n.contents)
      {
         BVariant v = vv;
         if(v.kind == vclass && v.c.outClassPointer)
            out.Add(v.c.outClassPointer.output.firstIterator.data);
      }
   }
}

static void cInHeaderProcessSourceFile(AST out, Gen g, const char * comment, const char * pathToFile)
{
   ASTRawString raw { }; DynamicString z { };
   if(comment)
      bigCommentSection(z, comment);
   sourceFileProcessToDynamicString(z, pathToFile, g.sourceProcessorVars);
   raw.string = CopyString(z.array); delete z;
   out.Add(raw);
}

static void cInHeaderFileComment(AST out, Gen g)
{
   ASTRawString raw { }; DynamicString z { };
   if(g.lib.ecereCOM)
      bigCommentLibrary(z, "Core eC Library");
   else
      bigCommentLibrary(z, (s = PrintString(g.lib.moduleName, " Module"))), delete s;
   raw.string = CopyString(z.array); delete z;
   s = g.lib.ecereCOM ? CopyString("//// Core eC Library") : PrintString("//// ", g.lib.moduleName, " Module");
   out.Add(raw);
}

static void cInHeaderIncludes(AST out, Gen g)
{
   ASTRawString raw { }; DynamicString z { };
   bigCommentSection(z, "includes");
   if(g.lib.ecereCOM)
   {
      z.printxln("#include <stdint.h>");
      z.printxln("#include <stdio.h>");
      z.printxln("#include <string.h>");
   }
   else // todo? dependency iterating? fix these hardcoded includes!?
   {
      if(g.lib.ecere)
         z.printxln("#include \"eC.h\"");
      else if(!strcmp(g.lib.moduleName, "EDA"))
      {
         z.printxln("#include \"ecere.h\"");
         z.printxln("#include \"ffi.h\"");
      }
      else if(!strcmp(g.lib.moduleName, "EDASQLite"))
      {
         z.printxln("#include \"ecere.h\"");
         z.printxln("#include \"EDA.h\"");
         z.printxln("#include \"ffi.h\"");
      }
      else if(!strcmp(g.lib.moduleName, "gnosis2"))
      {
         z.printxln("#include \"ecere.h\"");
         z.printxln("#include \"EDA.h\"");
         z.printxln("#include \"EDASQLite.h\"");
      }
      else
         z.printxln("#include \"ecere.h\"");
   }
   raw.string = CopyString(z.array); delete z;
   out.Add(raw);
}

static void cInHeaderEcereComRuntimeFunctions(AST out, Gen g)
{
   ASTRawString raw { }; DynamicString z { };
   IterNamespace ns { module = g.mod };
   bigCommentSection(z, "functions");
   while(ns.next())
   {
      GlobalFunction fn; IterFunction func { ns.ns };
      while((fn = func.next()))
      {
         BFunction f = fn;
         if(f.isDllExport/* && !skipFunctionTree.Find(fname)*/)
         {
            if(f.easy)
               z.printxln("#define ", f.easy, spaces(cw, strlen(f.easy)), " ", f.gname);
            else
            {
               strcpySubstring(f.fname, "eSystem", "eC");
               {
                  //if(module is ecere/ecereCOM)
                  char * s = strstr(f.fname, "_");
                  if(s && *(++s))
                     *s = (char)tolower(*s);
                  //endif
                  s = f.fname;
                  if(*f.fname == 'e'/* && module is ecere/ecereCOM*/)
                  {
                     if(
                           strstr(f.fname, "eInstance_") == f.fname ||
                           strstr(f.fname, "eClass_") == f.fname ||
                           strstr(f.fname, "eModule_") == f.fname ||
                           strstr(f.fname, "eEnum_") == f.fname ||
                           strstr(f.fname, "eMember_") == f.fname ||
                           strstr(f.fname, "eProperty_") == f.fname
                     )
                        s++;
                     else if(strstr(f.fname, "eC_") == f.fname)
                        ;
                     else check();
                  }
                  else/* if(module is ecere/ecereCOM)*/
                     *s = (char)tolower(*s);
                  z.printxln("#define ", s, spaces(cw, strlen(s)), " ", f.gname);
               }
            }
         }
      }
   }
   ns.cleanup();
   raw.string = CopyString(z.array); delete z;
   out.Add(raw);
}

static void cInHeaderEcereRuntimeMacros(AST out, Gen g)
{
   ASTRawString raw { }; DynamicString z { };
   z.printxln("#define ", g.lib.defineName, "_APP_INTRO(c) \\");
   z.printxln("      APP_INTRO(true) \\");
   z.printxln("      ", g.lib.moduleName, "_init(app); \\");
   z.printxln("      loadTranslatedStrings(null, MODULE_NAME); \\");
   z.printxln("      Instance_evolve(&app, class_ ## c);");
   z.printxln("");
   z.printxln("#define ", g.lib.defineName, "_APP_OUTRO \\");
   z.printxln("      unloadTranslatedStrings(MODULE_NAME); \\");
   z.printxln("      APP_OUTRO");
   z.printxln("");
   z.printxln("#define GUIAPP_INTRO ", g.lib.defineName, "_APP_INTRO(GuiApplication)");
   raw.string = CopyString(z.array); delete z;
   out.Add(raw);
}

static void cInHeaderEDARuntimeMacros(AST out, Gen g)
{
   ASTRawString raw { }; DynamicString z { };
   z.printxln("#define EDA_APP_INTRO(c) \\");
   z.printxln("      APP_INTRO(true) \\");
   z.printxln("      ecere_init(app); \\");
   z.printxln("      EDA_init(app); \\");
   z.printxln("      loadTranslatedStrings(null, MODULE_NAME); \\");
   z.printxln("      Instance_evolve(&app, class_ ## c);");
   z.printxln("");
   z.printxln("#define EDA_GUIAPP_INTRO EDA_APP_INTRO(GuiApplication)");
   raw.string = CopyString(z.array); delete z;
   out.Add(raw);
}

static void cInHeaderLibraryInitPrototype(AST out, Gen g)
{
   ASTRawString raw { }; DynamicString z { };
   if(g.lib.ecereCOM)
      z.printxln("C(Application) ", g.lib.bindingName, "_init(C(Module) fromModule, bool loadEcere, bool guiApp, int argc, char * argv[]);");
   else
      z.printxln("C(Module) ", g.lib.bindingName, "_init(C(Module) fromModule);");
   raw.string = CopyString(z.array); delete z;
   out.Add(raw);
}

static void cInHeaderDynamicLinkFunctionImports(AST out, Gen g)
{
   ASTRawString raw { }; DynamicString z { };
   bool prefixed = false;
   IterNamespace ns { module = g.mod };
   while(ns.next())
   {
      GlobalFunction fn; IterFunction func { ns.ns };
      while((fn = func.next()))
      {
         BFunction f = fn;
         if(!prefixed && f.isDllExport)
         {
            z.printxln("");
            bigCommentSection(z, "dll function imports");
            z.printxln("");
            prefixed = true;
         }
         if(f.isDllExport)
         {
            ASTNode node = astFunction(f.gname, { type = fn.dataType, fn = fn }, { _extern = true, _dllimport = true }, null);
            ec2PrintToDynamicString(z, node, true);
         }
      }
   }
   ns.cleanup();
   raw.string = CopyString(z.array); delete z;
   out.Add(raw);
}

static void cInHeaderThisModule(AST out, Gen g)
{
   ASTRawString raw { }; DynamicString z { };
   z.printxln("extern C(Module) __thisModule;");
   raw.string = CopyString(z.array); delete z;
   out.Add(raw);
}
