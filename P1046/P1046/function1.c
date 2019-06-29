#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main(){
	int high[10] = { 0 };
	int max_high = 0;
	int count = 0;
	for (int i = 0; i < 10; i++){
		scanf("%d", &high[i]);
	}
	scanf("%d", &max_high);
	max_high = max_high + 30;
	for(int i =0;i<10;i++){
		if (high[i] <= max_high){
			count++;
		}
	}
	printf("%d\n", count);
	system("pause");
	return 0;
}