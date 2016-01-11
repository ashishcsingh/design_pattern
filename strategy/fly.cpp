#include "fly.h"

int main() {
  cout<<"Test dog for fly"<<endl;
  FlyingAbility* cantfly(new CantFly());
  Animal dog(cantfly);
  dog.Fly();
  cout<<"Enabling flying mode for dog"<<endl;
  FlyingAbility* canfly(new CanFly());
  dog.SetFlyingAbility(canfly);
  dog.Fly();
  // Cleaning.
  delete cantfly;
  delete canfly;
}
 

