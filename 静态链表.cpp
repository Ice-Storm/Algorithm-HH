#include <stdio.h>

#define MAXSIZE 100

typedef struct {
	int data;
	int cur;
}staticList, NodeList[MAXSIZE];

int initStaticList(NodeList staticList);  //初始化静态链表 

int mallocStaticListNode(NodeList staticList, int inChar); //插入元素 

int delStaticLIstNode(NodeList staticList, int i); //删除静态链表元素 

int main(int argc, char *argv[]){
	
	NodeList staticList;
	
	initStaticList(staticList);
	
	
	for (int i =0; i < 10; i++) { //测试静态链表已满插入失败 
		printf("%d\n", i);
		mallocStaticListNode(staticList, i);
	}
	delStaticLIstNode(staticList, 22);
	printf("%d\n", staticList[22].cur);
	
	
	
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
	staticList[0].data = 1;
	freeCur = staticList[0].cur;
	
	if (freeCur == MAXSIZE-1) { //静态链表已满插入失败 
		printf("%s", "静态链表已满");
		return 0;
	} 
	
	staticList[freeCur].data = inChar; 
	staticList[0].cur = staticList[freeCur].cur;	
	return 0;
}

int delStaticLIstNode(NodeList staticList, int i) {
	int temp = 0;
	int j = 0;
	int pre = 0;
	
	if (i < 1 || i > MAXSIZE - 1) {
		printf("插入位置越界");
		return 0;
	}
	
	while(staticList[j].cur) {
		pre = j;
		j++;
		if (j == i) {
			break;
		}	
	}
	
	/*
	 *  指针改变两次，一次是空闲指针，一次是数据指针 
	 *  应该分成两条线，分治 
	 */
	
	temp = staticList[0].cur;
	staticList[pre].cur =	staticList[i].cur;
	staticList[i].cur = temp;
 	staticList[0].cur = j;
} 
