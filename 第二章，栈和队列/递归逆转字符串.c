#include <stdio.h>

/*
 *  函数的递归调用
 *
 *  函数执行时，调用它的函数保存该函数的返回地址，实参等信息，将该函数入栈
 *  ps:( 感觉保存函数状态那里有点像javascript的闭包 )
 *  重复上述过程，产生函数嵌套
 *  例子 A -> B
 *            B -> C
 *                 C -> D
 *
 *  当执行到最后一层嵌套的时候依次弹栈
 *
 */

void print();

int main(){

  print();

  return 0;
}

void print(){
  char c = getchar();

  if(c != '#') print();

  if(c != '#') printf("%c", c);
}
