#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <iostream>

using std::cout;
using std::string;
using std::endl;

/*
 * Base class defining interface for children.
 */
class Animal {
public:
   virtual void MakeNoise() = 0;
   virtual ~Animal() {}
};

class Dog: public Animal {
public:
   virtual void MakeNoise() {
      cout<<"Bhow bhow"<<endl;
   }
};

class Cat: public Animal {
public:
   virtual void MakeNoise() {
      cout<<"Meow meow"<<endl;
   }
};

class Pig: public Animal {
public:
   virtual void MakeNoise() {
      cout<<"Uanck uanck"<<endl;
   }
};

class DefaultAnimal: public Animal {
public:
   virtual void MakeNoise() {
      cout<<"Chi chi"<<endl;
   }
};

/*
 * Animal Factory gives back all types of animals based upon
 * type passed.
 */
class AnimalFactory {
public:
   static Animal* MakeAnimal(char type) {
      switch(type) {
         case 'D' :
            return new Dog();
            break;
         case 'C' :
            return new Cat();
            break;
         case 'P':
            return new Pig();
            break;
         default:
            return new DefaultAnimal();
            break;
      };
   }
};

#endif

