#include <stdio.h>

/* 斐波那契数列最终都会被拆分成 fib(1) + fib(0) 的形式
 *
 * Example ->
 * 当 n = 4 时
 *
 * fib(4) = fib(3) + fib(2) = fib(2) + fib(1) + fib(2) = fib(1) + fib(0) + fib(1) + fib(1) + fib(0) = 5
 */

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
