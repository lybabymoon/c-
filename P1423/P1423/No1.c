#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
	double x = 0.0;
	double sum = 0.0;
	int i = 0;
	scanf("%lf", &x);
	for (i = 0;;i++){
	        sum = sum + 2 * pow(0.98, i);
			if (sum > x){
				break;
			}
	}
	printf("%d\n", i+1);
	system("pause");
	return 0;
}