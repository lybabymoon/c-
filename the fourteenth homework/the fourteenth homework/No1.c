//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
////ʵ��һ�����������������ַ����е�k���ַ���
////ABCD����һ���ַ��õ�BCDA
////ABCD���������ַ��õ�CDAB
//void reserve(char *left, char *right){            //�����������
//	while (left < right){
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//void left_remove(char * p, int n, int len){
//	reserve(p, p + n - 1);               //��Ҫ��ת����������
//	reserve(p + n, p + len - 1);         //��ʣ�����������
//	reserve(p, p + len - 1);             //�������ַ�������
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
//	printf("��������ת�ַ��ĸ���:\n");
//	scanf("%d", &k);
//	while (k<1 || k>len - 1){
//		if (k == len){
//			printf("%s", arr);
//		}
//		else{
//			printf("�������,����������!\n");
//		}
//	}
//	left_remove(arr, k, len);
//	printf("%s\n", arr);
//	system("pause");
//	return 0;
//}