#ifndef HASHHEAD_H_INCLUDED
#define HASHHEAD_H_INCLUDED

struct ListNode;
typedef unsigned int Position;

struct HashTbl;
typedef struct HashTbl *HashTable;
typedef int ElementType;

extern HashTable InitializeTable( int TableSize );
extern Position Hash( ElementType Key, int TableSize );
extern void DestoryTable( HashTable H );
extern Position Find( ElementType Key, HashTable H );
extern void Insert( ElementType Key, HashTable H );
extern ElementType Retrieve( Position P, HashTable H );
extern HashTable Rehash( HashTable H );

#include "hashRealize.c"

#endif // HASHHEAD_H_INCLUDED
