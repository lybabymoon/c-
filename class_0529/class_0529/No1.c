#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
struct s2{
	char c1;         //4
	int c2;          //8
	double c3;       //8
	char c4[10];     //16
};
struct s3{
	struct s2 a;   //32
	int b;         //4
	char c[15];    //16
};
int main1(){
	
	printf("%d\n", offsetof(struct s3, a));
	printf("%d\n", offsetof(struct s3, b));
	printf("%d\n", offsetof(struct s3, c));
	printf("%d\n", sizeof(struct s3));
	system("pause");
	return 0;
}
//
#define  my_offsetof(s,m)  (size_t)&(((s *)0)->m)
