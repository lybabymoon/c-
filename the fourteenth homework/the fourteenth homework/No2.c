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
<<<<<<< HEAD
void left_remove(char * p, int k, int len){
	reserve(p, p + k - 1);               //��Ҫ��ת����������
	reserve(p + k, p + len - 1);         //��ʣ�����������
=======
void left_remove(char * p, int n, int len){
	reserve(p, p + n - 1);               //��Ҫ��ת����������
	reserve(p + n, p + len - 1);         //��ʣ�����������
>>>>>>> 7f4ec8ca41f0edfeb2294da65b5afca44cd6e3cf
	reserve(p, p + len - 1);             //������4�ַ�������
}

int main(){
<<<<<<< HEAD
	char arr1[] = "abcd";
	char arr2[] = "ABCD";
	int len = strlen(arr1);
	int number = 0;
	int k = 1;
	int count = 0;
	//��Ϊ����ʱ�õ���ָ��,����������ת�ַ�����ʱһ��һ�μ�
	for (int i = 0; i < len - 1; i++){                   
		
		left_remove(arr1, k, len);
		/*printf("��ת%d���ַ�,%s\n", i+1, arr1);*/
		number = strcmp(arr1, arr2);
		if (number==0){                      //arr1=arr2ʱ���1 �������0
			printf("1\n");
			break;
		}
		else{
			count++;
		}
		
	}
	if (count == 3){
		printf("0 \n");
	}
=======
	char arr1[] = "AABCD";
	char arr2[] = "BCDAA";
	int len = strlen(arr1);
	int k = 0;
	for (int k = 0; k < len - 1; k++){
		left_remove(arr1, k, len);
		printf("%s\n", arr1);
	}
	
>>>>>>> 7f4ec8ca41f0edfeb2294da65b5afca44cd6e3cf
	system("pause");
	return 0;
}