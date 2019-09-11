#ifndef _DEQUEUE_H_
#define _DEQUEUE_H_
#include<stdio.h>
#include<stdlib.h>
#define QUEUENUM 5
typedef int DataType;
typedef struct {
	DataType _data[QUEUENUM];
	DataType * _head;
	DataType * _tail;
	size_t _size;
	 }Dequeue;
void dequeueInit(Dequeue * qu);
void dequeueEmpty(Dequeue * qu);
void dequeueDestory(Dequeue * qu);
int dequeuePush(Dequeue * qu, DataType x);
void dequeuePop(Dequeue * qu);
DataType dequeueFront(Dequeue * qu);
DataType dequeueBack(Dequeue * qu);
int dequeueIsEmpty(Dequeue * qu);
size_t dequeueSize(Dequeue * qu);

#endif     //_DEQUEUE_H_