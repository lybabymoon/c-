#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main(){
	FILE *fp = NULL;
	char c;
	fp = fopen("C:\\Users\\Î¢ÐÇ\\Desktop\\2.txt", "w");
	if (fp == NULL){
		printf("open fail\n");
		return 0;
	}
	//while ((c = fgetc(fp)) != EOF) //-1
	//{
	//	putchar(c);
	//}
	fclose(fp);
	fp = NULL;
	system("pause");
	return 0;
}