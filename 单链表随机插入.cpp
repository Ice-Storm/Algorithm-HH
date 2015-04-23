#include <stdio.h>
#include <malloc.h>

struct NodeList{
	char data;
	struct NodeList *next;
};

NodeList *initHead(NodeList *head); //����ͷ�ڵ� 

NodeList *createList(NodeList *head);  //��ʼ��������

NodeList *insNode(NodeList *head, int posi, int ele); //����  

int main()
{
	NodeList  node, *head, *list, *ins, *createListHead, *insBefore;
	int flag = 1;
	int insChar, insPosi, count;
	
	insPosi = 3; //����λ�� 
	insChar = 9; //����ֵ 
	
	count = 1; //������ 
	
	head = initHead(&node);
	
	list = createList(head);
	
	createListHead = list; 
	
	while(list->next){
		printf("%d ---- �ڵ������� ", list->next->data);
		printf("%p ---- �ڵ㱾���ַ ", list->next);
		printf("%p ---- �ڵ�ָ���ַ \n", list->next->next);
		list = list->next;
	}
	
	printf("\n%s\n", "ͷ�巨�Զ���������");
	
	insBefore = insNode(createListHead, insPosi, insChar);

	while(insBefore->next){
		printf("%d ---- �ڵ������� ", insBefore->next->data);
		printf("%p ---- �ڵ㱾���ַ ", insBefore->next);
		printf("%p ---- �ڵ�ָ���ַ \n", insBefore->next->next);
		
		insBefore = insBefore->next;
	}
 
	return (0);
}

NodeList *initHead(NodeList *head) {
	head -> next = NULL;
	return head;
}

NodeList *createList(NodeList *head){
	NodeList *p, *newNode;
	
	//ͷָ�봢��������
	head->data = 10;  
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

NodeList *insNode(NodeList *head, int posi, int ele) {
	if (posi < 1 || posi > head->data){
		printf("%s", "Խ��"); 
		return 0;
	}

	int count = 1;
	NodeList *p;
	p = head;
	
	while (head->next) { 
		if (count == posi) {
			NodeList *newNode;
			newNode = (NodeList *)malloc(sizeof(NodeList));
			newNode->data = ele;
			newNode->next = head->next;
			head->next = newNode;
		}
		head = head->next;
		count++;
	}
	
	return p;
}