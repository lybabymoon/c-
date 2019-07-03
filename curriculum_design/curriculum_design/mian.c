#define _CRT_SECURE_NO_WARNINGS
#include "design.h"
int main(){
	int a = 0, b = 0;
	printf("请输入你要购买的花的数量：\n");
	scanf("%d", &a);
	printf("请输入你要购买的花瓶的数量：\n");
	scanf("%d", &b);
	printf("%d\n",mix_shopping(a, b));
	system("pause");
	return 0;
}