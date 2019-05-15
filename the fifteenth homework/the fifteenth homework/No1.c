//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//void find_num(int a[],int n){
//	int i, j,tmp = 0;
//	for (i = 0; i < n-1; i++){
//		for (j = 0; j < n - i - 1; j++){
//			if (a[j] > a[j + 1]){
//				tmp = a[j];
//				a[j] = a[j + 1];
//				a[j + 1] = tmp;
//			}
//		}
//	}
//	for (int x = 0; x < n; x+=2){
//		if (a[x] == a[x + 1]){
//			continue;
//		}
//		else if(a[x] != a[x+1]){
//			printf("%d\n", a[x]);
//			x++;
//		}
//	}
//}
//int main(){
//	int a[] = { 1, 2, 7, 1, 3, 5, 4,5, 6, 4, 6, 2, 7, 8 };
//	int len = sizeof(a)/sizeof(a[0]);
//	find_num(a, len);
//	system("pause");
//	return 0;
//}