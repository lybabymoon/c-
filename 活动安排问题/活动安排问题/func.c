#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define N 11
int greedySelector(int s[], int f[],int * a){          // n Ϊ��� s ���ʼʱ��  f �����ʱ��
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
	int s[N] = { 0 };         //ÿ����Ŀ�ʼʱ��
	int f[N] = { 0 };         //ÿ����Ľ���ʱ��
	int a[N] = { 0 };         //������ѡ��Ļ
	printf("������ÿһ����Ŀ�ʼʱ��ͻ����ʱ�䣺\n");
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