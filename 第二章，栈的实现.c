#include <stdio.h>

#define MAX_STACK_SIZE 10

struct stack {
  int data[MAX_STACK_SIZE];
  int top;
};

struct stack push(struct stack s, int n);

struct stack pop(struct stack s);

int main(int argc, char *argv[])
{
  struct stack stackExp;
  int i;

  stackExp.top = 0;

  for(i = 0; i < 10; i++) {
    stackExp = push(stackExp, i);
  }

  for(i = 0; i < 11; i++) {
    printf("%d\n", stackExp.data[10]);
    stackExp = pop(stackExp);
  }
  printf("%d\n", stackExp.data[0]);
	return 0;
}

/*
 *  栈的最大size是10， 即 0-9
 *  当栈满时，栈顶指针指向 10
 *
 *  当弹栈时，先将栈顶指针减1，然后释放空间
 *
 */

struct stack push(struct stack s, int n){
  if(s.top >= MAX_STACK_SIZE) {
    printf("%s", "栈满");
    return s;
  }

  s.data[s.top] = n;

  s.top++;

  return s;
};

struct stack pop(struct stack s){
  if(s.top <= 0) {
    printf("%s\n", "栈空");
    return s;
  }

  s.top--;
  s.data[s.top] = 0;

  return s;
};




