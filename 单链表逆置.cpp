#include <stdio.h>
#include <malloc.h>

struct NodeList{
	char data;
	struct NodeList *next;
};

NodeList *initHead(NodeList *head); //创建头节点 

NodeList *createList(NodeList *head);  //初始化单链表

int main()
{
	NodeList  node, *pre, *head, *list, *createListHead, *temp;
	int flag = 1;

	head = initHead(&node);

	list = createList(head);

	createListHead = list; 
	
	while(list->next){
		printf("%d ---- 节点数据域 ", list->next->data);
		printf("%p ---- 节点本身地址 ", list->next);
		printf("%p ---- 节点指向地址 \n", list->next->next);
		list = list->next;
	}
	
	printf("\n%s\n", "头插法自动生成链表");

	//链表逆置
	NodeList *p;
	
	pre = NULL;

	p = createListHead->next; //第一个结点 
	while(p) {
		temp = p->next; //头结点指向的结点 
		p->next = pre;
		pre = p;
		p = temp;
	}
	
	createListHead->next = pre;
	
	while(createListHead->next){
		printf("%d\n", createListHead->next->data);
		createListHead = createListHead->next;
	}
 
	return (0);
}

NodeList *initHead(NodeList *head) {
	head -> next = NULL;
	return head;
}

NodeList *createList(NodeList *head){
	NodeList *p, *newNode;
	
	//头指针储存链表长度
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

