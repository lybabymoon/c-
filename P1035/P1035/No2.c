#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main(){
	int n = 0;
	double	Sn = 0;
	int k = 0;
	scanf("%d", &k);
	for (n = 1; n <10000000; n++){
		Sn = Sn + 1.0 / n;
		if (Sn > k){
			printf("%d\n", n);
			break;
		}
	}
	system("pause");
	return 0;
}