#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

/*
 * ������������������Ǿ�ֱ�ӽ��������
 * 2����������������������ǽ�����뵽ջ�У�����������ʱ����Ҳ�������ջ�С�
 * 3���������һ�������ţ���ջԪ�ص������������Ĳ��������ֱ������������Ϊֹ��ע�⣬������ֻ�������������
 * 4����������κ������Ĳ��������磨��+���� ��*�������������ȣ���ջ�е���Ԫ��ֱ���������ָ������ȼ���Ԫ��(����ջΪ��)Ϊֹ����������ЩԪ�غ󣬲Ž������Ĳ�����ѹ�뵽ջ�С���һ����Ҫע�⣬ֻ��������" ) "����������ǲŵ���" ( "������������Ƕ����ᵯ��" ( "��
 * 5��������Ƕ����������ĩβ����ջ������Ԫ�����ε�����
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

  printf("%s", "������׺���ʽ(#��Ϊ������)\n");

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
    printf("%s", "ջ��");
    exit(0);
  }

  s->data[s->top] = n;
  s->top++;

  return s;
}

int pop(stack *s){
  int temp;

  if(s->top < 0){
    printf("%s", "ջ����");
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
    printf("!!%s", "�����쳣");
    exit(1);
  }

  if(s->top >= 1){
    return s->top;
  }
}


