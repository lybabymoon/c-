#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main(){
	long n = 0, x = 0,tmp = 0,y=0;                                                                                                                                           //1到n x出现了多少次
	int time = 0;
	scanf("%d%d", &n, &x);
	for (long i = 1; i <= n; i++){
		y = i;                   //为了使i的值不改变故将其赋值给 y
		while (y != 0){
			tmp = y % 10;           //临时tmp 保存i每一位的值方便与x比较
			y = y / 10;             //将i移到下一位
			if (tmp == x){
				time++;
			}
		}
	}
	printf("%d\n", time);
	system("pause");
	return 0;
}