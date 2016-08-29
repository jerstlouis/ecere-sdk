import "bgen"
import "cgenc"
import "cgenh"

class CBindingsGenerator : BindingsGenerator
{
   char cFileName[MAX_LOCATION];
   char hFileName[MAX_LOCATION];

   AST ast_H;
   AST ast_C;

   void generate()
   {
      File f;
      Module m = homeModule; //componentsApp;
      f = FileOpen(hFileName, write);
      if(f)
      {
         generateH(f, this, m);
         delete f;
      }
      f = FileOpen(cFileName, write);
      if(f)
      {
         generateC(f, this, m);
         delete f;
      }
   }

   bool init()
   {
      char path[MAX_LOCATION];
      if(readyGeneratedDir(path, false))
      {
         PathCatSlash(path, bindingName);
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
            ast_C = { };
            ast_H = { };
            //Platform os = __runtimePlatform;
            ec1init(moduleName);
         }
         return true;
      }
      return false;
   }

   void reset()
   {
      if(ast_C) ast_C.Free();
      delete ast_C;
      if(ast_H) ast_H.Free();
      delete ast_H;
      ec1terminate();
   }
}

class WalkerGenerator : eC_RTTI_Walker
{
   File f;
   bool classClass;
   bool haveContent;

   AST ast;
   ClassDefList defs;
   DeclarationInit declStruct;
}

void cgenPrintVirtualMethodDefs(File f, Class cl, Method md, const char * mname, bool classClass, bool assumeTypedObject, bool forInstance)
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
      f.Print("#define Instance_", mname, "(c, i");
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
      f.Print("#define ", classClass ? "" : cl.name, "_", mname, "(");
      if(thisClassName)
         f.Print("i");
      else if(assumeTypedObject)
         f.Print("c, i");
   }
   for(ap = 0, param = md.dataType.params.first; param; param = param.next)
   {
      //if(!param.type || (param.type.kind == voidType && !param.name))
      //   PrintLn("he"); param.
      //if(!param.type || (param.type.kind == voidType && !param.name)) continue;
      if(param.kind == voidType && !param.name) continue;
      if(prev || param.prev) f.Print(", ");
      if(param.name)
      {
         f.Print(param.name);
         charCount += strlen(param.name);
      }
      else
      {
         f.Print("ap", ++ap);
         charCount += 2 + floor(log10(ap)) + 1;
      }
   }
   if(forInstance)
   {
      f.Print(")", spaces(64, charCount), "_", mname, "((i) ? (i)->_class : c, i");
   }
   else
   {
      f.Print(") ");
      f.Print(spaces(64, charCount), "({ void (* method)(");
      cgenPrintParamsType(f, thisClassName, assumeTypedObject, md.dataType.params);
      f.Print(") = (void (*)(");
      cgenPrintParamsType(f, thisClassName, assumeTypedObject, md.dataType.params);
      f.Print("))");
      if(thisClassName)
         f.Print("(i ? i->_vTbl : class_", thisClassName, "->_vTbl)");
      else if(assumeTypedObject)
         f.Print("((c) ? (c)->_vTbl : class_", cl.name, "->_vTbl)");
      else
         f.Print("(class_", cl.name, "->_vTbl)");
      f.Print("[", assumeTypedObject ? "" : cl.name, assumeTypedObject ? "" : "_", mname, "_vTblID]; ");
      f.Print("if(method) ", md.dataType.returnType.kind == voidType ? "" : "return ", "method(");
      if(thisClassName)
         f.Print("i");
      else if(assumeTypedObject)
         f.Print("(c), i");
   }
   for(ap = 0, param = md.dataType.params.first; param; param = param.next)
   {
      if(param.kind == voidType && !param.name) continue;
      f.Print((prev || param.prev) ? ", " : "");
      if(param.name)
         f.Print(param.name);
      else
         f.Print("ap", ++ap);
   }
   if(forInstance)
      f.PrintLn(")");
   else
      f.PrintLn("); })");
}

void cgenPrintParamsType(File f, const char * thisClassName, bool assumeTypedObject, OldList params)
{
   Type param;
   bool prev = thisClassName || assumeTypedObject;
   if(thisClassName)
      f.Print("eC_", thisClassName);
   else if(assumeTypedObject)
      f.Print("eC_Class *, void *");
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
      f.Print((prev || param.prev) ? ", " : "", prefix ? "eC_" : "", typeString);
   }
}
