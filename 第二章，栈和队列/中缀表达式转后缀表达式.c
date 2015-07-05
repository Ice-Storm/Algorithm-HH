#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

/*
 * 如果遇到操作数，我们就直接将其输出。
 * 2）如果遇到操作符，则我们将其放入到栈中，遇到左括号时我们也将其放入栈中。
 * 3）如果遇到一个右括号，则将栈元素弹出，将弹出的操作符输出直到遇到左括号为止。注意，左括号只弹出并不输出。
 * 4）如果遇到任何其他的操作符，如（“+”， “*”，“（”）等，从栈中弹出元素直到遇到发现更低优先级的元素(或者栈为空)为止。弹出完这些元素后，才将遇到的操作符压入到栈中。有一点需要注意，只有在遇到" ) "的情况下我们才弹出" ( "，其他情况我们都不会弹出" ( "。
 * 5）如果我们读到了输入的末尾，则将栈中所有元素依次弹出。
 */


#define MAX_STACK_SIZE 20

typedef struct {
	int data[MAX_STACK_SIZE];
	int top;
}stack;

stack *push(stack *s, int n);

int pop(stack *s);

int stackLen(stack *s);


int main(int argc, char *argv[])
{
  stack *stackExp, p;
  char c, temp;

  stackExp = &p;
  stackExp->top = 0;

  printf("%s", "输入中缀表达式(#作为结束符)\n");

  while((c = getchar()) != '#'){

    if(!isdigit(c) && c != ' '){

      if(c == '+' || c == '-') {

        if(stackLen(stackExp) == 0){

          stackExp = push(stackExp, c);

        }else{

          do{
            temp = pop(stackExp);

            if(temp == '('){
              push(stackExp, temp);
            }else{
              printf("%c", temp);
            }

          }while(stackLen(stackExp) != 0 && temp != '(');

          push(stackExp, c);
        }
      }else if(c == ')'){

        temp = pop(stackExp);
        while(temp != '('){
          printf("%c", temp);
          temp = pop(stackExp);
        }

      }else if (c == '*' || c == '/' || c == '('){

        push(stackExp, c);

      }
    }else{
      printf("% c", c);
    }
  }

  while(stackLen(stackExp) != 0){
    c = pop(stackExp);
    printf(" %c", c);
  }

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

int stackLen(stack *s){
  if(s->top == 0){
    return 0;
  }

  if(s->top < 0){
    printf("!!%s", "长度异常");
    exit(1);
  }

  if(s->top >= 1){
    return s->top;
  }
}


