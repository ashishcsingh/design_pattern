#ifndef ROBOT_H
#define ROBOT_H

#include <string>
#include <iostream>

using namespace std;

/*
 * Bluprint of Robot.
 * It is has 3 known parts (head, torso, legs)
 */
class RobotPlan {
private:
      string head_, torso_, legs_;
public:
   void SetHead(const string& head) {
      head_ = head;
   }
   string GetHead() {
      return head_;
   }
  void SetTorso(const string& torso) {
      torso_ = torso;
   }
   string GetTorso() {
      return torso_;
   }
  void SetLegs(const string& legs) {
      legs_ = legs;
   }
   string GetLegs() {
      return legs_;
   }
   friend ostream& operator<<(ostream& os, RobotPlan& rb);
};

ostream& operator<<(ostream& os, RobotPlan& rb) {
   os<<"===   Robot details   ==="<<endl;
   os<<" Head : "<<rb.GetHead()<<endl;
   os<<" Torso : "<<rb.GetTorso()<<endl;
   os<<" Legs : "<<rb.GetLegs()<<endl;
   return os;
}

/*
 * Builder Design Pattern abstract class
 * It has a robot to customize by childrens.
 */
class RobotBuilder {
public:
      RobotPlan robot_;
   RobotPlan& GetRobot() {
      return robot_;
   }
   virtual void BuildHead() = 0;
   virtual void BuildTorso() = 0;
   virtual void BuildLegs() = 0;
};

class OldRobotBuilder : public RobotBuilder {
   public:
   virtual void BuildHead() {
      GetRobot().SetHead("Tin Head");
   }
   virtual void BuildTorso() {
      GetRobot().SetTorso("Tin Torso");
   }
   virtual void BuildLegs() {
      GetRobot().SetLegs("Tin Legs");
   }
};

class NewRobotBuilder : public RobotBuilder {
   public:
   virtual void BuildHead() {
      GetRobot().SetHead("Steel Head");
   }
   virtual void BuildTorso() {
      GetRobot().SetTorso("Steel Torso");
   }
   virtual void BuildLegs() {
      GetRobot().SetLegs("Steel Legs");
   }
};

class NextGenRobotBuilder : public RobotBuilder {
   public:
   virtual void BuildHead() {
     GetRobot().SetHead("Titanium Head");
   }
   virtual void BuildTorso() {
      GetRobot().SetTorso("Titanium Torso");
   }
   virtual void BuildLegs() {
      GetRobot().SetLegs("Titanium Legs");
   }
};

class RobotDirector {
   public:
   RobotPlan& RobotMaker(RobotBuilder* rb) {
      rb_ = rb;
      rb_->BuildHead();
      rb_->BuildTorso();
      rb_->BuildLegs();
      return rb_->GetRobot();
   }

   virtual RobotPlan& GetRobot() {
      return rb_->GetRobot();
   };
   protected:
   RobotBuilder* rb_;
};

#endif

