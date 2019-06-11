//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//int money(int price[], int n){
//	int tmp = 0;
//	int sum = 0;
//	while (1){
//		for (int i = 0; i < n; i++){
//			tmp = 300 - price[i] + tmp;
//			sum = sum + tmp / 100 * 100;
//			tmp = tmp % 100;
//			if (tmp < 0){
//				return -(i+1);
//			}
//		}
//	}
//	return sum*0.2 + sum + tmp;
//}
//int main(){
//	int price[12] = { 0 };
//	for (int i = 0; i < 12; i++){
//		scanf("%d", &price[i]);
//	}
//	printf("%d\n", money(price,12));
//	system("pause");
//	return 0;
//}