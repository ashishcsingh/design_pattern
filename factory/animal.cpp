#include "animal.h"
#include <vector>

using namespace std;

int main() {
   vector<Animal*> animals;
   vector<char> types {'P','D','C'};
   // Using static factory create all animals of all kinds.
   for(auto c: types) {
      animals.push_back(AnimalFactory::MakeAnimal(c));
   }
   // Invoke common method.
   for(auto a: animals) {
      a->MakeNoise();
   }
   // Cleaning vector of animal ptrs.
   for(auto a: animals) {
      delete a;
   }
}

