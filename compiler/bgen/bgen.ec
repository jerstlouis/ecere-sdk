import "ecere"
import "ecwalker"
import "cgen"
import "cppgen"
import "ec2"
import "oldgen"

ConsoleFile console { };

//define app = (Application)__thisModule.application;

class BindingsGenerator
{
public:
   const char * bindingName;
   const char * moduleName;
   const char * defineName;
   bool ecereCOM;
   virtual bool init();
   virtual void generate();
   virtual void reset();
   ~BindingsGenerator()
   {
      reset();
   }
}

#define _NEW_BGEN

class BGen : Application
{
   void Main()
   {
      //if(argc > 1)
      //if(Init())
      {
         if(prepForBindingsGeneration("eC"))
         {
            openModule("ecereCOM");
            processModule("ecereCOM", "EC", true);
            terminateBindingsGeneration();
         }
         /*{
            CBindingsGenerator cbgen;
            cbgen = { "eC", "ecereCOM", "EC", true };
            if(cbgen.init())
               cbgen.generate();
            delete cbgen;
         }*/
#if 0 // defined(_NEW_BGEN)
         CBindingsGenerator cbgen;
         cbgen = { "eC", "ecereCOM", "EC", true };
         if(cbgen.init())
            cbgen.generate();
         delete cbgen;
         cbgen = { "ecere", "ecere", "ECERE", false };
         if(cbgen.init())
            cbgen.generate();
         delete cbgen;
         cbgen = { "eda", "EDA", "EDA", false };
         if(cbgen.init())
            cbgen.generate();
         delete cbgen;
//#else
         if(prepForBindingsGeneration("eC"))
         {
            openModule("ecereCOM");
            processModule("ecereCOM", "EC", true);
            terminateBindingsGeneration();
         }
         if(prepForBindingsGeneration("ecere"))
         {
            openModule("ecere");
            processModule("ecere", "ECERE", false);
            terminateBindingsGeneration();
         }
         if(prepForBindingsGeneration("eda"))
         {
            openModule("EDA");
            processModule("EDA", "EDA", false);
            terminateBindingsGeneration();
         }
#if 0
         if(prepForBindingsGeneration("gnosis"))
         {
            openModule("gnosis");
            processModule("gnosis", "GNOSIS", false);
            terminateBindingsGeneration();
         }
#endif
#endif // 0 // defined(_NEW_BGEN)
      }
      system("pause");
   }
}

bool readyGeneratedDir(char * path, bool old)
{
   if(path)
   {
      *path = 0;
      PathCatSlash(path, "generated");
      if(!FileExists(path))
         MakeDir(path);
      if(FileExists(path))
      {
         PathCatSlash(path, old ? "old" : "new");
         if(!FileExists(path))
            MakeDir(path);
         if(FileExists(path))
            return true;
      }
   }
   return false;
}

const char * _spaces = \
      "                                                                " \
      "                                                                " \
      "                                                                " \
      "                                                                " \
      "                                                                " \
      "                                                                " \
      "                                                                " \
      "                                                                ";

const char * spaces(int colSize, int stringSize)
{
   return _spaces + strlen(_spaces) - Min(Max(0, colSize - stringSize), strlen(_spaces));
}

char * copyCamelCaseString(const char * string)
{
   char * s = CopyString(string);
   *s = (char)tolower(*s);
   return s;
}

char * strcpySubstring(char * string, const char * substring, const char * replace)
{
   char * b, * d;
   const char * s, * r;
   //if(strlen(substring) >= strlen(replace)
   b = strstr(string, substring);
   if(b)
   {
      for(s = substring, r = replace, d = b; *b; b++)
      {
         if(*r && *s)
         {
            *d++ = *r;
            s++;
            r++;
         }
         else if(*s)
            s++;
         else
            *d++ = *b;
      }
      *d = 0;
   }
   return string;
}

char * copySpecialSingleCharName(const char * name)
{
   char * s = new char[2];
   *s = (char)tolower(*name);
   if(*s == 'v') *s = 'x';
   s[1] = 0;
   return s;
}

AVLTree<const String> skipTypes { [
   "char",
   "char *",
   "double",
   "float",
   "int",
   "short",
   "unsigned int",
   "enum",
   "struct",
   "cclass"
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

const char * systemTypeSubst(const char * name, const char * dataTypeString)
{
   const char * subst = sysTypeMap[name];
   return subst ? subst : dataTypeString;
}

//Map<String, String> listEnumDataTypes { };

AVLTree<const String> skipFunctionTree { [
   "acos",
   "acosh",
   "asin",
   "asinh",
   "atan",
   "atan2",
   "atanh",
   "atof",
   "atoi",
   "ceil",
   "cos",
   "cosh",
   "exp",
   "fabs",
   "floor",
   "fmod",
   "fputs",
   "getenv",
   "isalnum",
   "isalpha",
   "isblank",
   "isdigit",
   "islower",
   "isprint",
   "isspace",
   "isupper",
   "isxdigit",
   "log",
   "log10",
   "memcmp",
   "memcpy",
   "memmove",
   "memset",
   "pow",
   "printf",
   "puts",
   "qsort",
   "rename",
   "sin",
   "sinh",
 //"sprintf",
   "sprintf",
   "sqrt",
   "strcasecmp",
   "strcat",
   "strchr",
   "strcmp",
   "strcpy",
   "strcspn",
   "strlen",
   "strlwr",
   "strncasecmp",
   "strncat",
   "strncmp",
   "strncpy",
   "strpbrk",
   "strspn",
   "strstr",
   "strtod",
   "strtol",
   "strtoll",
   "strtoul",
   "strtoull",
   "strupr",
   "system",
   "tan",
   "tanh",
   "tolower",
   "toupper",
   "vsnprintf",
   "vsprintf"
] };

bool skipFunction(const char * name, const char * moduleName, NameSpace * ns)
{
   if(!moduleName && skipFunctionTree.Find(name))
      return true;
   if(islower(name[0]) && strstr(name, "eClass") != name && strstr(name, "eSystem") != name && strstr(name, "eEnum") != name &&
          strstr(name, "eInstance") != name && strstr(name, "eMember") != name && strstr(name, "eModule") != name &&
          strstr(name, "eProperty") != name)
      PrintLn("SHOULD WE SKIP FUNCTION: ", name, moduleName ? " from " : "", moduleName ? moduleName : "",
            (ns && ns->name) ? " / " : "", (ns && ns->name) ? ns->name : "");
   return false;
}

char * getFunctionPointerDeclFromDataTypeString(const char * str)
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

char * getFuncTypeString(const char * str)
{
   const char * _typed_object_object = "typed_object object";
   const char * _class_class_object_object = "Class class_object, void * object";
   char * out = getNoNamespaceString(str, null);
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

char * getNoNamespaceString(const char * str, char * buffer)
{
   uint len = strlen(str);
   char * output = buffer ? buffer : new char[len+1];
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

ASTClassDef getClassDefDeclFromMember(Property pt, bool privateData)
{
   ASTClassDef def = null;
   TempFile f { };
   char * n, * dataTypeString = (char*)pt.dataTypeString;
   char string[512], marker, * s, * d;
   while((n = strstr(dataTypeString, "::"))) dataTypeString = n+2;

   if(!strcmp(dataTypeString, "T"))
      PrintLn("stop");
   if(pt.dataType.kind == classType &&
         !(pt.dataType._class.registered && (pt.dataType._class.registered.type == structClass ||
                  pt.dataType._class.registered.type == normalClass || pt.dataType._class.registered.type == enumClass)))
      f.Print(dataTypeString, " * ", pt.name, ";");
   else if(pt.dataType.kind == arrayType)
   {
      marker = '[';
      for(s = dataTypeString, d = &string[0]; *s; s++)
      {
         if(*s == marker)
         {
            *d++ = ' ';
            strcpy(d, pt.name);
            d += strlen(pt.name);
            marker = 0;
         }
         *d++ = *s;
      }
      *d = 0;
      f.Print(string, ";");
   }
   else if(pt.dataType.kind == pointerType && pt.dataType.type.kind == functionType)
   {
      marker = '*';
      for(s = dataTypeString, d = &string[0]; *s; s++)
      {
         *d++ = *s;
         if(*s == marker)
         {
            strcpy(d, pt.name);
            d += strlen(pt.name);
            marker = 0;
         }
      }
      *d = 0;
      f.Print(string, ";");
   }
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
