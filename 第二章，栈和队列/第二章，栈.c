#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 10

struct stack{
  int *top;
  int *base;
  int stackSize;
};

struct stack initStack(struct stack s);

struct stack push(struct stack s, int n);

void pop(struct stack s);

int main ()
{
  struct stack stackExp;

  stackExp = initStack(stackExp);
  int i = 0;

  for(i = 0; i < 18; i++ ){
    stackExp = push(stackExp, i);
    printf("%d\n", *(stackExp.top));
   // printf("%p---!!-\n", stackExp.top);
  }

}

struct stack initStack(struct stack s){
  s.base = (int *)malloc(MAX_STACK_SIZE * sizeof(int));

  s.top = s.base;

  s.stackSize = MAX_STACK_SIZE;

  return s;
};

struct stack push(struct stack s, int n){

  if(s.top - s.base >= MAX_STACK_SIZE) {
    s.base = (int*)realloc(s.base, (MAX_STACK_SIZE + 1) * sizeof(int));
    printf("%p*******\n", s.base);
    if(!s.base) {
      printf("---%s---\n", "动态增容");
      s.stackSize++;

      printf("---!%p!---\n", s.top);
      s.top = s.base + s.stackSize;
      printf("---!%p!---\n", s.top);

      s.top = &n;

      return s;
    } else {

      printf("%s*******\n", "malloc失败");
      exit(1);
    }

  }

  s.top++;

  *(s.top) = n;

  return s;

};


