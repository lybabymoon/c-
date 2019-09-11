#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
void reverseString(char* s, int sSize){
	assert(s);
	char* tmp = NULL;
	char *p = NULL;
	while (*s){
		*s++;
	}
	while (sSize){
		*tmp = *s--;
		*p++ = *tmp;
		sSize--;
	}
	printf("%s", *p);
}

int main(){
	char a[] = { 'a', 'b', 'c', 'd' };
	int sSize = sizeof(a);
	reverseString(a, sSize-1);;
	system("pause");
	return 0;
}