//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
////malloc的用法
//int main(){
//	int num = 0;
//	scanf("%d", &num);
//	/*int arr[num] = { 0 };   */
//	//这样输入时错误的
//	int *ptr = NULL;
//	ptr = (int*)malloc(num*sizeof(int));
//	if (NULL != ptr){
//		int i = 0;
//		for (i = 0; i < num; i++){
//			*(ptr + i) = 0;
//		}
//	}
//	free(ptr);
//	ptr = NULL;
//	system("pause");
//	return 0;
//}