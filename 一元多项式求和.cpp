#include <stdio.h>
#include <math.h>
#include <malloc.h>

struct Data {
	int index;//ָ��
	int frequency; //���� 
	struct Data *next;
};

//һԪ����ʽ��� 
int main() {
	int inIndex, inFrequency;
	int flag = 1, count = 1;
	Data *node, *p, *headPoint, *tempHeadPoint;
	Data head;
	
	headPoint = (&head);
	
	printf("%s\n", "����r���");
	
	//���������ϵ����ָ�� �������� 
	while (flag) {
		printf("%s", "�������ʽϵ��");
		scanf("%d", &inFrequency); 
		printf("%s", "�������ʽָ��");
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
		printf("\n%d ---- �ڵ������� ", tempHeadPoint->next->frequency);
		printf("\n%d ---- �ڵ������� ", tempHeadPoint->next->index);
		printf("\n%p ---- �ڵ㱾���ַ ", tempHeadPoint->next);
		tempHeadPoint = tempHeadPoint->next;
	}
	
	//���
	int x = 3;
	float temp, sum;
	
 	while(headPoint->next){
		temp = headPoint->next->frequency * pow(x, headPoint->next->index);	
		
		sum +=temp;
		
		headPoint = headPoint->next;
	}
	
	printf("��� -- \n%lf", sum); 
	
	return (0);
	 
}
 