#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main(){

	int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0,sum = 0;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	e = c - a;
	f = d - b;
	sum = e * 60 + f;
	f = sum % 60;
	e = (sum - f) / 60;
	printf("%d %d\n", e, f);
	system("pause");
	return 0;
}