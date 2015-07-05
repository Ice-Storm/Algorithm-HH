#ifndef LISTHEAD_H_INCLUDED
#define LISTHEAD_H_INCLUDED

struct Node;
typedef int ElementType;
typedef struct Node *PtrToNode;
typedef PtrToNode List;               //指向头结点的指针
typedef PtrToNode Position;           //指向链表任意一个节点的指针

extern List CreateList();
extern List MakeEmpty(List L);        //清空头指针并且重新生成
extern int IsEmpty(List L);
extern int IsLast(Position P, List L);
extern Position Find(ElementType X, List L);
extern void Delete(ElementType X, List L);   //删除链表出现的第一个X元素
extern Position FindPrevious(ElementType X, List L);
extern void Insert(ElementType X, List L, Position P);
extern void DeleteList(List L);
extern Position Header(List L);
extern Position First(List L);
extern Position Advance(Position P);
extern ElementType Retrieve(Position P);     //Retrive取回，恢复

#include "listRealize.c"

#endif // LISTHEAD_H_INCLUDED
