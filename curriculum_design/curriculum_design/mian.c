#define _CRT_SECURE_NO_WARNINGS
#include "design.h"
int main(){
	int a = 0, b = 0;
	printf("��������Ҫ����Ļ���������\n");
	scanf("%d", &a);
	printf("��������Ҫ����Ļ�ƿ��������\n");
	scanf("%d", &b);
	printf("%d\n",mix_shopping(a, b));
	system("pause");
	return 0;
}