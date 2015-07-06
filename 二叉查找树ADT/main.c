#include <stdio.h>
#include "treeHead.h"

int main()
{
  SearchTree T;

  T = CreateSearchTree(6);

  //Insert(6, T);
  Insert(2, T);
  Insert(8, T);
  Insert(1, T);
  Insert(4, T);
  Insert(3, T);

  printf("%d", T->Left->Right->Element);

  printf("\n%d", Find(3, T)->Element);

  printf("\n%d", FindMin(T)->Element);

  printf("\n%d", FindMax(T)->Element);

  Delete(2, T);

  printf("\n%d", T->Left->Element);

  return 0;
}
