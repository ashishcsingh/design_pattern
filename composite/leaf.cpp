#include "leaf.h"

int main()
{
  Composite containers[4];
  int i, j;
  for (i = 0; i < 4; i++)
    for (j = 0; j < 3; j++)
      containers[i].Add(new Leaf(i *3+j));

  for (i = 1; i < 4; i++)
    containers[0].Add(&(containers[i]));

  for (i = 0; i < 4; i++)
  {
    containers[i].Traverse();
    cout << endl;
  }
}
