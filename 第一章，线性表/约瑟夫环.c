#include <stdio.h>

struct list{
	int data;
	struct list *next;
};

struct list *iniNodeList(int n); //初始化

struct list *josephus(struct list *head, int i, int n); //kill

int main(int argc, char *argv[])
{


	struct list *head;
	head = iniNodeList(41);

	head = josephus(head, 3, 41);

	printf("%d\n", head->data);

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

	return head;
}

struct list *josephus(struct list *head, int i, int n) {

	struct list *cur, *before;
	int count = 1, freeCount = 0;

	cur = head->next;

	while(cur != cur->next) {
		before = cur->next;
		count++;
		if (count == i) {
				cur->next = before->next;
				free(before);
				freeCount++;
				count = 0;

				if(n - freeCount == 1) {
					return cur;
				}
		}

		cur = before;
	}

}
