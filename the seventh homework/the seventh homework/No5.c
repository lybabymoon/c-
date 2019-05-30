#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
//strcmp
int my_strcmp(const char * str1, const char * str2)
{
	assert(str1);
	assert(str2);
	while (*str1){
		if (*str1 == *str2){
			str1++;
			str2++;
		}
		else if (*str1 != *str2){
			return (int*)*str1 - (int*)*str2;
		}

	}
	return 0;
}
int main5(){
	char a[] = "abcd";
	char b[] = "cdef";
	printf("%d\n", my_strcmp(a, b));
	printf("%d\n", strcmp(a, b));
	system("pause");
	return 0;
}
