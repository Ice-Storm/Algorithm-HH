#include <stdio.h>
#include <malloc.h>

struct NodeList{
	char data;
	struct NodeList *next;
};

NodeList *initHead(NodeList *head); 

NodeList *createList(NodeList *head);

NodeList *deleteList(NodeList *head);

int main(int argc, char *argv[]){
	
	NodeList *head, he;
	
	head = initHead(&he);
	
	head = createList(head);
	
	head = deleteList(head);
	
	printf("%p", head->next);
	
	
	return 0;
}


NodeList *initHead(NodeList *head) {
	head -> next = NULL;
	return head;
}

NodeList *createList(NodeList *head){
	NodeList *p, *newNode;
	
	//?????????????
	head->data = 10;  
	head->next = NULL;  
	p = head;
	
	for (int i = 0; i < 10; i++) {
		newNode = (NodeList *)malloc(sizeof(NodeList));
		if(i == 0) {
			p->next = newNode;
		}
		
		newNode->data = i;
		newNode->next = NULL;
		head->next = newNode;
		head = newNode;
	}
	
	return p;
}

NodeList *deleteList(NodeList *head){
	NodeList *p, *first, *q;
	
	first = head->next;
	
	while(first){
		p = first;
		head->next = first->next;  //???????????? 
		q = p->next;
		free(p);
		first = q; 
	}
	
	return head;
	
}