#include <stdio.h>
#include <malloc.h>

struct NodeList{
	char data;
	struct NodeList *next;
};

NodeList *initHead(NodeList *head);

int main()
{
	NodeList  node, *head, *tail, *p;
	int flag = 1;
	char inChar;
	
	head = initHead(&node);
	
	while(flag) {
		scanf("%c", &inChar);
		getchar();
		
		if(inChar != 'q') {
			
			if (head->next == NULL) {
				tail = head; 
			} else {
				tail = p;
			}
			

			p = (NodeList *)malloc(sizeof(NodeList));
			
			p->data = inChar;
			p->next= NULL;
			
			tail->next = p;

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