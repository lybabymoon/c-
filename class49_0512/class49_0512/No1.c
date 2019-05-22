#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//指针
void swap3(int *a, int* b){
	int t = 0;
	t = *a;
	*a = *b;
	*b = t;

}

int main1(){
	int a = 0, b = 0;
	scanf("%d%d", &a, &b);
	printf("交换前a=%d,b=%d\n", a,b);
	swap3(&a, &b);
	printf("交换后a=%d,b=%d\n",a,b);
	system("pause");
	return 0;
}
int main2(){
	int a[3][4];
	printf("%d,%d,%d\n", a, a[0], &a[0][0]);
	printf("%d,%d\n", a, a + 1,&a[1]);
	system("pause");
	return 0;
}

int main3(){
	int a[] = { 1, 2, 3, 4, 5 };
	int b[3][5];
	int *p = (int*)(&a + 1);
	printf("%d\n", *(p - 1));
	system("pause");
	return 0;
}
int main4(){
	int a[] = { 7, 6, 8, 9, 0, 1, 2, 3, 4, 5 };
	int i, j, t = 0;
	int *p = a;
	int n = sizeof(a) / sizeof(a[0]);
	for (i = 0; i < n - 1; ++i){
		for (j = 0; j < n - i - 1; j++){
			if (a[j] > a[j + 1]){
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}
	for (p = a; p < a + 10; ++p){
		printf("%d ", *p);
	}
	printf("\n");
	system("pause");
	return 0;
}
int main5(){
	int a[10] = { 7, 6, 8, 9, 0, 1, 2, 3, 4, 5 };
     int n = sizeof(a) / sizeof(a[0]);
	 int *p = a, *q = a + 1, *end = a + n - 1;
	 for (p = a; p < a + n - 1; ++p){             //趟数
		 for (q = a; q < end; ++q){               //次数
			 if (*q < *(q + 1)){
				 int t = *q;
				 *q = *(q + 1);
				 *(q + 1) = t;
			 }
		 }
		 end--;
	 }
	 for (p = a; p < a + n; ++p)
		 printf("%d ", *p);
	 printf("\n");
	
	system("pause");
	return 0;
}
int main6(){
	int a[3][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 9, 8 };
	int *p = &a[0][0];
	int i;
	int j;
	for (i = 0; i < 3 ; i++){
		for (j = 0; j < 4; ++j){
			printf("%d", *(p + i * 4 + j));
		}
		putchar('\n');
	}


	system("pause");
	return 0;
}
int main7(){
	char b[10] = "1234";
	char *p = "12345";
	b[3] = 'k';
	/**p = 'k';*/
	puts(b);
	puts(p);

	system("pause");
	return 0;
}
int main8(){
	char a[] = "123";
	char b[] = "123";

	const char c[] = "123";
	const char d[] = "123";
	char *p = "123";
	char *q = "123";
	const char *pp = "123";
	const char *qq = "123";
	if (a == b)
		printf("a==n\n");
	if (c == d)
		printf("c==d\n");
	if (p == q)
		printf("p==q\n");
	if (pp == qq)
		printf("pp==qq\n");
	if (p == pp)
		printf("p==pp\n");
	system("pause");
	return 0;
}
int main9(){
	char a[] = "123";
	char b[] = "456";
	char temp[20];
	strcpy(temp, a);
	strcpy(a, b);
	strcpy(b, temp);
	puts(a);
	puts(b);

	system("pause");
	return 0;
}
int main11(){
	char *p = "123";
	char *q = "456";
	char *t;
	t = q;
	q = p;
	p = t;
	puts(p);
	puts(q);

	system("pause");
	return 0;
}
int main16(){
	int a[3][4] = { 1,  2,  3,  4,
		            5,  6,  7,  8, 
					9, 10, 11, 12 };
	int(*p)[4];           //数组指针
	int *q[3];            //指针数组
	int i;
	p = a;
	for (i = 0; i < 4; i++)
	{
		*p[i] = a[i];
		
	}
	for (i = 0; i < 3; i++){
		printf("%d\n", (*p[i]));
	}

	system("pause");
	return 0;
}
int sub(int a, int b){
	return a - b;
}
int add(int a, int b){
	return a + b;
}
int mul(int a, int b){
	return a * b;
}
int Div(int a, int b){
	if (b!=0)
	return a / b;
}
//转移表
int main12(){
	int(*p[])(int, int) = { add, sub, mul, Div };       //函数指针数组
	int len = sizeof(p) / sizeof(p[0]);
	for (int i = 0; i < len; i++){
		printf("%d\n\a", p[i](6, 2));
	}
    system("pause");
	return 0;
}
//把函数指针作为函数的参数
void test(int a, int b, int(*p)(int, int))   //add->p
{
	printf("%d\n", p(a, b));
}
void main13(){
	test(4, 7, add);
	system("pause");
}
//fn函数的返回值是个指针（指向函数（int xx（int，int））的指针）
int(*fn(int n))(int, int){         
	printf("fn:n=%d\n", n);
	return add;
}
void main14(){
	int value = fn(100)(3, 9);
	printf("%d\n", value);
	//int (*p)(int,int);
	/*p = fn(100);
	p(3, 9);*/
	system("pause");
}
//signal  不知道是什么动动  老师说下节课给看一下   理解了指针就没问题了


//数组指针的使用

	void  print_arr1(int arr[3][5], int row, int col){
		int i = 0;
		int j = 0;
		for (i = 0; i<row; i++)
		{
			for (j = 0; j<col; j++)
			{
				printf("%d ", arr[i][j]);
			}
			printf("\n");
		}
	}
	void print_arr2(int(*arr)[5], int row, int col)
	{
		int i = 0;
		int j = 0;
		for (i = 0; i<row; i++)
		{
			for (j = 0; j<col; j++)
			{
				printf("%d ", arr[i][j]);
			}
			printf("\n");
		}
	}
	int main() {
		int arr[3][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		print_arr1(arr, 3, 5);    
		//数组名arr，表示首元素的地址    
		//但是二维数组的首元素是二维数组的第一行    
		//所以这里传递的arr，其实相当于第一行的地址，是一维数组的地址    
		//可以数组指针来接收     
		print_arr2(arr, 3, 5);
		system("pause");
		return 0;
	}