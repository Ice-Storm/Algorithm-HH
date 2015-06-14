#include <stdio.h>

/*
 *   汉诺塔问题
 *
 *  假设有三根柱子  A B C
 *
 *  状态0: A按顺序放着n个盘子，B和C是空的
 *         目标是把A上的n个盘子移动到C，所以C的最下面应该是标号为n的盘子，n上面的n-1个盘子既不能放
 *         在A，也不能放在C(如果放在C，那n就没法放到C，游戏没法玩了)
 *
 *  状态1: A上面有最大的盘子n，B上n-1，C为空
 *
 *         中间状态0:  把A上最大的盘子n移动到C，这时A空，B上n-1个盘子, C上为n
 *
 *         中间状态1:  C上为最大的盘子n时，它上面可以放任意的盘子，所以可以抽象为空
 *                     即为 A空，B上n-1, C空,在把B上的n-1个盘子移动到A
 *
 *  状态2: A上有n-1个盘子，B空，C上有n（看成是空的）
 *
 *
 *
 */

void hanoi(char a, char b, char c, int n);

int main(){

  hanoi('X', 'Y', 'Z', 3);

  return 0;
}

void hanoi(char a, char b, char c, int n){

  if(n == 1){
    printf("\n%c --> %c", a, c);
  }else {
    hanoi(a, c, b, n - 1);
    printf("\n%c --> %c", a, c);
    hanoi(b, a, c, n - 1);
  }

}
