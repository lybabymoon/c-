#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//P1008 ÈýÁ¬»÷
int main(){
	int a, b, c = 0;
	int i = 0;
	for (i = 192; i < 329; i++){
		a = i;
		b = 2 * i;
		c = i * 3;
		if ((a % 10 + a / 10 % 10 + a / 100 + b % 10 + b / 10 % 10 + b / 100 + c % 10 + c / 10 % 10 + c / 100 == 45)&&
			((a % 10) * (a / 10 % 10) * (a / 100) *( b % 10) *( b / 10 % 10) *( b / 100) * (c % 10 )* (c / 10 % 10) *( c / 100 )== 362880)){
               //45 = 1+2+3+4+5+6+7+8+9
			  //1*2*3*4*5*6*7*8*9 =362880
			printf("%d %d %d\n", a, b, c);
		}
	}
	system("pause");
	return 0;
}