#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main(){
	int sum = 0;
	scanf("%d", &sum);
	double price = 0.0;
	if (sum < 150){
		price = sum * 0.4463;
	}
	else if (sum >= 151 && sum <= 400){
		price = sum * 0.4663;
	}
	else if (sum >= 401){
		price = sum * 0.5663;
	}
	printf("%5.1f", price);
	system("pause");
	return 0;
}