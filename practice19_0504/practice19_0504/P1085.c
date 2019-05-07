#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main(){
	int a[7] = { 0 }, b[7] = { 0 }, c[7] = { 0 };
	int max = 0;
	int count = 0;
	int j = 0;
	for (int i = 0; i < 7; i++){
		scanf("%d %d",&a[i],&b[i]);
		c[i] = a[i] + b[i];
		if (c[i]>8){
		count++;
		if (c[i] > max){
			max = c[i];
		}
		}
	}
	if (count != 0){
		for (j = 0; j < 7; j++){
			if (c[j] == max){
				printf("%d\n", j+1);
				break;
			}
		}
	}
	else{
		printf("%d\n", count);
	}
	
	system("pause");
	return 0;
}