#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//strncpy
char * my_strncpy(char * dest, const char * src, size_t num){
	assert(dest != NULL);
	assert(src != NULL);
	char * str1 = dest;
	char * str2 = (char*)src;
	while (num){
		*str1++ = *str2++;
		num--;
	}
	return dest;
}
int main1(){
	char a[] = "123456";
	char b[40] = { '\0' };
	
	printf("%s\n", my_strncpy(b, a, 4));
	system("pause");
	return 0;
}