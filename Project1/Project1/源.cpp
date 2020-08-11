#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	/*int* p1 = NULL, *p2 = NULL, *p3 = NULL;

	p1 = (int*)malloc(10 * sizeof(int));
	if (!p1)
	{
		free(p1);
		p1 = nullptr;
	}
	cout << strlen(p1) << endl;
	p2 = (int*)calloc(10, sizeof(int));
	if (!p2)
	{
		free(p2);
		p2 = nullptr;
	}
	cout << sizeof(p2) << endl;
	p3 = (int*)realloc(p2, 20 * sizeof(int));
	if (!p3)
	{
		free(p3);
		p3 = nullptr;
	}
	cout << sizeof(p3) << endl;*/
	char* p = NULL;
	p = (char*)malloc(100);
	strcpy(p, "hello world");
	cout << p << endl;
	return 0;
}