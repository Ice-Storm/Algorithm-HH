#include <stdio.h>
#include <malloc.h>

struct NodeList{
	char data;
	struct NodeList *next;
};

NodeList *initHead(NodeList *head);

NodeList *list(NodeList *head, char inChar);  //�������봴������ 

void printList(NodeList *head); //����������� 

int main()
{
	NodeList *head;
	NodeList he;
	char inChar;
	int flag = 1;
	
	head = initHead(&he);
	
	printf("ͷָ��ָ����%p\n", head->next);
	
	while (flag) {
		scanf("%c", &inChar);
		getchar();
		if(inChar != 'q') {
	  	head = list(head, inChar);
		} else {
			printList(head);
			flag = 0;
		}
	}
	return (0);
}

NodeList *initHead(NodeList *head) {
	head -> next = NULL;
	return head;
}

NodeList *list(NodeList *head, char inChar) {
	NodeList *node;
	node = (NodeList *)malloc(sizeof(NodeList));
	node->data = inChar;
	node->next = head->next;
	head->next = node;
	return head;
}

void printList(NodeList	*head) {
	NodeList *firstNode = head->next;
	while(firstNode) {
		printf("%c", firstNode->data);
		firstNode = firstNode->next; 
	}
}