#include "gun.h"

int main() {
   GunFactory gf;
   auto ug =  gf.MakeGun("UfoGun");
   auto ng = gf.MakeGun("NaiveGun");
   auto hg = gf.MakeGun("HeroGun");
   cout<<ug;
   cout<<ng;
   cout<<hg;
}
