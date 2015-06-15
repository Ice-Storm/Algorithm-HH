#include <stdio.h>

/*
 * 数组实现队列
 *
 * 设置一个头指针 head ，一个尾指针 tail
 * 头指针指向队列元素的前一个空间，尾指针指向队列最后一个元素
 * 头尾相连防止假溢出
 *
 * 初始化时头尾指针为0
 * 当头尾指针指向相同空间时队列满
 *
 */

#define QUEUE_SIZE 10

typedef struct{
  int data[QUEUE_SIZE];
  int head;
  int tail;
  int num;  //队列元素个数
}
queue;

queue *iniQueue();

int addQueue(queue *q, int n);

int removeQueue(queue *q);

int main(){

  queue *queueExp;

  int n;

  queueExp = iniQueue();

  for (n = 0; n < 12; n++) {
    addQueue(queueExp, n);
    printf("%d\n", queueExp->data[queueExp->tail]);
  }

  printf("%d------\n", queueExp->data[0]);

  for (n = 0; n < 12; n++) {
    removeQueue(queueExp);
  }

  printf("%d------", queueExp->data[0]);

  return 0;
}

queue *iniQueue(){
  queue *q;

  q = (queue *)malloc(sizeof(queue));

  q->head = 0;
  q->tail = 0;
  q->num = 0;

  return q;
}

int addQueue(queue *q, int n){
  int tail;

  if(q->num == QUEUE_SIZE) {
    printf("%s", "栈满");
    return 1;
  }

  if(q->tail + 1 < QUEUE_SIZE){
    tail = q->tail + 1;
  }else {
    tail = (q->tail + 1) % QUEUE_SIZE;
  }

  q->data[tail] = n;
  q->tail++;
  q->num++;

  return n;
}

int removeQueue(queue *q){
  int head;

  if(q->num == 0) {
    printf("%s", "栈空");
    return 1;
  }

  if(q->head + 1 < QUEUE_SIZE){
    head = q->head + 1;
  }else {
    head = (q->head + 1) % QUEUE_SIZE;
  }

  q->data[head] = 0;
  q->head++;
  q->num--;

  return 0;
}
