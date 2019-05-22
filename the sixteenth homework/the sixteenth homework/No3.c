#include<stdio.h>
#include<stdlib.h>
int cmp(const void * p1, const void * p2){
	return (*(int*)p1 > *(int *)p2);
}
int cmp2(const void * p1, const void * p2){
	return (*(char*)p1 > *(char *)p2);
}
int cmp3(const void * p1, const void * p2){
	return (*(float *)p1 > *(float *)p2);
}
void swap1(void *p1, void *p2, int size){
	int i = 0;
	for (i = 0; i < size; i++){
		char tmp = *((char *)p1 + i);
		*((char *)p1 + i) = *((char*)p2 + i);
		*((char *)p2 + i) = tmp;
	}
}
void bubble(void *base, int count, int size, int(*cmp)(void*, void*)){
	int i, j;
	
	for (i = 0; i < count - 1; i++){
		for (j = 0; j < count - i - 1; j++){
			if (cmp((char *)base + j*size, (char *)base + (j + 1)*size) > 0)
			{
				swap1((char *)base + j*size, (char *)base + (j + 1)*size, size);
			}
		}
	}

}
int main(){

	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	char arr2[] = { 'b', 'd', 'c', 'a', 'e' };
	float arr3[] = {2.1, 1.5, 3.0, 4.1 };
	/*printf("请输入十个整数：\n");
	for (int i = 0; i < 10; i++)
		scanf("%d", &arr[i]);*/
	bubble(arr, sizeof(arr)/sizeof(arr[0]), sizeof(int),cmp);
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	bubble(arr2, sizeof(arr2) / sizeof(arr2[0]), sizeof(char), cmp2);
	for (int i = 0; i < sizeof(arr2) / sizeof(arr2[0]); i++){
		printf("%c ", arr2[i]);
	}
	printf("\n");
	bubble(arr3, sizeof(arr3) / sizeof(arr3[0]), sizeof(float), cmp3);
	for (int i = 0; i < sizeof(arr3) / sizeof(arr3[0]); i++){
		printf("%f ", arr3[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}