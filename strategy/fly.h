#ifndef FLY_H
#define FLY_H

#include <iostream>
#include <string>

using namespace std;

class FlyingAbility {
public:
    virtual void Fly() = 0;
    virtual ~FlyingAbility() {}
};

class CantFly: public FlyingAbility {
public:
    virtual void Fly() {
        cout<<"Cannot fly"<<endl;
    }
};

class CanFly: public FlyingAbility {
public:
    virtual void Fly() {
        cout<<"Can fly"<<endl;
    }
};

class Animal {
protected:
    FlyingAbility* flyA_;
    string name_;
public:
    Animal(FlyingAbility* fA) {
       flyA_ = fA;
    }
    virtual ~Animal() {}
    virtual void SetName(const string& name) { name_ = name; }
    virtual void SetFlyingAbility(FlyingAbility* fA) { flyA_ = fA;}
    virtual void Fly() {
        flyA_->Fly();
    }
};

#endif
