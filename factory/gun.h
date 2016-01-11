#ifndef GUN_H
#define GUN_H

#include <string>
#include <iostream>

using namespace std;

class GunPlan {
protected:
   int damage_, speed_;
   string desc_;
public:
   virtual void SetDescription(const string& desc) { desc_ = desc; }
   virtual string GetDescription() { return desc_; }
   virtual void SetDamage(int damage) { damage_ = damage; }
   virtual int GetDamage() { return damage_; }
   virtual void SetSpeed(int speed) { speed_ = speed; }
   virtual int GetSpeed() { return speed_; }
   virtual ~GunPlan() {}
   friend ostream& operator<<(ostream& os, GunPlan& gp);
};

ostream& operator<<(ostream& os, GunPlan& gp) {
   os<<" == GunType =="<<endl;
   os<<"  "<<gp.GetDescription()<<endl;
   return os;
}

class UfoGun : public GunPlan {
   public:
   UfoGun() {
      SetDescription("UfoGun");
      SetDamage(10);
      SetSpeed(2);
   }
};

class NaiveGun : public GunPlan {
   public:
   NaiveGun() {
      SetDescription("NaiveGun");
      SetDamage(1);
      SetSpeed(1);
   }
};

class HeroGun : public GunPlan {
   public:
   HeroGun() {
      SetDescription("HeroGun");
      SetDamage(100);
      SetSpeed(5);
   }
};

class GunFactory {
public:
   GunPlan MakeGun(const string& type) {
      if(type.compare("UfoGun") == 0) {
         return UfoGun();
      } else if(type.compare("NaiveGun") == 0) {
         return NaiveGun();
      } else if(type.compare("HeroGun") == 0) {
         return HeroGun();
      }
      return NaiveGun();
   }
};

#endif
