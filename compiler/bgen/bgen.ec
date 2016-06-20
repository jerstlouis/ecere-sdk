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

//#define _NEW_BGEN

class BGen : Application
{
   void Main()
   {
      //if(argc > 1)
      //if(Init())
      {
#if defined(_NEW_BGEN)
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
#else
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
#endif // defined(_NEW_BGEN)
      }
      system("pause");
   }
}
