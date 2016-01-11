#ifndef DRIVE_H
#define DRIVE_H

#include <iostream>
#include <string>

using namespace std;

// Interface for Drive()
class AutomobilePlan {
   public:
      virtual void Drive(float distance) = 0;
      virtual ~AutomobilePlan() {}
};

// A known component that implements Drive()
class Car: public AutomobilePlan {
   public:
      virtual void Drive(float distance) {
         cout<<" Moving by distance "<<distance<<endl;
      }
};

// An unknown component that we try to switch to.
class Bike {
   public:
      virtual void Ride(float distance) {
         cout<<" Riding by distance "<<distance<<endl;
      }
      virtual ~Bike() {}
};

// Adapter allows to plug an unknown to meet Drive()
class AutomobileAdapter: public AutomobilePlan {
   public:
      Bike& bk_;
      AutomobileAdapter(Bike& bk) : bk_(bk) {}
      virtual void Drive(float distance) {
         bk_.Ride(distance);
      }
};

#endif

