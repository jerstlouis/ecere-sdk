import "lexing"

public class ASTNode : Container
{
public:
   Location loc;

   virtual void print();

   ~ASTNode()
   {
      if(this)
         Free();
   }
}

public class ASTList : ASTNode
{
public:
   List<ASTNode> list { };

   IteratorPointer GetFirst()                             { return list ? list.GetFirst() : 0; }
   IteratorPointer GetLast()                              { return list ? list.GetLast() : 0; }
   IteratorPointer GetPrev(IteratorPointer pointer)       { return list ? list.GetPrev(pointer) : 0; }
   IteratorPointer GetNext(IteratorPointer pointer)       { return list ? list.GetNext(pointer) : 0; }
   bool SetData(IteratorPointer pointer, D data)          { return list ? list.SetData(pointer, (ASTNode)data) : 0; }
   D GetData(IteratorPointer pointer)                     { return list ? list.GetData(pointer) : (D)0; }
   IteratorPointer GetAtPosition(I pos, bool create, bool * justAdded)      { return list ? list.GetAtPosition((int)pos, create, justAdded) : 0; }
   IteratorPointer Insert(Link after, T value)            { return list ? list.Insert(after, (void *)value) : 0; }
   IteratorPointer Add(T value)                           { return list ? list.Add((void *)value) : 0; }
   void Remove(IteratorPointer it)                        { if(list) list.Remove(it); }
   void Move(IteratorPointer it, IteratorPointer after)   { if(list) list.Move(it, after); }
   void RemoveAll()                                       { if(list) list.RemoveAll(); }
   void Copy(Container<T> source)                         { if(list) list.Copy(source); }
   IteratorPointer Find(D value)                          { return list ? list.Find((void *)value) : 0; }
   void FreeIterator(IteratorPointer it)                  { if(list) list.FreeIterator(it); }
   int GetCount()                                         { return list ? list.GetCount() : 0; }
   void Free()                                            { /*if(list) list.Free();*/ }
   void Delete(IteratorPointer i)                         { if(list) list.Delete(i); }

public:
   virtual void printSep()
   {
      out.Print(", ");
   }

   void print()
   {
      Iterator<ASTNode> it { list };
      while(it.Next())
      {
         it.data.print();
         if(list.GetNext(it.pointer))
            printSep();
      }
   }

   Container ::parse(subclass(Container) c, ASTNode parser(), char sep)
   {
      Container<ASTNode> list = null;
      while(true)
      {
         ASTNode e = parser();
         if(e)
         {
            if(!list) list = eInstance_New(c);
            list.Add(e);
         }
         peekToken();
         if(sep && nextToken.type == sep)
            readToken();
         else if(sep || nextToken.type == '}' || !nextToken.type)
            break;
      }
      return list;
   }

   ~ASTList()
   {
      Free();
   }

   void topoSort()
   {
#if 0
      OldList * input;
      OldList L { };
      OldList S { };
      OldList B { };
      External n, next;
      //External x;

      for(n = input->first; n; n = next)
      {
         next = n.next;
         if(n.type == declarationExternal && !n.declaration)
         {
            input->Remove(n);
            if(n.symbol && n.symbol.structExternal == n)
               n.symbol.structExternal = null;
            FreeExternal(n);
         }
         else if(!n.incoming.count)
         {
            input->Remove(n);
            S.Add(n);
         }
         else if(!n.nonBreakableIncoming)
         {
            input->Remove(n);
            B.Add(n);
         }
      }
   /*
            for(x = input->first; x; x = x.next)
            {
               int count = 0;
               for(e : x.incoming; !e.breakable)
                  count++;
               if(count != x.nonBreakableIncoming)
                  printf("Bug in input");

               if(!x.incoming.count)
                  printf("This node should be in S!\n");
               for(e : x.incoming)
               {
                  External y, from = e.from;
                  for(y = input->first; y; y = y.next)
                     if(y == from)
                        break;
                  if(!y)
                  {
                     for(y = B.first; y; y = y.next)
                        if(y == from)
                           break;
                  }

                  if(!y)
                  {
                     for(y = S.first; y; y = y.next)
                        if(y == from)
                           break;
                  }
                  if(!y)
                  {
                     printf("This node is nowhere!\n");
                  }
               }
            }*/

      while(true)
      {
         TopoEdge e, ne;
         if((n = S.first))
         {
            /*
            for(x = input->first; x; x = x.next)
            {
               int count = 0;
               for(e : x.incoming; !e.breakable)
                  count++;
               if(count != x.nonBreakableIncoming)
                  printf("Bug in input");
               if(!x.incoming.count)
                  printf("This node should be in S!\n");
               for(e : x.incoming)
               {
                  External y, from = e.from;
                  for(y = input->first; y; y = y.next)
                     if(y == from)
                        break;
                  if(!y)
                  {
                     for(y = B.first; y; y = y.next)
                        if(y == from)
                           break;
                  }

                  if(!y)
                  {
                     for(y = S.first; y; y = y.next)
                        if(y == from)
                           break;
                  }
                  if(!y)
                  {
                     printf("This node is nowhere!\n");
                  }
               }
            }*/

            //DebugPrint("*** Free Node: [", n.id, "]\n\t", n.output);
            S.Remove((IteratorPointer)n);

            /*
            if(n && n.symbol && n.symbol.string && !strcmp(n.symbol.string, "ecere::com::Instance"))
               printf("Adding Instance\n");
            */

            L.Add(n);
            for(e = n.outgoing.first; e; e = ne)
            {
               External m = e.to;
               OldList * list;

               //DebugPrint(" This Free Node has an edge to [", m.id, "] ", m.output);
               if(m.nonBreakableIncoming)
               {
                  //DebugPrint("... which we think is in input");
                  list = input;
               }
               else
               {
                  //DebugPrint("... which we think is in B");
                  list = &B;
               }

               if(!list->count)
                  PrintLn("!!! Something's wrong !!!");
               ne = e.out.next;

               if(!e.breakable)
               {
   #ifdef _DEBUG
                  if(!m.nonBreakableIncoming)
                     printf("Bug");
   #endif
                  m.nonBreakableIncoming--;
                  //DebugPrint("Reducing non breakable incoming, now ", m.nonBreakableIncoming);
               }

               n.outgoing.Remove((IteratorPointer)e);
               m.incoming.Remove((IteratorPointer)e);
               delete e;

               if(!m.incoming.count)
               {
                  //DebugPrint("Last edge to this node taken out, moving to S...");
                  list->Remove(m);
                  S.Add(m);
               }
               else if(!m.nonBreakableIncoming)
               {
                  //DebugPrint("Last non-breakable edge to this node taken out, moving to B...");
                  list->Remove(m);
                  B.Add(m);
               }
            }
         }
         else if((n = B.first))
         {
            //DebugPrint("Breaking some of the ", n.incoming.count, " incoming edges to [", n.id, "] ", n.output);
            B.Remove((IteratorPointer)n);

            // Break the edges of this node
            for(e = n.incoming.first; e; e = ne)
            {
               TopoEdge e2, n2;
               External m = e.from;
               External f;
   /*
            for(x = input->first; x; x = x.next)
            {
               int count = 0;
               for(e : x.incoming; !e.breakable)
                  count++;
               if(count != x.nonBreakableIncoming)
                  printf("Bug in input");
               if(!x.incoming.count)
                  printf("This node should be in S!\n");
               for(e : x.incoming)
               {
                  External y, from = e.from;
                  for(y = input->first; y; y = y.next)
                     if(y == from)
                        break;
                  if(!y)
                  {
                     for(y = B.first; y; y = y.next)
                        if(y == from)
                           break;
                  }

                  if(!y)
                  {
                     for(y = S.first; y; y = y.next)
                        if(y == from)
                           break;
                  }
                  if(!y && from != n)
                  {
                     printf("This node is nowhere!\n");
                  }
               }
            }*/

               f = m.ForwardDeclare();
               ne = e.in.next;
   /*
            for(x = input->first; x; x = x.next)
            {
               int count = 0;
               for(e : x.incoming; !e.breakable)
                  count++;
               if(count != x.nonBreakableIncoming)
                  printf("Bug in input");
               if(!x.incoming.count)
                  printf("This node should be in S!\n");
               for(e : x.incoming)
               {
                  External y, from = e.from;
                  for(y = input->first; y; y = y.next)
                     if(y == from)
                        break;
                  if(!y)
                  {
                     for(y = B.first; y; y = y.next)
                        if(y == from)
                           break;
                  }

                  if(!y)
                  {
                     for(y = S.first; y; y = y.next)
                        if(y == from)
                           break;
                  }
                  if(!y && from != n && from != f)
                  {
                     printf("This node is nowhere!\n");
                  }
               }
            }
   */
               // Recheck input for edges created by forward declaration
               {
                  External c, next;
                  for(c = input->first; c; c = next)
                  {
                     next = c.next;
                     if(!c.incoming.count)
                     {
                        input->Remove(c);
                        S.Add(c);
                     }
                     else if(!c.nonBreakableIncoming)
                     {
                        input->Remove(c);
                        B.Add(c);
                     }
                  }
               }

               //DebugPrint("Breaking edge from ", e.from.id, " to ", e.to.id);
               //DebugPrint("Creating a forward decl node [", f.id, "] for [", m.id, "]");

               for(e2 = m.outgoing.first; e2; e2 = n2)
               {
                  n2 = e2.out.next;
                  if(e2.breakable)
                  {
                     External to = e2.to;

                     if(e2 == e)
                        ;//DebugPrint("Breaking this particular connection");
                     else
                        ;//DebugPrint("Also redirecting connection from ", m.id, " to ", to.id, " to come from ", f.id, " instead.");
                     e2.breakable = false;
                     e2.from = f;
                     m.outgoing.Remove((IteratorPointer)e2);
                     f.outgoing.Add(e2);
                     to.nonBreakableIncoming++;
                     if(e2 != e && to.nonBreakableIncoming == 1)
                     {
                        // If this node was previously in B, move it to input
                        B.Remove(to);
                        input->Add(to);
                     }

                     //DebugPrint("Node ", e2.to.id, " now has ", e2.to.nonBreakableIncoming, " non-breakable incoming edges.");
                  }
               }
   /*
            for(x = input->first; x; x = x.next)
            {
               int count = 0;
               for(e : x.incoming; !e.breakable)
                  count++;
               if(count != x.nonBreakableIncoming)
                  printf("Bug in input");
               if(!x.incoming.count)
                  printf("This node should be in S!\n");
               for(e : x.incoming)
               {
                  External y, from = e.from;
                  for(y = input->first; y; y = y.next)
                     if(y == from)
                        break;
                  if(!y)
                  {
                     for(y = B.first; y; y = y.next)
                        if(y == from)
                           break;
                  }

                  if(!y)
                  {
                     for(y = S.first; y; y = y.next)
                        if(y == from)
                           break;
                  }
                  if(!y && from != n && from != f)
                  {
                     printf("This node is nowhere!\n");
                  }
               }
            }*/
               if(!f.incoming.count)
                  S.Add(f);
               else if(!f.nonBreakableIncoming)
                  B.Add(f);
               else
                  input->Add(f);
   /*
            for(x = input->first; x; x = x.next)
            {
               int count = 0;
               for(e : x.incoming; !e.breakable)
                  count++;
               if(count != x.nonBreakableIncoming)
                  printf("Bug in input");
               if(!x.incoming.count)
                  printf("This node should be in S!\n");
               for(e : x.incoming)
               {
                  External y, from = e.from;
                  for(y = input->first; y; y = y.next)
                     if(y == from)
                        break;
                  if(!y)
                  {
                     for(y = B.first; y; y = y.next)
                        if(y == from)
                           break;
                  }

                  if(!y)
                  {
                     for(y = S.first; y; y = y.next)
                        if(y == from)
                           break;
                  }

                  if(!y)
                  {
                     for(y = L.first; y; y = y.next)
                        if(y == from)
                        {
                           PrintLn("This node is already in L!");
                           break;
                        }
                  }

                  if(!y && from != n)
                  {
                     ConsoleFile file { };
                     printf("This node is nowhere!\n");
                     OutputExternal(from, file);
                     delete file;
                  }
               }
            }
   */
               // Avoid needless edge breaking by processing a node as soon as one shows up in S
               if(S.first)
                  break;
            }

            // Put n back in input because it now has unbreakable edges
            input->Add(n);
         }
         else
         {
            if(input->count)
            {
   #ifdef _DEBUG
               ConsoleFile f { };
               External e = input->first;
   #endif
               Compiler_Error("declarations cycles found\n");
   #ifdef _DEBUG
               //OutputTree(input, f);
   /*
            for(x = input->first; x; x = x.next)
            {
               int count = 0;
               for(e : x.incoming; !e.breakable)
                  count++;
               if(count != x.nonBreakableIncoming)
                  printf("Bug in input");
               if(!x.incoming.count)
                  printf("This node should be in S!\n");

               for(e : x.incoming)
               {
                  External y, from = e.from;
                  for(y = input->first; y; y = y.next)
                     if(y == from)
                        break;
                  if(!y)
                  {
                     for(y = B.first; y; y = y.next)
                        if(y == from)
                           break;
                  }

                  if(!y)
                  {
                     for(y = S.first; y; y = y.next)
                        if(y == from)
                           break;
                  }
                  if(!y)
                  {
                     printf("This node is nowhere!\n");
                  }
               }
            }
   */
               SetOutputLineNumbers(false);
               OutputExternal(e, f);

               PrintLn("\nDepends on:\n");
               { TopoEdge i; for(i = e.incoming.last; i && !i.breakable && i.from.incoming.count; i = i.in.next) { e = i.from; break; } }

               OutputExternal(e, f);

               PrintLn("\nWhile that depends on:\n");
               { TopoEdge i; for(i = e.incoming.first; i && !i.breakable && i.from.incoming.count; i = i.in.next) { e = i.from; break; } }

               OutputExternal(e, f);

               PrintLn("\nWhile that depends on:\n");
               { TopoEdge i; for(i = e.incoming.first; i && !i.breakable && i.from.incoming.count; i = i.in.next) { e = i.from; break; } }

               OutputExternal(e, f);

               PrintLn("\nWhile that depends on:\n");
               { TopoEdge i; for(i = e.incoming.first; i && !i.breakable && i.from.incoming.count; i = i.in.next) { e = i.from; break; } }

               OutputExternal(e, f);
               delete f;

               system("pause");

               while((e = input->first))
               {
                  input->Remove(e);
                  L.Add(e);
               }
               *input = L;
   #endif
            }
            else
               *input = L;
            break;
         }
      }

      for(n = input->first; n; n = next)
      {
         next = n.next;
         if(n.type == declarationExternal && (!n.declaration || ((!n.declaration.specifiers || !n.declaration.specifiers->count) && (!n.declaration.declarators || !n.declaration.declarators->count))))
         {
            input->Remove(n);
            if(n.symbol && n.symbol.structExternal == n)
               n.symbol.structExternal = null;
            FreeExternal(n);
         }
      }
#endif // 0
   }
}
