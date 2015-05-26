#include <stdio.h>

#define MAXSIZE 100

typedef struct {
	int data;
	int cur;
}staticList, NodeList[MAXSIZE];

int initStaticList(NodeList staticList);  //��ʼ����̬���� 

int mallocStaticListNode(NodeList staticList, int inChar); //����Ԫ�� 

int delStaticLIstNode(NodeList staticList, int i); //ɾ����̬����Ԫ�� 

int main(int argc, char *argv[]){
	
	NodeList staticList;
	
	initStaticList(staticList);
	
	
	for (int i =0; i < 10; i++) { //���Ծ�̬������������ʧ�� 
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
	int freeCur;  //ָ��̬������ýڵ� 
	staticList[0].data = 1;
	freeCur = staticList[0].cur;
	
	if (freeCur == MAXSIZE-1) { //��̬������������ʧ�� 
		printf("%s", "��̬��������");
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
		printf("����λ��Խ��");
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
	 *  ָ��ı����Σ�һ���ǿ���ָ�룬һ��������ָ�� 
	 *  Ӧ�÷ֳ������ߣ����� 
	 */
	
	temp = staticList[0].cur;
	staticList[pre].cur =	staticList[i].cur;
	staticList[i].cur = temp;
 	staticList[0].cur = j;
} 
