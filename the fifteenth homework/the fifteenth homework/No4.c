#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//Ä£ÄâÊµÏÖstrcpy
int main(){
	char a[50];
	char b[] = "abcd";
	int len = sizeof(a) / sizeof(a[0]);
	for (int i = 0; i < len - 1; ++i){
		a[i] = b[i];
		if (b[i] == '\0')
			break;
	}
	printf("a=%s\n", a);
	printf("strcpy=%s\n", strcpy(a, b));


	system("pause");
	return 0;
}