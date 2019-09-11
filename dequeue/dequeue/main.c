#include"dequeue.h"
int main(){
	Dequeue test;
	dequeueInit(&test);
	printf("%d\n", dequeuePush(&test, 1));
	printf("%d\n", dequeuePush(&test, 1));
	printf("%d\n", dequeuePush(&test, 1));
	printf("%d\n", dequeuePush(&test, 1));
	printf("%d\n", dequeuePush(&test, 1));
	system("pause");
	return 0;
}