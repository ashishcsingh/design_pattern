#ifndef LEAF_H
#define LEAF_H

#include <iostream>
#include <vector>

using namespace std;

// Common interface for all.
class Component {
   public:
      virtual void Traverse()=0;
};

class Leaf: public Component {
   public:
      virtual void Traverse() {
         cout<<" Value : "<<value_;
      }
      Leaf(int val) {
         value_ = val;
      }
   private:
      int value_;
};

class Composite: public Component {
   public:
      void Add(Component* c) {
         children_.push_back(c);
      }
      virtual void Traverse() {
         for(auto c: children_) {
            c->Traverse();
         }
      }
   private:
      vector<Component*> children_;
};

#endif
