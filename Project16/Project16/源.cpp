#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;
#include <string.h>
char* AllocMemory(char* p)
{
	p = (char*)malloc(100);
	return p;
}
void Test(void)
{
	char* str = NULL;
	str = AllocMemory(str);
	strcpy(str, "hello world");
	cout << str << endl;
}
int main() {
	
	Test();
	return 0;
}