#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include<Windows.h>
int Factor(int n){
	int ret = 1;
	for (int i = 1; i <= n; ++i){
		ret *= i;
	}
	return ret;
}
int main(){

	//char str1[] = "zby I LOVE YOU!";
	//char str2[] = "###############";
	//int left = 0;
	//int right = strlen(str1) - 1;
	//while (left <= right){
	//	printf("%s\n", str2);
	//	str2[left] = str1[left];
	//	str2[right] = str1[right];
	//	++left;
	//	--right;
	//	Sleep(300);
	//	system("cls");
	//}



    //int sum = 0;
	//for (int i = 1; i <= 10; i++){
	//	sum += Factor(i);
	//}
	//printf(" %d", sum);



	//int i = 0;
	//for(;i<3;i++){
	//	printf("请输入密码 :");
	//	char password[20] = "";
	//	scanf("%s", password);
	//	// ==比较俩个字符串是不是在相同的地址上 .
	//	if (strcmp(password, "abcdef") == 0){
	//		printf("登陆成功\n");
	//		break;
	//	}
	//	else{
	//		printf("面膜错误\n");
	//	}
	//}
	//if (i ==3){
	//	printf("禁止登陆.\n");
	//}

	//int i = 0;
	//int arr[4] = { 9, 5, 2, 7 };
	//int to_find = 20;
	//for (; i < 4; ++i){
	//	if (arr[i] == to_find){
	//		printf("找到了!\n");
	//		break;
	//	}
	//}
	//if (i == 4){
	//	printf("没找到!\n"); 
	//}







	//二分查找 前提有序数组
	int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	
	int to_find ;
	scanf("%d", &to_find);
	int middle = 0;
	//left right 待查找区间
	int left = 0;
	int right = sizeof(arr)/sizeof(arr[0]) - 1;
	while (left <= right){
		//这个循环条件表示待查找区间中有元素要查找
		int mid = (left + right) / 2;
		//  c语言中除法取整"/"
		if (to_find < arr[mid]){
			right = mid - 1;

		}
		else if (to_find>arr[mid]){
			left = mid + 1;
		}
		else{
			break;
		}
	}
		if (left <= right){
			printf("find\n");
		}
		else{
			printf("can't find");
		}

	system("pause");
	return 0;
}