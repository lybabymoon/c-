#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>
//strncmp
int my_strncmp(const char * src, const char * dst, size_t num){
	int ret = 0;
	assert(src != NULL);
	assert(dst != NULL);
	while (!(ret = *(unsigned char*)src - *(unsigned char*)dst) && *dst && num)
	{
		++src;
		++dst;
		num--;
	}
	if (ret < 0)
		ret = -1;
	else if (ret>0)
		ret = 1;
	return(ret);
}
int main(){
	char a[] = "abcffga";
	char b[] = "abcdfgb";
	printf("%d\n", my_strncmp(a, b, 1));
	//printf("%d\n", strncmp(a,b,4));
	system("pause");
	return 0;
}