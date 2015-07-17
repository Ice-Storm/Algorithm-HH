#include <stdio.h>
#include "hashHead.h"


int main(){

  HashTable H;
  Position Pos;

  H = InitializeTable( 10 );

  Insert(89, H);
  Insert(18, H);
  Insert(49, H);
  Insert(58, H);
  Insert(68, H);

  Pos = Find(58, H);

  printf("%d", Pos);

  return 0;
}
