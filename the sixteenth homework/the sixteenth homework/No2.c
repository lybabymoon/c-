//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//int compare(const void *a,const void *b){
//	return (*(int*)a) > (*(int*)b);
//}
//void _swap(void *p1, void * p2, int size) {
//	int i = 0;     
//	for (i = 0; i< size; i++)     {
//            char tmp = *((char *)p1 + i); 
//			*((char *)p1 + i) = *((char *)p2 + i);      
//			*((char *)p2 + i) = tmp;
//	}
//}
//void bubble(void *arr, int num, int size, int(*compar)(void*, void*)){
//	int i, j;
//	int tmp = 0;
//	for (i = 0; i < num-1; i++){
//		for (j = 0; j < num - i - 1; j++){
//			if (compare((int *)arr + j*size, (int *)arr + (j + 1)*size) > 0) 
//			{ 
//				_swap((int *)arr + j*size, (int *)arr + (j + 1)*size, size); 
//			}
//		}
//	}
//	
//}
//int main(){
//	
//	int arr[10];
//	printf("请输入十个整数：\n");
//	for (int i = 0; i < 10; i++)
//		scanf("%d", &arr[i]);
//	bubble(arr, sizeof(arr) / sizeof(arr[0]), sizeof(int), compare);
//	for (int i = 0; i < 10; i++){
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}