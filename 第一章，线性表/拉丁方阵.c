#include <stdio.h>

struct list {
	int data;
	struct list *next;
};

struct list *iniNodeList(int n); //生成一个构成 n 行 n 列拉丁方阵的单链表

void showList(struct list *head);

int main(int argc, char *argv[])
{
	struct list *head, *cur;

	int i = 0;

	head = iniNodeList(9);

	showList(head);

	return 0;
}

struct list *iniNodeList(int n){
	struct list *head, *p, *cur;
	int i;

	cur = head;

	for (i = 1; i <= n; i++) {
		p = (struct list*)malloc(sizeof(struct list));

		p->data = i;
		p->next = head->next;

		cur->next = p;
		cur = p;

	}

	cur->next = head->next;

	return head;
}

void showList(struct list *head) {
  struct list *cur, *temp, *h;
  int i;

  head = head->next;

  cur = head;

  temp = head;

   do {
     while(cur->next != temp) {
      printf("%2d", cur->data);
      cur = cur->next;
    }

    printf("\n");

    temp = temp->next;
    cur = temp;

  }while(temp != head);

}

