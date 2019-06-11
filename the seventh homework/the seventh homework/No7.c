#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//memmove
void * my_memmove(void * dst,const void * src,size_t count){
	void *ret = dst;
	if (dst <= src || (char*)dst >= ((char*)src + count)){
		while (count--){
			*(char*)dst = *(char*)src;
			dst = (char*)dst + 1;
			src = (char*)src + 1;
		}
	}
	else{
		dst = (char*)dst + count - 1;
		src = (char*)src + count - 1;
		while (count--){
			*(char*)dst = *(char*)src;
			dst = (char*)dst - 1;
			src = (char*)src - 1;

		}
	}
	return(ret);
}
int main7(){
	char a[20] = "12345678";
	char b[20] = "qwert";
	/*memmove(a + 2,a , 5);
	puts(a);*/
	my_memmove(a + 2,a, 5);
	puts(a);
	system("pause");
	return 0;
}