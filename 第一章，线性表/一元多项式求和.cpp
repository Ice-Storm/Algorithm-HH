#include <stdio.h>
#include <math.h>
#include <malloc.h>

struct Data {
	int index;//指数
	int frequency; //次数 
	struct Data *next;
};

//一元多项式求和 
int main() {
	int inIndex, inFrequency;
	int flag = 1, count = 1;
	Data *node, *p, *headPoint, *tempHeadPoint;
	Data head;
	
	headPoint = (&head);
	
	printf("%s\n", "输入r求和");
	
	//根据输入的系数和指数 生成链表 
	while (flag) {
		printf("%s", "输入多项式系数");
		scanf("%d", &inFrequency); 
		printf("%s", "输入多项式指数");
		scanf("%d", &inIndex); 
		
		if(inIndex == 0 && inFrequency == 0) {
			flag = 0;
			break;
		}

		node = (Data *)malloc(sizeof(Data));
		
		node->index = inIndex;
		node->frequency = inFrequency;
		node->next = NULL;
		
		if(count == 1) {
			headPoint->next = NULL;
			p = headPoint;
		}
		
		p->next = node;
		
		p = node;
		
		count++;
	}
	
	tempHeadPoint = headPoint;
	
	while(tempHeadPoint->next){
		printf("\n%d ---- 节点数据域 ", tempHeadPoint->next->frequency);
		printf("\n%d ---- 节点数据域 ", tempHeadPoint->next->index);
		printf("\n%p ---- 节点本身地址 ", tempHeadPoint->next);
		tempHeadPoint = tempHeadPoint->next;
	}
	
	//求和
	int x = 3;
	float temp, sum;
	
 	while(headPoint->next){
		temp = headPoint->next->frequency * pow(x, headPoint->next->index);	
		
		sum +=temp;
		
		headPoint = headPoint->next;
	}
	
	printf("结果 -- \n%lf", sum); 
	
	return (0);
	 
}
 