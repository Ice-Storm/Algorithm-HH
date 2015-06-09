#include <stdio.h>

#define N 5

int fib(int n);

int main(){

  int n, i;
  for (i = 0; i < 40; i++){
    printf("%10d", fib(i));
    if (i % N == 0){
      printf("\n");
    }
  }

  return 0;
}

int fib(int n){

  if(n == 0 || n == 1){
    return 1;
  } else {
    return fib(n - 1) + fib(n - 2);
  }

}
