#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdio.h>
int a[101], n;
void quicksort(int left, int right){
	int j, i, t, tmp;
	if (left > right){
		return;                   //如果左边大于右边退出循环
	}
	tmp = a[left];                //存放第一个基准的值
	i = left;
	j = right;
	while (i != j){              //如果left 和 right 不相交则开始循环j--。i++
		while (a[j] >= tmp && i < j)    //找到小于基准的数字
			j--;
		while (a[i] <= tmp && i < j)    //找到大于基准的数字
			i++;
		if (i < j){                    //交换大于基准的数字与小于基准的数字
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	a[left] = a[i];                   //将开头作为基准的数字和i停止--前的数字进行交换
	a[i] = tmp;
	quicksort(left, i - 1);           //递归调用排序 直到全部排完
	quicksort(i + 1, right);
}
int main(){
	int i, j, t;
	printf("请输入你要排序的数字的个数：\n");
	scanf("%d", &n);            
	printf("请输入你要排序的数字\n");
	for (i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	quicksort(1, n);
	for (i = 1; i <= n; i++)
		printf("%d", a[i]);
	getchar(); getchar();
	system("pause");
	return 0;
}