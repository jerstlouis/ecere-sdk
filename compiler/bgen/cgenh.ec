import "cgen"

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

class WalkerTestH : eC_RTTI_Walker
{

}
