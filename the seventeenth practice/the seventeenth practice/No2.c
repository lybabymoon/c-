#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//strncat
char * my_strncat(char * dest, const char * src, size_t num){
	assert(src != NULL);
	assert(dest != NULL);
	char * ret = dest;
	while (*dest){
		*dest++;
	}
	while (num)
	{
		*dest++ = *src++;
		num--;
	}
	return ret;
}
int main2(){
	char a[20] = "1234";
	char b[] = "56789";
	printf("%s\n", my_strncat(a, b, 2));
	system("pause");
	return 0;
}