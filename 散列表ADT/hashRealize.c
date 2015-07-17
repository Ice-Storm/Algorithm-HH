#include <stdlib.h>
#include <math.h>

typedef struct HashEntry Cell;
enum KindOfEntry { Legitimate, Empty, Delete };

struct HashEntry{
  ElementType Element;
  enum KindOfEntry Info;
};

struct HashTbl{
  int TableSize;
  Cell *TheCells;
};

HashTable InitializeTable( int TableSize ){
  HashTable H;
  int i;

  if( TableSize <= 0 ){
    printf("%s", "TableSize不能为负数或者0");
    return 0;
  }

  H = malloc( sizeof ( struct HashTbl ) );

  if( H == NULL ){
    printf("%s", "HashTable申请空间失败");
    return 0;
  }

  H->TableSize = TableSize;

  H->TheCells = malloc( sizeof( Cell ) * H->TableSize );

  if( H == NULL ){
    printf("%s", "TheCells申请空间失败");
    return 0;
  }

  for( i = 0; i < H->TableSize; i++)
    H->TheCells[i].Info = Empty;

  return H;
}

Position Hash( ElementType Key, int TableSize ){
  return Key % TableSize;
}

void DestoryTable( HashTable H ){

}

Position Find( ElementType Key, HashTable H ){
  int Count = 0;

  int CurrentNum = 0;

  CurrentNum = Hash( Key, H->TableSize );

  while( H->TheCells[ CurrentNum ].Info != Empty && H->TheCells[ CurrentNum ].Element != Key){
   CurrentNum += 2 * ++Count - 1;
  // CurrentNum += pow( ++Count, 2 ) - 1;
   printf("--%d--\n", Count);

    if( CurrentNum >= H->TableSize )
      CurrentNum -= H->TableSize;
      //CurrentNum %= H->TableSize;

  }

  return CurrentNum;

}

void Insert( ElementType Key, HashTable H ){
  Position Pos;

  Pos = Find( Key, H );

  if( H->TheCells[ Pos ].Info != Legitimate ){
    H->TheCells[ Pos ].Info = Legitimate;
    H->TheCells[ Pos ].Element = Key;
  }
}

ElementType Retrieve( Position P, HashTable H ){

}

HashTable Rehash( HashTable H ){

}



























