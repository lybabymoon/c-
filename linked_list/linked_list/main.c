#include "linkedList.h"
void listtest(){
	SList test;
	SListInit(&test);
	SListPushFront(&test, 4);
	SListPushFront(&test, 1);
	SListPushFront(&test, 3);
	SListPushFront(&test, 2);
	SListPushFront(&test, 7);
	SListPrint(&test);

	SListPopFront(&test);
	SListPrint(&test);
}
int main(){
	listtest();
	system("pause");
	return 0;
}