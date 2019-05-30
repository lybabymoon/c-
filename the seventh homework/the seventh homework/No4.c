#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
//strchr 
char * my_strchr(const char *str,const char character){
	assert(str);
	char *s1 = NULL;
	while (*str){
		if (*str == character){
			s1 = str;
		}
		str++;
    }
	return s1;          //找到返回str，否则返回NULL
}
int main4(){
	char str[] = "This is a sample string";
	char * pch;
	printf("Looking for the 's' character in \" %s \"...\n", str);
	pch = my_strchr(str, 's');
	while (pch != NULL)
	{
		printf("found at %d\n", pch - str + 1);
		pch = my_strchr(pch + 1, 's');
	}
	/*printf("\" %s\" \n", my_strchr(str,'s'));*/
	system("pause");
	return 0;
}