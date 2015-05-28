#include <stdio.h>

struct list {
	int data;
	struct list *next;
};

// i ���ɻ�λ�� �� n ���ɽڵ����
struct list *createCirList(int i, int n);

int judge(struct list *head);

int main(int argc, char *argv[])
{

	struct list *head;
	head = createCirList(3, 5);

	judge(head);

	return 0;
}

struct list *createCirList(int i, int n) {
	struct list *head, *cur, *node;
	struct list static *temp;
	int j;

	if (i < 0 || i > n) {
		printf("���ɻ�����Խ��");
		return 0;
	}

	cur = head;

	//�����л�����
	for (j = 1; j <= n; j++){
		node = (struct list*)malloc(sizeof(struct list));

		node->data = j;
		node->next = NULL;

		cur->next = node;
		cur = node;

		if (j == i) {
			temp = cur;
		}
	}

	cur->next = temp;

	return head;
}

int judge(struct list *head) {
	struct list *slowP, *quickP, *cur;

	int quickCount = 0, slowCount = 0;

	slowP = head->next;
 	quickP = head->next;

	while(quickP->next) {

		cur = quickP;
		quickP = quickP->next;
		quickCount++;
		printf("\n��ָ��λ��%d", quickCount);

		while(1) {

			slowP = slowP->next;
			slowCount++;
			printf("\n��ָ���ƶ�%d", slowCount);


			if(slowP == quickP && quickCount != slowCount) {
				printf("\n\n���ڵ�%d���ڵ�\n", slowP->data);
				return 0;
			} else if(slowP == quickP && quickCount == slowCount) {
				printf("\n��ָ������%d��\n\n", slowP->data);
				slowCount = 0;
				slowP = head->next;
				break;
			}

		}
	}

	return 0;
}








