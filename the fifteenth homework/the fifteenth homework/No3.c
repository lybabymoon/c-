#include<stdio.h>
#include<stdlib.h>
//Ä£ÄâÊµÏÖstrcat
int main1(){
	char a[50] = "abcde";
	char b[] = "qwer";
	char tmp = 0;
	int i = 0;
	int len = sizeof(b) / sizeof(b[0]);
	for (; i < 50; i++){
		if (a[i] == '\0')break;
	}
	for (int j = 0; j < len; j++,++i){
		a[i] = b[j];
}
	printf("%s", a);
	system("pause");
	return 0;
}