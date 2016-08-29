import "astNode"
import "classes"

// Specifiers
public class ASTSpecifier : ASTNode
{
public:
};

public class SpecTypeOf : ASTSpecifier
{
public:
   Expression expression;

   ~SpecTypeOf()
   {
      delete expression;
   }
}

public class SpecSubClass : ASTSpecifier
{
public:
   ASTSpecifier _class;

   ~SpecSubClass()
   {
      delete _class;
   }
}

public class SpecTemplateType : ASTSpecifier
{
public:
   TemplateParameter templateParameter;

   ~SpecTemplateType()
   {
      delete templateParameter;
   }
}

public class SpecsList : ASTList<ASTSpecifier>
{
public:
   void printSep()
   {
      out.Print(" ");
   }

   SpecsList ::parse()
   {
      SpecsList specs = null;
      bool gotSpec = false;
      while(true)
      {
         peekToken();
         if(nextToken.type == _struct || nextToken.type == _union || nextToken.type == _class || nextToken.type == _enum)
         {
            ASTSpecifier s = SpecClass::parse();
            if(s)
            {
               if(!specs) specs = { };
               specs.Add(s);
            }
            break;
         }
         else if(nextToken.type.isSpecifier)
         {
            readToken();
            if(!specs) specs = { };
            specs.Add(SpecBase { specifier = token.type });
            if(!token.type.isQualifier && token.type != _typedef)
               gotSpec = true;
         }
         else if(nextToken.type == identifier || nextToken.type == typeName)
         {
            bool isType = false;
            if(isType || !gotSpec)
            {
               readToken();
               if(!specs) specs = { };
               specs.Add(SpecName { name = CopyString(token.text) });
               gotSpec = true;
            }
            else
               break;
         }
         else
            break;
      }
      return specs;
   }
}

public class SpecBase : ASTSpecifier
{
public:
   TokenType2 specifier;

   void print()
   {
      specifier.print();
   }
}

public class SpecName : ASTSpecifier
{
public:
   String name;
   //ExtDecl extDecl;
   //Symbol symbol;
   //List<ClassTemplateArgument> templateArgs;

   void print()
   {
      if(name) out.Print(name);
   }

   ~SpecName()
   {
      delete name;
      // delete extDecl;
      // delete symbol;
      // if(templateArgs) templateArgs.Free();
      // delete templateArgs;
   }
}

public class SpecClass : ASTSpecifier
{
public:
   TokenType2 type;
   ASTIdentifier id;
   SpecsList baseSpecs;
   ClassDefList definitions;

   //ASTSpecifier _class;
   // Symbol symbol;
   //Location blockStart;
   //Location nameLoc;
   //bool deleteWatchable;
   //int endid;
   //AccessMode declMode;
   bool addNameSpace;
   Context ctx;
   // ExtDecl extDeclStruct;

   SpecClass ::parse()
   {
      SpecClass spec = (peekToken().type == _enum) ? SpecEnum { } : SpecClass { };
      spec.type = readToken().type;
      if(peekToken().type == identifier)
         spec.id = ASTIdentifier::parse();
      if(peekToken().type == ':')
      {
         readToken();
         spec.baseSpecs = SpecsList::parse();
      }
      if(peekToken().type == '{')
      {
         readToken();
         spec.definitions = ClassDefList::parse();
         if(!spec.definitions)
            spec.definitions = { };
         if(peekToken().type == '}')
            readToken();
      }
      return spec;
   }

   void print()
   {
      type.print();
      if(type)
         out.Print(" ");
      if(id) id.print();
      if(baseSpecs)
      {
         out.Print(" : ");
         baseSpecs.print();
      }
      if(definitions)
      {
         out.PrintLn("");
         printIndent();
         out.PrintLn("{");
         indent++;
         definitions.print();
         indent--;
         printIndent();
         out.Print("}");
      }
   }

   ~SpecClass()
   {
      delete id;
      delete baseSpecs;
      delete definitions;
      // delete _class;
      // delete symbol;
      // delete blockStart;
      // delete nameLoc;
      delete ctx;
      // delete extDeclStruct;
   }
}

public class ASTEnumerator : ASTNode
{
public:
   ASTIdentifier id;
   ASTExpression exp;

   ~ASTEnumerator()
   {
      delete id;
      delete exp;
   }
};

public class EnumeratorList : ASTList<ASTEnumerator>
{
public:
}

public class SpecEnum : SpecClass
{
public:
   EnumeratorList enumerators;

   ~SpecEnum()
   {
      delete enumerators;
   }
}

public class ASTAttribute : ASTNode
{
public:
   String attr;
   ASTExpression exp;

   ~ASTAttribute()
   {
      delete attr;
      delete exp;
   }
}

public class ASTAttrib : ASTNode
{
public:
   TokenType2 type;
   List<ASTAttribute> attribs;

   ~ASTAttrib()
   {
      if(attribs) attribs.Free();
      delete attribs;
   }
}

public class ASTExtDecl : ASTNode { }

public class ExtDeclString : ASTExtDecl
{
public:
   String s;

   ~ExtDeclString()
   {
      delete s;
   }
}

public class ExtDeclAttrib : ASTExtDecl
{
public:
   ASTAttrib attr;

   ~ExtDeclAttrib()
   {
      delete attr;
   }
}
