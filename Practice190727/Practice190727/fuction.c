#include<stdio.h>
#include<stdlib.h>
#if 0
//day 1 £¨Ò».1£©
int main(){
	int a[] = { 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24 };
	int *q[4];
	int k;
	for (k = 0; k < 4; k++){
		q[k] = &a[k * 3];
	}
	printf("%d\n",q[3][1]);
	system("pause");
	return 0;
}
#endif
int main(){
	int i, j, a = 0;
	for (i = 0; i < 2; i++){
		for (j = 0; i < 4; j++){
			if (j % 2){
				break;
			}
			a++;
		}
		a++;
	}
	printf("%d\n", a);
	system("pause");
	return 0;
}
