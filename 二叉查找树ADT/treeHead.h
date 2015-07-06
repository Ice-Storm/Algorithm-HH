#ifndef TREEHEAD_H_INCLUDED
#define TREEHEAD_H_INCLUDED

struct TreeNode;
typedef int ElementType;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

extern SearchTree CreateSearchTree( ElementType X );
extern SearchTree MakeEmpty( SearchTree T );
extern Position Find( ElementType X, SearchTree T );
extern Position FindMin( SearchTree T );
extern Position FindMax( SearchTree T );
extern SearchTree Insert( ElementType X, SearchTree T );
extern SearchTree Delete( ElementType X, SearchTree T );
extern ElementType Retrieve( Position P );

#include "treeRealize.c"

#endif // TREEHEAD_H_INCLUDED
