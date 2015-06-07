#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 20

typedef struct {
	int data[MAX_STACK_SIZE];
	int top;
}stack;

stack *push(stack *s, int n);

int pop(stack *s);

void calculate(stack *s, int *count);

int main(int argc, char *argv[])
{
  stack *stackExp, p;
  char c;
  int temp1, temp2;

  stackExp = &p;
  stackExp->top = 0;

  printf("%s", "请输入后缀表达式(#表示结束)\n");

  while((c = getchar()) != '#'){

    if(isdigit(c) && c != ' ') {
      stackExp = push(stackExp, atoi(&c));
    }

    switch(c){
      case '+':
        temp1 = pop(stackExp);
        temp2 = pop(stackExp);
        stackExp = push(stackExp, temp1 + temp2);
        break;
      case '-':
        temp1 = pop(stackExp);
        temp2 = pop(stackExp);
        stackExp = push(stackExp, temp2 - temp1);
        break;
      case '*':
        temp1 = pop(stackExp);
        temp2 = pop(stackExp);
        stackExp = push(stackExp, temp1 * temp2);
        break;
      case '/':
        temp1 = pop(stackExp);
        temp2 = pop(stackExp);

        if(temp1 == 0) {
          printf("%s", "除数不能为0");
          exit(0);
        }

        stackExp = push(stackExp,  (int)(temp2/temp1));
        break;
    }
  }

  printf("逆波兰表达式结果%d", stackExp->data[0]);

	return 0;
}

stack *push(stack *s, int n){
  if(s->top >= MAX_STACK_SIZE){
    printf("%s", "栈满");
    exit(0);
  }

  s->data[s->top] = n;
  s->top++;

  return s;
}

int pop(stack *s){
  int temp;

  if(s->top < 0){
    printf("%s", "栈下溢");
    exit(0);
  }

  s->top--;
  temp = s->data[s->top];
  s->data[s->top] = 0;

  return temp;
}
