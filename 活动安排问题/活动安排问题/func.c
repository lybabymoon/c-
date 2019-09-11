#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define N 11
int greedySelector(int s[], int f[],int * a){          // n 为活动数 s 活动开始时间  f 活动结束时间
	int j = 1;
	a[1] = 1;
	int count = 1;
	for (int i = 2; i <= N; i++){
		if (s[i] >= f[j]){
			*(a+i) = 1;
			j = i;
			count++;
		}
		else{
			*(a + i) = 0;
		}
	}
	return count;
}
int main(){
	int s[N] = { 0 };         //每个活动的开始时间
	int f[N] = { 0 };         //每个活动的结束时间
	int a[N] = { 0 };         //储存所选择的活动
	printf("请输入每一个活动的开始时间和活动结束时间：\n");
	for (int i = 0; i < N; i++){
		scanf("%d%d",&s[i],&f[i]);
	}
	printf("%d\n",greedySelector(s, f, a));
	for (int i = 0; i < N; i++){
		if (a[i] == 1){
			printf("%d  ", i+1);
		}
		else{
			;
		}
	}
	system("pause");
    return 0;
}