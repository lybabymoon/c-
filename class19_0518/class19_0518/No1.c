#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main1(){
	char arr[] = { 'a', 'b' };
	printf("%d\n", strlen(arr));
	printf("%d\n", strlen(arr + 0)); 
	printf("%d\n", strlen(*arr));
	printf("%d\n", strlen(arr[1]));
	printf("%d\n", strlen(&arr));
	printf("%d\n", strlen(&arr + 1));
	printf("%d\n", strlen(&arr[0] + 1));
	system("pause");
	return 0;
}
 int main2() 
{     
	int a[3][2] = { (0, 1), (2, 3), (4, 5) };
    int *p;
    p = a[0];      //&a[0][0]
    printf("%d", p[0]);          //*(p+0)
    system("pause");
    return 0;
}
 int main3(){
	 char a = -128;
	 //10000000
	 //10000000 00000000 00000000 10000000
	 //11111111 11111111 11111111 01111111
	 //11111111 11111111 11111111 10000000
	 char b = -127;
	 //01111111
	 //10000000 00000000 00000000 01111111
	 //11111111 11111111 11111111 10000000
	 //11111111 11111111 11111111 10000001
	 char c = -126;
	 //01111110
	 //10000000 00000000 00000000 01111110
	 //11111111 11111111 11111111 10000001
	 //11111111 11111111 11111111 10000010
	 printf("%d %d %d\n", a, b, c);
	 printf("%u %u %u\n", a, b, c);
	 system("pause");
	 return 0;
 }

 //指针回调函数
 int cmp(const void *p1,const void *p2){
	 return  (*(int*)p1 - *(int *)p2);
 }
 int main4(){
	 int arr[] = { 6, 5, 7, 8, 9, 0, 1, 2, 3, 4, 5 };
	 int n = sizeof(arr) / sizeof(arr[0]);
	 int i;
	 qsort(arr, n, sizeof(int), cmp);    //函数指针
	 for (i = 0; i < n; i++){
		 printf("%d", arr[i]);
	 }
	 printf("\n");
	 system("pause");
	 return 0;
 }

 //数组指针的用法1
 int main5(){
	 int b[10];
	 int a[3][4] = { 1, 2, 3, 4,
		             5, 6, 7, 8, 
		             9, 10, 11, 12 };
	 /*printf("%d %d\n", a, *a);
	 printf("%d %d\n", a, a + 1);
	 printf("%d %d\n", *a, *a + 1);
	 printf("%d %d\n", *(a + 1), a[1]);*/
	 /*printf("%d %d %d %d %d\n", **a, *(*a + 1), *(*(a + 1 + 1)), *(*(a + 1) + 3),*(*a+1+1));*/
	 //                        1       2            9                 8               3
	
	 int(*p)[4];
	 int i, j;
	 p = a;
	 for (i = 0; i < 3; i++){
		 for (j = 0; j < 4; j++){
			 printf("%2d\t", *(*(p + i) + j));   //p[i][j]
		 }
		 printf("\n");
	 }


	 system("pause");
	 return 0;
 }


 //数组指针的用法2
 int main6(){
	 int b[10];
	 int a[3][4] = { 1, 2, 3, 4,
		 5, 6, 7, 8,
		 9, 10, 11, 12 };
	 int(*p)[4];    //数组指针
	 int i, j;
	 p = a;
	 //注意指针变量的当前值
	 for (p = a; p < a + 3; p++){
		 for (j = 0; j < 4; j++){
			 printf("%2d\t", *(*p + j));
		 }
		 printf("\n");
	 }
	 //执行完上述代码后p的指已经发生变化
	 p = a;
	 system("pause");
	 return 0;
 }
 
 //数组指针一般用来操作二维数组
 //数组指针的用法和二维数组数组名一样
 //数组名不能为左值

 int main7(){
	 int arr[3][4];
	 int(*p)[4];   //数组指针  指向数组的指针
	 int *q[3];    //指针数组  存放指针的数组
	 p = arr;
	 int i;
	 for (i = 0; i < 3; i++){
		 q[i] = arr[i];
	 }
	 //a  ->(int *)[4]
	 //a[1]  ->(int *)[4]
	 //a[1][0]  ->int
	 system("pause");
	 return 0;
 }
 void test(const char* str) { 
	 printf("%s\n", str); 
 } 
 int main8() {  
	  
	 //函数指针pfun  
	 void (*pfun)(const char*) = test;
	 //函数指针的数组pfunArr 
	 void(*pfunArr[5])(const char* str); 
	 pfunArr[0] = test; 
	 //指向函数指针数组pfunArr的指针ppfunArr  
	 void (*(*ppfunArr)[10])(const char*) = &pfunArr; 
	 system("pause");
	 return 0; 
 }
 int main9(){
	 int b[10];
	 int a[3][4] = { 1, 2, 3, 4,
		 5, 6, 7, 8,
		 9, 10, 11, 12 };
	 printf("%d,%d,%d,%d,%d\n", **a, *(*a + 1), *(*(a + 1 + 1)), *(*a + 1 + 1), *(*(a + 1) + 3));
	                        //     1       2            9                3               8
	 system("pause");
	 return 0;
 }
 int main10(){
	   char *name[5] = { "lili", "zhangsan", "asfassfa", "fddf", "qwerqqwer" };
	   printf("%c\n", *name[0]);
	 //char(*name)[5] = { "saddsa", "sadsadasdsa", "sdsadafefef", "fddafqsafsa","asdafewwf" };   这个是错误的
	   char *tmp = NULL;
	   char *p = "111";
	   char *q = "222";
	    tmp = p;
		p = q;
		q = tmp;
		printf("%s %s\n", p, q);
	   system("pause");
	   return 0;
 }
 int main11(){
	 int  a = 5;
	 int *p = &a;
	 int **q = &p;
	 printf("%d %d %d\n", a, *p, **q);
	 system("pause");
	 return 0;
 }
 int main(){
	 int a[5] = { 1, 2, 3, 4, 5 };
	 int *q[5] = { &a[0], &a[1], &a[2], &a[3], &a[4] };
	 int **p = q;
	 int i;

	 for (i = 0; i < 5; i++){
		 //printf("%d", *q[i]);
		 printf("%d ", *(*(q + i)));     //**(q+i)
	 }
	 putchar('\n');
	 for (p = q; p < q + 5; p++){
		 printf("%d ", **p);
	 }
	 putchar('\n');
	 system("pause");
	 return 0;
 }