#include <stdlib.h>
#include "listHead.h"

int main()
{
  List list;

  list = CreateList();

  Insert(3, list, list);
  Insert(4, list, Advance(list));

  //DeleteList(list);
  MakeEmpty(list);

  printf("%p", list->Next);

  return 0;
}
