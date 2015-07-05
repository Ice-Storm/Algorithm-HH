#include <stdio.h>
#include <stdlib.h>

struct Node
{
    ElementType Element;
    Position Next;
};

List CreateList()
{
  List list;

  list = malloc(sizeof(struct Node));
  list->Next = NULL;

  return list;
}

List MakeEmpty(List L)
{
  if(L != NULL)
    DeleteList(L);

  L = malloc(sizeof(struct Node));

  if(L == NULL)
    printf("%s", "申请空间失败");

  L->Next = NULL;

  return L;

}

int IsEmpty(List L)
{
  return L->Next == NULL;
}

int IsLast(Position P, List L)
{
  return P->Next == NULL;
}

Position Find(ElementType X, List L)
{
  Position p;

  p = L->Next;

  while(p->Element != X && p != NULL)
    p = L->Next;

  return p;
}

void Delete(ElementType X, List L)
{
  Position P, Temp;

  P = FindPrevious(X, L);

  if( !IsLast(P, L) )
  {
    Temp = P->Next;
    P->Next = Temp->Next;
    free(Temp);
  }
}

void Insert(ElementType X, List L, Position P)
{
  Position Temp;

  Temp = malloc(sizeof(struct Node));

  if(Temp == NULL)
    printf("%s", "申请空间失败");

  Temp->Element = X;
  Temp->Next = P->Next;
  P->Next = Temp;
}

Position FindPrevious(ElementType X, List L)
{
  Position P;

  P = L;

  while(P->Next != NULL && P->Next->Element != X)
    P = P->Next;

  return P;
}

void DeleteList(List L)
{
  Position P, Temp;

  P = L->Next;
  L->Next = NULL;             //当时忘了，看书才想起来，思维不够细致

  while( !IsLast(P, L) )
  {
    Temp = P->Next;
    free(P);
    P = Temp;
  }
  free(P);
}

Position Header(List L)
{
  return L;
}

Position First(List L)
{
  return L->Next;
}

Position Advance(Position P)
{
  return P->Next;
}

ElementType Retrieve(Position P)
{
  return P->Element;
}


