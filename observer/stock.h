#ifndef STOCK_H
#define STOCK_H

#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Observer {
    public:
    virtual void Update(float) = 0;
    virtual ~Observer() {}
};

class Subject {
    public:
    virtual void RegisterObserver(Observer*) = 0;
    virtual void UnRegisterObserver(Observer*) = 0;
    virtual void NotifyAll() = 0;
    virtual ~Subject() {}
};

class StockMonitor: public Subject {
    private:
    list<Observer*> oList_;
    float stock_;
    public:
    StockMonitor(float stock) : stock_(stock) {}
    void RegisterObserver(Observer* ob) {
        oList_.push_back(ob);
    }
    void UnRegisterObserver(Observer* ob) {
        oList_.remove(ob);
    }
    void NotifyAll() {
        for(auto o : oList_) {
            o->Update(stock_);
        }
    }
    void SetStock(float newVal) {
        stock_ = newVal;
        NotifyAll();
    }
    float GetStock() {
        return stock_;
    }
};

class StockListener: public Observer {
    private:
    Subject& subject_;
    static int idG_;
    int id_;
    public:
    StockListener(Subject& subject) : subject_(subject), id_(idG_) {
        ++idG_;
        subject_.RegisterObserver(this);
    }
    
    virtual ~StockListener() {
        subject_.UnRegisterObserver(this);
    }
    
    virtual void Update(float stock) {
        cout<<"Stocks seen by Observer Id: "<<id_<<" : ";
        cout<<stock<<endl;
    }
};

int StockListener::idG_ = 0;

#endif

