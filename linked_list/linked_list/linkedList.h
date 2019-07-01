#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLTDataType; 
typedef struct SListNode { 
	SLTDataType _data;                  //存储内容
	struct SListNode* _next;            //存储自己本身的地址
}SListNode;

typedef struct SList {
	SListNode* _head; 
}SList;

void SListInit(SList* plist);
void SListDestory(SList* plist);

SListNode* BuySListNode(SLTDataType x);
void SListPushFront(SList* plist, SLTDataType x);
void SListPopFront(SList* plist);
SListNode* SListFind(SList* plist, SLTDataType x);
// 在pos的后面进行插入
void SListInsertAfter(SListNode* pos, SLTDataType x);
// 在pos的前面进行插入
void SListEraseAfter(SListNode* pos);
void SListRemove(SList* plist, SLTDataType x);

void SListPrint(SList* plist);
void TestSList(); 
void SListReverse(SList* plist);
#endif  //_LINKEDLIST_H_