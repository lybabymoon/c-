#include "double_linked_list.h"
void test(){
	List list;
	ListInit(&list);
	ListPushBack(&list, 7);
	ListPushBack(&list, 6);
	ListPushBack(&list, 5);
	ListPushBack(&list, 4);
	ListPrint(&list);           //ListFind(&list, 5)
	ListPrint(ListFind(&list, 5));
}
int main(){
	test();
	system("pause");
	return 0;
}