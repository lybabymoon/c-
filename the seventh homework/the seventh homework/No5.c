#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
//strcmp
int my_strcmp(const char * str1, const char * str2)
{ 
	int ret = 0;
	assert(str1);
	assert(str2);
	while (!(ret = *(unsigned char*)str1 - *(unsigned char*)str2) && *str1){
		str1++;
		str2++;
	}
	if (ret < 0)
		ret = -1;
	if (ret>0)
		ret = 1;
	return ret;
}
int main(){
	char a[] = "abcd";
	char b[] = "adef";
	printf("%d\n", my_strcmp(a, b));
	printf("%d\n", strcmp(a, b));
	system("pause");
	return 0;
}
