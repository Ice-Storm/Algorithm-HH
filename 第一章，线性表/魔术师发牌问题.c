#include <stdio.h>

struct list {
	int data;
	struct list *next;
};

struct list *iniNodeList(int n);

struct list *magicStart(struct list* head);

int main(int argc, char *argv[])
{
	struct list *head, *cur;

	int i = 0;

	head = iniNodeList(13);

	head = magicStart(head);

	cur = head->next;

	while(1) {
		printf("%d\n", cur->data);
		cur = cur->next;
		i++;
		if(i == 13) {
			break;
		}
	}

	return 0;
}

struct list *iniNodeList(int n){
	struct list *head, *p, *cur;
	int i;

	cur = head;

	for (i = 1; i <= n; i++) {
		p = (struct list*)malloc(sizeof(struct list));

		p->data = 0;
		p->next = head->next;


		cur->next = p;
		cur = p;
	}

	cur->next = head->next;

	return head;
}

struct list *magicStart(struct list* head){
	int i, countNumber = 1;
	struct list *cur;

	cur = head->next;

	while(1) {
		for (i = 0; i < countNumber; i++){
			if(cur->data == 0) {
				if(i == countNumber-1) {
					cur->data = countNumber;
				}
			} else {
				i--;
			}
			cur = cur->next;
		}

		countNumber++;

		if(countNumber == 14){
			break;
		}
	}

	return head;

};

