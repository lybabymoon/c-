#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void Bubble(int data[], int num){
	int i, j, tmp;
	for (i = 0; i<num - 1; i++)
	{
		for (j = 0; j<num - 1 - i; j++){
			if (data[j]>data[j + 1])
			{
				tmp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = tmp;
			}
		}
	}
}
int main(){
	int num[20] = { 0 };
	int n = 0;
	int i;
	int sum = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%d", num+i);
	}
	
	for (i = 0; i < n - 1; i++){
		Bubble(num + i, n-i);
		sum= num[i] + num[i + 1];
	}
	printf("%d", sum);
	system("pause");
	return 0;
}
