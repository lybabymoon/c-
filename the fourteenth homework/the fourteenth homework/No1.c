//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
////实现一个函数，可以左旋字符串中的k个字符。
////ABCD左旋一个字符得到BCDA
////ABCD左旋两个字符得到CDAB
//void reserve(char *left, char *right){            //逆序输出函数
//	while (left < right){
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//void left_remove(char * p, int n, int len){
//	reserve(p, p + n - 1);               //将要旋转的内容逆序
//	reserve(p + n, p + len - 1);         //将剩余的内容逆序
//	reserve(p, p + len - 1);             //对整个字符串逆序
//}
<<<<<<< HEAD
//int main(){
//	char arr[] = "AABCD";
=======
//int main1(){
//	char arr[] = "ABCD";
>>>>>>> 7f4ec8ca41f0edfeb2294da65b5afca44cd6e3cf
//	int len = strlen(arr);
//	int k = 0;
//	printf("请输入旋转字符的个数:\n");
//	scanf("%d", &k);
//	while (k<1 || k>len - 1){
//		if (k == len){
//			printf("%s", arr);
//		}
//		else{
//			printf("输入错误,请重新输入!\n");
//		}
//	}
//	left_remove(arr, k, len);
//	printf("%s\n", arr);
//	system("pause");
//	return 0;
//}