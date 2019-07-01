#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLTDataType; 
typedef struct SListNode { 
	SLTDataType _data;                  //�洢����
	struct SListNode* _next;            //�洢�Լ�����ĵ�ַ
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
// ��pos�ĺ�����в���
void SListInsertAfter(SListNode* pos, SLTDataType x);
// ��pos��ǰ����в���
void SListEraseAfter(SListNode* pos);
void SListRemove(SList* plist, SLTDataType x);

void SListPrint(SList* plist);
void TestSList(); 
void SListReverse(SList* plist);
#endif  //_LINKEDLIST_H_