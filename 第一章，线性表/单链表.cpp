#include <stdio.h>
#include <malloc.h>

struct NodeList{
	char data;
	struct NodeList *next;
};

NodeList *initHead(NodeList *head);

int main()
{
	NodeList *head, *p;
	NodeList he;
	char inChar;
	int flag = 1;
	
	head = initHead(&he);
	
	printf("头节点指针域%p\n", head->next);
	
	while (flag) {
		scanf("%c", &inChar);
		getchar();
		if(inChar != 'q') {
		 	p = (NodeList *)malloc(sizeof(NodeList));
		  p->data = inChar;
		  p->next = head->next;
		  printf("111%p\n", head->next);
		  head->next = p;
			printf("新建节点数据域%c\n", p->data);
			printf("新建节点指针域%p\n", p->next);
			 printf("ccc%p\n", head->next);
		} else {
			while (head->next) {
				printf("%c", head->next->data);
				head = head->next;
			}
			flag = 0;
		}
	}
	return (0);
}

NodeList *initHead(NodeList *head) {
	head -> next = NULL;
	return head;
}