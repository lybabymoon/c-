#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main(){
	long n = 0, x = 0,tmp = 0,y=0;                                                                                                                                           //1��n x�����˶��ٴ�
	int time = 0;
	scanf("%d%d", &n, &x);
	for (long i = 1; i <= n; i++){
		y = i;                   //Ϊ��ʹi��ֵ���ı�ʽ��丳ֵ�� y
		while (y != 0){
			tmp = y % 10;           //��ʱtmp ����iÿһλ��ֵ������x�Ƚ�
			y = y / 10;             //��i�Ƶ���һλ
			if (tmp == x){
				time++;
			}
		}
	}
	printf("%d\n", time);
	system("pause");
	return 0;
}