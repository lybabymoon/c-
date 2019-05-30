#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//ʵ��һ�����������������ַ����е�k���ַ���
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB
void reserve(char *left, char *right){            //�����������
	while (left < right){
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
void left_remove(char * p, int n, int len){
	reserve(p, p + n - 1);               //��Ҫ��ת����������
	reserve(p + n, p + len - 1);         //��ʣ�����������
	reserve(p, p + len - 1);             //�������ַ�������
}

int main(){
	char arr[] = "ABCDE";
	int len = strlen(arr);
	int k = 0;
	
	printf("��������ת�ַ��ĸ���:\n");
	scanf("%d", &k);
	int pos = len - k % len;
	/*while (k<1 || k>len - 1){
		if (k == len){
			printf("%s", arr);
		}
		else{
			printf("�������,����������!\n");
		}
	}*/
	left_remove(arr, k, pos);
	printf("%s\n", arr);
	system("pause");
	return 0;
}