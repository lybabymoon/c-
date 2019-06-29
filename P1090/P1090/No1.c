#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main(){    //只卖同一种
	int sum = 0;
	int mix = 0;
	int price1 = 0, price2 = 0, price3 = 0;   
	int type1 = 0, type2 = 0, type3 = 0;
	int a = 0, b = 0, c = 0;
	int type[3] = { 0 };
	int price[3] = { 0 };
	scanf("%d", &sum);
	for (int i = 0; i < 3; i++){
		scanf("%d%d", &type[i], &price[i]);
	}
	type1 = sum / type[0];
	a = sum % type[1] == 0 ? type1 : type1 + 1;
	price1 = a * price[0];
	type2 = sum / type[1];
	b = sum % type[1] == 0 ? type2 : type2 + 1;
	price2 = b * price[1];
	type3 = sum / type[2];
	c = sum % type[2] == 0 ? type3 : type3 + 1;
	price3 = c * price[2];
	if (price1>price2){
		mix = price2;
	}
	else if (price1 > price3){
		mix = price3;
	}
	else if (price2 > price3){
		mix = price3;
	}
	printf("%d\n", mix);
	system("pause");
	return 0;
}