#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main(){
	int l = 0;
	int num = 0;
	int a = 0, b = 0;
	int x;
	scanf("%d%d", &l, &num);                                         //输入马路长度L和区间数量num
	int view[10001] = { 0 };
	int count = 0;
	for (int i = 0; i <= l; i++){                   //对树进行初始化
		view[i] = 1;
	}
	while (num){
		scanf("%d%d", &a, &b);                         //输入没有树的区间
	                                               //将没有树的位置设为0
			for (x=a;x<=b; x++){
				view[x] = 0;
			}
		num--;
	}
	for (int i = 0; i <= l; i++){                  //统计树的数量
		if (view[i] == 1){
			count++;
		}
	}
	printf("%d\n", count);
	system("pause");
	return 0;
}