#include<stdio.h>
#include<stdlib.h>
//realloc  ��̬���ٿռ�
int main(){
	int *ptr = malloc(100);
	if (ptr != NULL){
		//ҵ����
	}
	else{
		exit(EXIT_FAILURE);
	}
	int *p = NULL;
	p = realloc(ptr, 1000);
	if (p != NULL){
		ptr = p;
	}
	free(ptr);
	system("pause");
	return 0;
}