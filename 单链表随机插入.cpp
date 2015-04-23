#include <stdio.h>
#include <malloc.h>

struct NodeList{
	char data;
	struct NodeList *next;
};

NodeList *initHead(NodeList *head); //创建头节点 

NodeList *createList(NodeList *head);  //初始化单链表

NodeList *insNode(NodeList *head, int posi, int ele); //插入  

int main()
{
	NodeList  node, *head, *list, *ins, *createListHead, *insBefore;
	int flag = 1;
	int insChar, insPosi, count;
	
	insPosi = 3; //插入位置 
	insChar = 9; //插入值 
	
	count = 1; //计数器 
	
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
	
	insBefore = insNode(createListHead, insPosi, insChar);

	while(insBefore->next){
		printf("%d ---- 节点数据域 ", insBefore->next->data);
		printf("%p ---- 节点本身地址 ", insBefore->next);
		printf("%p ---- 节点指向地址 \n", insBefore->next->next);
		
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

NodeList *insNode(NodeList *head, int posi, int ele) {
	if (posi < 1 || posi > head->data){
		printf("%s", "越界"); 
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