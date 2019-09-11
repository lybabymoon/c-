#include "seqList.h"
int main(){
	SeqList test;
	SeqListInit(&test, 10);
	SeqListDestory(&test);
	system("pause");
	return 0;
}