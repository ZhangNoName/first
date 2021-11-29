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
	printf("冒泡排序后：\n");
	for (i = 0; i < 5; i++)
		printf("%d\t", arr[i]);
	printf("\n");
}
void selection_sort(int a[], int len) 
{
    int i,j,temp;
 
    for (i = 0 ; i < len - 1 ; i++) 
    {
        int min = i;                  // 记录最小值，第一个元素默认最小
        for (j = i + 1; j < len; j++)     // 访问未排序的元素
        {
            if (a[j] < a[min])    // 找到目前最小值
            {
                min = j;    // 记录最小值
            }
        }
        if(min != i)
        {
            temp=a[min];  // 交换两个变量
            a[min]=a[i];
            a[i]=temp;
        }
        /* swap(&a[min], &a[i]);  */   // 使用自定义函数交換
    }
	printf("选择排序后：\n");
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
		printf("排序生成数据方式选择：\n");
		printf("自动输入（A或a）或者手动输入（M或m）：");
		b = getchar();
		if(b=='A' || b=='a'){
			srand((unsigned)time(NULL));
			for (i = 0; i < 5; i++) {
				
				arr[i] = rand()%101;
			}
		}else{
			printf("请输入5个整数：\n");
			for(i=0;i<5;i++){
				printf("第%d个：",i+1);
				scanf("%d",&arr[i]);
			}
		}
		printf("排序前：\n");
		for (i = 0; i < 5; i++)
			printf("%d\t", arr[i]);
		printf("\n");
		bubble_sort(arr, 5);
		selection_sort(arr, 5);
		printf("输入Q或q结束程序，输入任意字符继续下一次排序：");
		s=getchar();
		s=getchar();
	}while(s!='Q' && s!= 'q');
    return 0;
}