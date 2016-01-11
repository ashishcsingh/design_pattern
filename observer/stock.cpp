#include "stock.h"
#include <iostream>

int main() {
    StockMonitor sm(10);
    vector<StockListener*> vListener;
    for(unsigned i=0; i<3; ++i) {
        vListener.push_back(new StockListener(sm));
    }

    cout<<"Changing stock value"<<endl;
    sm.SetStock(5);
    
    cout<<"Changing stock value"<<endl;
    sm.SetStock(7);
    
    // Cleaning.
   for(unsigned i=0; i<3; ++i) {
        delete vListener[i];
    }
}
