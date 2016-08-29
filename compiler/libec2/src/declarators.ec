import "expressions"

public class ASTPointer : ASTNode
{
public:
   SpecsList qualifiers;
   ASTPointer pointer;

   void print()
   {
      out.Print("*");
      if(qualifiers) qualifiers.print();
      if(pointer) pointer.print();
   }

   ASTPointer ::parse()
   {
      ASTPointer ptr { };
      readToken();
      while(peekToken().type == '*')
      {
         readToken();
         ptr = { pointer = ptr };
      }
      return ptr;
   }

   ~ASTPointer()
   {
      delete qualifiers;
      delete pointer;
   }
}

public class ASTDeclarator : ASTNode
{
public:
   DeclaratorType type;
   ASTDeclarator declarator;
   // Symbol symbol;

   ASTDeclarator ::parse()
   {
      ASTDeclarator decl = null;

      if(peekToken().type == '*')
         decl = DeclPointer::parse();
      else
      {
         if(peekToken().type == identifier)
            decl = DeclIdentifier::parse();
         else if(nextToken.type == '(')
            decl = DeclBrackets::parse();
         if(decl)
         {
            while(true)
            {
               if(peekToken().type == '[')
                  decl = DeclArray::parse(decl);
               else if(nextToken.type == '(')
                  decl = DeclFunction::parse(decl);
               else
                  break;
            }
         }
      }
      return decl;
   }

   ~ASTDeclarator()
   {
      delete declarator;
   }
}

public class TypeNameList : ASTList<ASTTypeName>
{
public:
   TypeNameList ::parse()
   {
      TypeNameList list = null;
      int a = pushAmbiguity();
      while(true)
      {
         ASTTypeName e = ASTTypeName::parse();
         peekToken();
         if(e && (nextToken.type == ',' || nextToken.type == ')'))
         {
            if(!list) list = { };
            list.Add(e);

            clearAmbiguity();
            if(nextToken.type == ',')
            {
               readToken();
               a = pushAmbiguity();
            }
            else
               break;
         }
         else
         {
            // Error Recovery
            if(list)
               list.Add({});
            popAmbiguity(a);
            break;
         }
      }
      return list;
      // return (TypeNameList)ASTList::parse(class(TypeNameList), ASTTypeName::parse, ',');
   }
}

public class DeclFunction : ASTDeclarator
{
public:
   TypeNameList parameters;

   void print()
   {
      if(declarator) declarator.print();
      out.Print("(");
      if(parameters) parameters.print();
      out.Print(")");
   }

   DeclFunction ::parse(ASTDeclarator d)
   {
      DeclFunction decl { declarator = d };
      readToken();
      if(peekToken().type != ')') decl.parameters = TypeNameList::parse();
      if(peekToken().type == ')')
         readToken();
      return decl;
   }

   ~DeclFunction()
   {
      delete parameters;
   }
}

public class DeclIdentifier : ASTDeclarator
{
public:
   ASTIdentifier identifier;

   void print()
   {
      if(identifier) identifier.print();
   }

   DeclIdentifier ::parse()
   {
      return { identifier = ASTIdentifier::parse() };
   }

   ~DeclIdentifier()
   {
      delete identifier;
   }
}

public class DeclBrackets : ASTDeclarator
{
public:
   void print()
   {
      out.Print("(");
      if(declarator) declarator.print();
      out.Print(")");
   }

   DeclBrackets ::parse()
   {
      DeclBrackets decl = null;
      ASTDeclarator d;
      readToken();
      d = ASTDeclarator::parse();
      if(d)
         decl = { declarator = d };
      if(peekToken().type == ')')
         readToken();
      return decl;
   }
}

public class DeclArray : ASTDeclarator
{
public:
   ASTExpression exp;
   // ASTSpecifier enumClass;

   void print()
   {
      if(declarator) declarator.print();
      out.Print("[");
      if(exp) exp.print();
      out.Print("]");
   }

   DeclArray ::parse(ASTDeclarator d)
   {
      DeclArray decl { declarator = d };
      readToken();
      if(peekToken().type != ']') decl.exp = ExpConditional::parse();
      if(peekToken().type == ']') readToken();
      return decl;
   }

   ~DeclArray()
   {
      delete exp;
      // delete enumClass;
   }
}

public class DeclPointer : ASTDeclarator
{
public:
   ASTPointer pointer;

   void print()
   {
      if(pointer) pointer.print();
      if(declarator) declarator.print();
   }

   DeclPointer ::parse()
   {
      return { pointer = ASTPointer::parse(), declarator = ASTDeclarator::parse() };
   }

   ~DeclPointer()
   {
      delete pointer;
   }
}

public class DeclStruct : ASTDeclarator
{
public:
   ASTExpression exp;
   ASTExpression posExp;
   ASTAttrib attrib;

   DeclStruct ::parse()
   {
      return { declarator = ASTDeclarator::parse(); };
   }

   ~DeclStruct()
   {
      delete exp;
      delete posExp;
      delete attrib;
   }
}

public class DeclExtended : ASTDeclarator
{
public:
   ExtDecl extended;

   ~DeclExtended()
   {
      delete extended;
   }
}

public class ASTInitializer : ASTNode
{
public:
   // bool isConstant;
   ASTInitializer ::parse()
   {
      if(peekToken().type == '{')
      {
         InitList init;
         readToken();
         init = InitList::parse();
         if(peekToken().type == '}') readToken();
         return init;
      }
      else
         return InitExp::parse();
   }
};

public class InitExp : ASTInitializer
{
public:
   ASTExpression exp;

   void print()
   {
      if(exp)
         exp.print();
   }

   InitExp ::parse()
   {
      return InitExp { exp = ASTExpression::parse() };
   }

   ~InitExp()
   {
      delete exp;
   }
};

public class InitList : ASTInitializer
{
public:
   ASTList<ASTInitializer> list;

   void print()
   {
      if(list)
      {
         out.Print("{ ");
         list.print();
         out.Print(" }");
      }
   }

   InitList ::parse()
   {
      ASTList<ASTInitializer> list = (ASTList<ASTInitializer>)ASTList::parse(class(ASTList<ASTInitializer>), ASTInitializer::parse, ',');
      return list ? { list = (void *)list } : null;
   }

   ~InitList()
   {
      if(list) list.Free();
      delete list;
   }
};

public class ASTInitDeclarator : ASTNode
{
public:
   ASTDeclarator declarator;
   ASTInitializer initializer;

   void print()
   {
      if(declarator) declarator.print();
      if(initializer)
      {
         out.Print(" = ");
         initializer.print();
      }
   }

   ASTInitDeclarator ::parse()
   {
      ASTDeclarator decl = ASTDeclarator::parse();
      if(decl)
      {
         ASTInitializer init = null;
         if(peekToken().type == '=')
         {
            readToken();
            init = ASTInitializer::parse();
         }
         return { declarator = decl, initializer = init };
      }
      return null;
   }

   ~ASTInitDeclarator()
   {
      delete declarator;
      delete initializer;
   }
};

public class InitDeclList : ASTList<ASTInitDeclarator>
{
public:
   InitDeclList ::parse()
   {
      return (InitDeclList)ASTList::parse(class(InitDeclList), ASTInitDeclarator::parse, ',');
   }
}
