// first.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void bubble_sort(int arr[], int len) {
    int i, j, temp;
    for (i = 0; i < len - 1; i++)
        for (j = 0; j < len - 1 - i; j++)
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
	printf("ð�������\n");
	for (i = 0; i < 5; i++)
		printf("%d\t", arr[i]);
	printf("\n");
}
void selection_sort(int a[], int len) 
{
    int i,j,temp;
 
    for (i = 0 ; i < len - 1 ; i++) 
    {
        int min = i;                  // ��¼��Сֵ����һ��Ԫ��Ĭ����С
        for (j = i + 1; j < len; j++)     // ����δ�����Ԫ��
        {
            if (a[j] < a[min])    // �ҵ�Ŀǰ��Сֵ
            {
                min = j;    // ��¼��Сֵ
            }
        }
        if(min != i)
        {
            temp=a[min];  // ������������
            a[min]=a[i];
            a[i]=temp;
        }
        /* swap(&a[min], &a[i]);  */   // ʹ���Զ��庯�����Q
    }
	printf("ѡ�������\n");
	for (i = 0; i < 5; i++)
		printf("%d\t", a[i]);
	printf("\n");
}
int main() {
    int arr[5];
	int a=0;
	int i=0;
	char s;
	char b;
	do{
		printf("�����������ݷ�ʽѡ��\n");
		printf("�Զ����루A��a�������ֶ����루M��m����");
		b = getchar();
		if(b=='A' || b=='a'){
			srand((unsigned)time(NULL));
			for (i = 0; i < 5; i++) {
				
				arr[i] = rand()%101;
			}
		}else{
			printf("������5��������\n");
			for(i=0;i<5;i++){
				printf("��%d����",i+1);
				scanf("%d",&arr[i]);
			}
		}
		printf("����ǰ��\n");
		for (i = 0; i < 5; i++)
			printf("%d\t", arr[i]);
		printf("\n");
		bubble_sort(arr, 5);
		selection_sort(arr, 5);
		printf("����Q��q�����������������ַ�������һ������");
		s=getchar();
		s=getchar();
	}while(s!='Q' && s!= 'q');
    return 0;
}