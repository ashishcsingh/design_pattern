#ifndef PIZZA_H
#define PIZZA_H

#include <string>
#include <iostream>

using namespace std;

/*
 * Base pizza class
 * It contains setters for customizing all the components
 * And also consumption methods like GetInfo.
 */
class Pizza {
   protected:
      string base_, topping_, sauce_;
   public:
      virtual void SetBase(const string& newBase) {
         base_ = newBase;
      }
      virtual void SetTopping(const string& newTopping) { 
         topping_ = newTopping;
      }
      virtual void SetSauce(const string& newSauce) {
         sauce_ = newSauce;
      }
      virtual void GetInfo() {
         cout<<"=== Pizza details "<<endl;
         cout<<" Base details "<<base_<<endl;
         cout<<" Topping details "<<topping_<<endl;
         cout<<" Sauce details "<<sauce_<<endl;
      }
};

/*
 * Base Builder class.
 * Contains the base pizza member and builder methods.
 */
class PizzaBuilder {
   protected:
      Pizza pizza_;
   public:
      virtual void BuildBase() = 0;
      virtual void BuildTopping() = 0;
      virtual void BuildSauce() = 0;
      Pizza& GetPizza() {
         return pizza_;
      }
};

/*
 * The base pizza customizer defined as Builder.
 */
class VegPizzaBuilder: public PizzaBuilder{
   public:
      virtual void BuildBase() {
         pizza_.SetBase("Wheat Dough");
      }
      virtual void BuildTopping() {
         pizza_.SetTopping("Mushroom Bellpapers Onion");
      }
      virtual void BuildSauce() {
         pizza_.SetSauce("Marinara");
      }
};

class PepporiniPizzaBuilder: public PizzaBuilder{
   public:
      virtual void BuildBase() {
         pizza_.SetBase("Pan Crust");
      }
      virtual void BuildTopping() {
         pizza_.SetTopping("Pepporini Cheese");
      }
      virtual void BuildSauce() {
         pizza_.SetSauce("Marinara");
      }
};

class CheesePizzaBuilder: public PizzaBuilder{
   public:
      virtual void BuildBase() {
         pizza_.SetBase("Thin Crust");
      }
      virtual void BuildTopping() {
         pizza_.SetTopping("Cheese");
      }
      virtual void BuildSauce() {
         pizza_.SetSauce("Ranch");
      }
};

/*
 * Director calls the builder methods.
 * MakePizza() takes PizzaBuilder and calls all build methods.
 */
class PizzaDirector {
   protected:
      PizzaBuilder* builder_;
   public:
   Pizza& MakePizza(PizzaBuilder* newBuilder) {
      builder_ = newBuilder;
      builder_->BuildBase();
      builder_->BuildTopping();
      builder_->BuildSauce();
      return builder_->GetPizza();
   }
   Pizza& GetPizza() {
      return builder_->GetPizza();
   }
};

#endif

