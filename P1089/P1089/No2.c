#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main(){
	int price[12] = { 0 };
	int tmp = 0;
	int sum = 0;
	int sum1 = 0;
	int i = 0;
	for (int i = 0; i < 12; i++){
		scanf("%d", &price[i]);
	}
	
	
		for (i=0; i < 12; i++){
			tmp = 300 - price[i] + tmp;
			sum = sum + tmp / 100 * 100;
			tmp = tmp % 100;
			if (tmp < 0){
				printf("%d\n", -(i + 1));
				break;
			}
			else if (i == 11){
				sum1 = sum*0.2 + sum + tmp;
				printf("%d\n", sum1);
				break;
			}
		}
	system("pause");
	return 0;
}