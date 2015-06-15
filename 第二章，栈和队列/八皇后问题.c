#include <stdio.h>

void EightQueen(int col, int row, int (*chess)[8]); // col列， row行

int judge(int row, int col, int (*chess)[8]); //判断是否危险，如果危险返回0，否则返回1

int count = 0;

int main(){

  int chess[8][8], i, j;

  for(i = 0; i < 0; i++){
    for(j = 0; j < 0; j++){
      chess[i][j] = 0;
    }
  }

  EightQueen(8, 0, chess);

  printf("总共有%d种解决方法", count);

  return 0;
}

void EightQueen(int col, int row, int (*chess)[8]){
  int i, j;
  int chessTemp [8][8];

  for(i = 0; i < 8; i++){
    for(j = 0; j < 8; j++){
      chessTemp[i][j] = chess[i][j];
    }
  }

  if(row == 8){

    printf("一共有%d种可能\n", count + 1);
    for(i = 0; i < 8; i++){
      for(j = 0; j < 8; j++){
        printf("%d ", *(*(chessTemp + i) + j));
      }
      printf("\n");
    }
    printf("\n");
    count++;
  }else {

    for(i = 0; i < col; i++){

      if(judge(row, i, chess)){

        for (j = 0; j < 8; j++){
          *(*(chessTemp + row) + j) = 0;
        }

        *(*(chessTemp + row) + i) = 1;
        EightQueen(col, row + 1, chessTemp);
      }

    }

  }
}

int judge(int row, int col, int (*chess)[8]){
  int i, j, flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0, flag5 = 0;

  //判断列上是否有危险

  for (i = 0; i < 8; i++){
    if(*(*(chess + i) + col) == 1){
      flag1 = 1;
      break;
    }
  }

  //判断左上是否有危险

  for (i = row, j = col; i >= 0 && j >= 0; i--, j--){
    if(*(*(chess + i) + j) == 1){
      flag2 = 1;
      break;
    }
  }

  //判断右下是否有危险

  for (i = row, j = col; i < 8 && j < 8; i++, j++){
    if(*(*(chess + i) + j) == 1){
      flag3 = 1;
      break;
    }
  }

  //判断右上是否有危险

  for (i = row, j = col; i >= 0 && j < 8; i--, j++){
    if(*(*(chess + i) + j) == 1){
      flag4 = 1;
      break;
    }
  }

  //判断左下是否有危险

  for (i = row, j = col; i < 8 && j >= 0; i++, j--){
    if(*(*(chess + i) + j) == 1){
      flag5 = 1;
      break;
    }
  }

  if(flag1 || flag2 || flag3 || flag4 || flag5){
    return 0;
  } else{
    return 1;
  }

}
