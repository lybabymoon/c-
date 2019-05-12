#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//�ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
//���磺����s1 = AABCD��s2 = BCDAA������1
//����s1 = abcd��s2 = ACBD������0.
//
//AABCD����һ���ַ��õ�ABCDA
//AABCD���������ַ��õ�BCDAA
//
//AABCD����һ���ַ��õ�DAABC
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
	reserve(p, p + len - 1);             //������4�ַ�������
}

int main(){
	char arr1[] = "AABCD";
	char arr2[] = "BCDAA";
	int len = strlen(arr1);
	int k = 0;
	for (int k = 0; k < len - 1; k++){
		left_remove(arr1, k, len);
		printf("%s\n", arr1);
	}
	
	system("pause");
	return 0;
}