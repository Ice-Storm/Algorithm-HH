#include <stdlib.h>

struct TreeNode
{
  ElementType Element;
  SearchTree Left;
  SearchTree Right;
};

SearchTree CreateSearchTree( ElementType X )
{
  SearchTree S;

  S = malloc(sizeof(struct TreeNode));

  S->Element = X;
  S->Left = S->Right = NULL;

  return S;
}

SearchTree MakeEmpty( SearchTree T )
{
  if( T != NULL)
  {
    MakeEmpty( T->Left );
    MakeEmpty( T->Right );
    free(T);
  }

  return NULL;
}

Position Find( ElementType X, SearchTree T )
{
  //我的实现 ... 对比书上的实现...
  /*
  if( T == NULL)
  {
    return NULL;
  }

  if( X < T->Element)
  {
    return Find(X, T->Left);
  }

  if( X > T->Element)
  {
    return Find(X, T->Right);
  }

  if( X == T->Element)
  {
    return T;
  }
  */

  if( T == NULL)
    return NULL;

  if( X < T->Element)
    return Find(X, T->Left);
  else if( X > T->Element)
    return Find(X, T->Right);
  else
    return T;
}

Position FindMin( SearchTree T )
{
  if( T == NULL)
    return NULL;

  if( T->Left != NULL)
    return FindMin( T->Left );
  else
    return T;
}

Position FindMax( SearchTree T )
{
  //我的非递归实现 ...
  /*
  if( T == NULL)
    return NULL;

  while( T->Right )
    T = T->Right;

  return T;
  */

  if( T != NULL )
    while ( T-> Right != NULL )
      T = T->Right;

  return T;
}

SearchTree Insert( ElementType X, SearchTree T )
{
  Position P, Temp;

  P = malloc(sizeof(struct TreeNode));

  if( P == NULL)
  {
    printf("%s", "申请空间失败");
    return NULL;
  }

  P->Element = X;
  P->Left = P->Right = NULL;

  if( T == NULL)
    return P;
  else if( X < T->Element){
    T->Left = Insert(X, T->Left);
  } else if( X > T->Element ){
    T->Right = Insert(X, T->Right);
  } else{
    // X is in the tree already, but we will do nothing
  }

  return T;
}

SearchTree Delete( ElementType X, SearchTree T )
{
  Position Temp;

  if( T == NULL ){
    printf("%s", "没有找到X");
  } else if( X < T->Element ){

    T->Left = Delete( X, T->Left );

  } else if( X > T->Element ){

    T->Right = Delete( X, T->Right );

  } else if( T->Left && T->Right ){

    Temp = FindMin( T->Right );
    T->Element = Temp->Element;
    T->Right = Delete( T->Element, T->Right );

  } else{

    Temp = T;
    if( T->Left == NULL )
      T = T->Right;
    else if( T->Right == NULL )
      T = T->Left;

    free( Temp );
  }

  return T;
}

ElementType Retrieve( Position P )
{
  return P->Element;
}



