#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main(){
	int x = 0, n = 0;
	int sum = 0;
	scanf("%d%d", &x,&n);  //x从周几开始

   //1.判断
   //2.赋值
	for (int i = 0; i < n; i++){
		if (x == 8){
			x = 1;
		}
		if (x>0 && x < 6){
			sum = 250 + sum;
		}
	   
		x++;
	}
	printf("%d\n", sum);
	system("pause");
	return 0;
}