#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
//strstr
char * my_strstr(const char * str1, const char * str2){
	 assert(str1);
	 assert(str2);
	 char *p =(char*) str1;
	 char *s1 = (char*)str1;
	 char *s2 = (char*)str2;
	 
	 if (str2 == '\0')
		return NULL;
	 while (*p){
		s1 = p;             //回到s2++之前的位置
		s2 = (char*)str2;   //重新回到开头的意思
		while (*s1 && *s2 && (*s1 == *s2))
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0'){
			return p;
		}
		p++;
	}
	return NULL;
}
int main3(){
	char a[] = "abdcsfgggg";
	char b[] = "dcsf";
	char *p = NULL;
	if (p = my_strstr(a, b))
		puts(p);
	system("pause");
	return 0;
}