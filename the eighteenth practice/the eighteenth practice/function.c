#include<stdio.h>
#include<stdlib.h>
//realloc  动态开辟空间
int main(){
	int *ptr = malloc(100);
	if (ptr != NULL){
		//业务处理
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