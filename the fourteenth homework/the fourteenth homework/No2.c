#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//判断一个字符串是否为另外一个字符串旋转之后的字符串。
//例如：给定s1 = AABCD和s2 = BCDAA，返回1
//给定s1 = abcd和s2 = ACBD，返回0.
//
//AABCD左旋一个字符得到ABCDA
//AABCD左旋两个字符得到BCDAA
//
//AABCD右旋一个字符得到DAABC
void reserve(char *left, char *right){            //逆序输出函数
	while (left < right){
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
void left_remove(char * p, int n, int len){
	reserve(p, p + n - 1);               //将要旋转的内容逆序
	reserve(p + n, p + len - 1);         //将剩余的内容逆序
	reserve(p, p + len - 1);             //对整个4字符串逆序
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