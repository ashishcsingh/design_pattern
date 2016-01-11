#include "drive.h"

int main() {
   cout<<"Testing car for Drive"<<endl;
   AutomobilePlan&& apCar = move(Car());
   apCar.Drive(10);
   cout<<"Testing bike for Ride"<<endl;
   Bike bk;
   bk.Ride(20);
   cout<<"Testing bike for Drive"<<endl;
   // Adapter plugs Bike to Automobile interface.
   AutomobilePlan&& apBk = move(AutomobileAdapter(bk));
   apBk.Drive(30);
}

