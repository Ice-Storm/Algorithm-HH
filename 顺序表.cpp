#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define MaxSize 20

int *ini(int *arr);

int *insArr(int *arr, int posi, int val);

int *delArr(int *arr, int posi);

int main()
{
	int *p;
	int *pResult;
	int arr[MaxSize];
	
	p = ini(arr);
	
	for (int i = 0; i < MaxSize; i++) {
		printf("%d\n", p[i]);
	}
	
	pResult = delArr(p, 15);
	
	for (int i = 0; i < MaxSize; i++) {
		printf("%d\n", pResult[i]);
	}
	
	return 0;
}

//初始化数组 
int *ini(int *arr) {
	int *parr;
	
	for (int i = 0; i < MaxSize-1; i++) {
		arr[i] = i;
	}
	
	arr[MaxSize-1] = -1;
	
	parr = arr;
	
	return parr;
	
}

//插入 
int *insArr(int *arr, int posi, int val) {
	int j;
	if (posi < 1 || posi >= MaxSize-1) {
		 printf("越界");
		 return (0);
	}
	
	for (j = MaxSize; j > posi; j--) {
		arr[j + 1] = arr[j];
		arr[j] = val;
	}
	
	return arr;
}

//删除 
int *delArr(int *arr, int posi) {
	if (posi < 1 || posi > MaxSize -1) {
		printf("越界");
	 return (0);
	}
	
	for (int i = posi; i < MaxSize; i++) {
		arr[i] = arr[i + 1];
		arr[i + 1] = -1;
	}
	return arr;
}