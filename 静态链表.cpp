#include <stdio.h>

#define MAXSIZE 100

typedef struct {
	int data;
	int cur;
}staticList, NodeList[MAXSIZE];

int initStaticList(NodeList staticList);  //初始化静态链表 

int mallocStaticListNode(NodeList staticList, int inChar); //插入元素 

int main(int argc, char *argv[]){
	
	NodeList staticList;
	
	initStaticList(staticList);
	
	
	for (int i =0; i < 105; i++) { //测试静态链表已满插入失败 
		printf("%d\n", i);
		mallocStaticListNode(staticList, i);
	}
	printf("%d\n", staticList[0].cur);
	
	return (0);
}

int initStaticList(NodeList staticList){
	for (int i = 0; i < MAXSIZE	- 1; i++){
		staticList[i].cur = i + 1;
	}
	staticList[MAXSIZE - 1].cur = 0;
	return 0;
} 

int mallocStaticListNode(NodeList staticList, int inChar){
	int freeCur;  //指向静态链表可用节点 
	freeCur = staticList[0].cur;
	
	if (freeCur == MAXSIZE-1) { //静态链表已满插入失败 
		printf("%s", "静态链表已满");
		return 0;
	} 
	
	staticList[freeCur].data = inChar; 
	staticList[0].cur = staticList[freeCur].cur;	
	return 0;
}
