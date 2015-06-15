#include <stdio.h>
#include <math.h>

#define MAX_STACK_SIZE 15

typedef struct {
  int data[MAX_STACK_SIZE];
  int top;
} stack;

void push(stack *s, int n);

int calculate(stack *s);

int main(int argc, char *argv)
{
  stack *stackExp, p;
  int i, n, sum;

  stackExp = &p;

  stackExp->top = 0; //初始化栈顶指针

  printf("%s", "请输出二进制数(输入999作为结束符)\n");
  scanf("%d", &n);
  while(n != 999) {
    push(stackExp, n);
    scanf("%d", &n);
  }

  printf("%s", "你输入的二进制数是");
  for(i = 0; i < stackExp->top; i++) {
    printf("%d", stackExp->data[i]);
  }

  sum = calculate(stackExp);

  printf("\n转换为十进制是%d", sum);


	return 0;
}

void push(stack *s, int n){
  if(s->top >= MAX_STACK_SIZE) {
    printf("%s %d", "栈满,最大输入位数", MAX_STACK_SIZE);
    exit(0);
  }

  s->data[s->top] = n;
  s->top++;
}

int calculate(stack *s){
  int sum = 0, count = 0;

  s->top--;

  while(s->top >= 0){

    sum += pow(2 * s->data[s->top], count);
    s->top--;
    count++;
  }

  sum--;     // 0的0次方是1，所以结果减一

  return sum;

}
