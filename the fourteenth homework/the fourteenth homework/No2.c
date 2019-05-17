//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
////判断一个字符串是否为另外一个字符串旋转之后的字符串。
////例如：给定s1 = AABCD和s2 = BCDAA，返回1
////给定s1 = abcd和s2 = ACBD，返回0.
////
////AABCD左旋一个字符得到ABCDA
////AABCD左旋两个字符得到BCDAA
////
////AABCD右旋一个字符得到DAABC
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
//    reserve(p, p + len - 1);             //对整个4字符串逆序
//}
//
//int main(){
//
//	char arr1[] = "abcd";
//	char arr2[] = "ABCD";
//	int len = strlen(arr1);
//	int number = 0;
//	int k = 1;
//	int count = 0;
//	//因为逆序时用的是指针,所以自增旋转字符个数时一次一次加
//	for (int i = 0; i < len - 1; i++){                   
//		
//		left_remove(arr1, k, len);
//		/*printf("旋转%d个字符,%s\n", i+1, arr1);*/
//		number = strcmp(arr1, arr2);
//		if (number==0){                      //arr1=arr2时输出1 否则输出0
//			printf("1\n");
//			break;
//		}
//		else{
//			count++;
//		}
//		
//	}
//	if (count == 3){
//		printf("0 \n");
//	}
//	system("pause");
//	return 0;
//}
