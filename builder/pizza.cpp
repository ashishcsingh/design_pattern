#include "pizza.h"

using namespace std;

int main() {
   PizzaDirector director;

   VegPizzaBuilder vPizza;
   cout<<"+++++ Veg Pizza cooking"<<endl;
   /*'
    * Director takes Builder pointer and
    * calls all the builder methods and returns pizza.
    */
   director.MakePizza(&vPizza).GetInfo();
   
   PepporiniPizzaBuilder pPizza;
   cout<<"+++++ Pepporini Pizza cooking"<<endl;
   director.MakePizza(&pPizza).GetInfo();
   
   CheesePizzaBuilder cPizza;
   cout<<"+++++ Cheese Pizza cooking"<<endl;
   director.MakePizza(&cPizza).GetInfo();

   return 0;
}
