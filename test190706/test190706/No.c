#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int mix_shopping(int a, int b){
	int mix = 0;
	int flower = 2;            //����Ǯ
	int bowel = 5;             //��ƿ��Ǯ
	int type1 = 5;             //һ��Ǯ
	int type2 = 10;            //����Ǯ
	int num1 = 0, num2 = 0;    //�ײ�һ���ײͶ�������
	int mix_flower = 0, mix_bowel = 0;   //��ʱ�������ٵ�Ǯ����ƿʱ�������ٵ�Ǯ
	num2 = b / 2;
	if (num2 <= a){
		num1 = (a - num2) / 3;
		mix_bowel = type2*num2 + b % 2 * bowel;
		mix_flower = type1*num1 + (a - num2) % 3 * flower;
	}
	else if (num2 > a){
		mix_bowel = type2*a + (b - 2 * a)*bowel;
		mix_flower = 0;
	}
	return mix = mix_bowel + mix_flower;
}
int main(){
	int a = 0, b = 0;
	printf("��������Ҫ����Ļ���������\n");
	scanf("%d", &a);
	printf("��������Ҫ����Ļ�ƿ��������\n");
	scanf("%d", &b);
	printf("%d\n", mix_shopping(a, b));
	system("pause");
	return 0;
}