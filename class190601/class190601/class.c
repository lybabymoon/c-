#include<stdio.h>
#include<stdlib.h>
//int *find(int(*p)[4], int n){  //这段代码有问题
//	int i, j;
//	for (i = 0; i < n; i++){
//		for (j = 0; j < 4; j++){
//			if (p[i][j] <= 60){
//				return p[i];
//			}
//		}
//	}
//}
void test(){
	int i;
	int *p = (int *)malloc(10 * sizeof(int));
	if (NULL == p){
		;
	}
	for (i = 0; i <= 10; i++){
		*(p + i) = i;
	}
	free(p);
}
void test1(){
	int *p = (int*)malloc(100);
	free(p);
	p = NULL;
	if (p!=NULL)
	free(p); // 重复释放
}
void GetMemory(char **p){
	*p = (char *)malloc(100);

}
void test3(){
	char *str = NULL;
	//str = 0
	GetMemory(&str);
	strcpy(str, "hello world");
	printf(str);
	free(str);
	str = NULL;

}
void test5(){
	int a = 0;    //动态存储
	static int b = 0;   //静态存储
	a++;
	b++;
	printf("a=%d b=%d\n", a, b);
}
struct S{
	int aa;     //4
	int arr[0];    //柔型数组  
};
struct SS{
	int aa;
	int *pa;
};
int main1(){
	int i;
	struct S *ps = (struct S*)malloc(sizeof(struct S) + sizeof(int)* 10);
	ps->aa = 20;
	for (i = 0; i < 10; i++)
		ps->arr[i] = i;
	for (i = 0; i < 10; i++)
		printf("%d ", ps->arr[i]);
	printf("\n");
	system("pause");
	return 0;
}
int main2(){
	int i;
	struct SS *p = (struct SS*)malloc(sizeof(struct SS));
	p->aa = 20;
	p->pa = NULL;
	p->pa = (int *)malloc(sizeof(int)* 10);
	for (i = 0; i < 10; i++)
		p->pa[i] = i;
	for (i = 0; i < 10; i++)
		printf("%d ", p->pa[i]);
	printf("\n");
	free(p->pa);
	p->pa = NULL;
	free(p);
	p = NULL;
	system("pause");
	return 0;
}