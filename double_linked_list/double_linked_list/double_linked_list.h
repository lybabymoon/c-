#ifndef _DOUBLE_LINKED_H_
#define _DOUBLE_LINKED_H_ 
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int LTDataType;
typedef struct ListNode {          //˫��ѭ����ͷ˫����
	LTDataType _data;              //���ڵ������
	struct ListNode* _next;        //��һ���ڵ�ĵ�ַ
	struct ListNode* _prev;        //��һ���ڵ�ĵ�ַ
}ListNode;

typedef struct List {
	ListNode* _head;           //�����ͷָ��
}List;

void ListInit(List* plist);
void ListDestory(List* plist);

void ListPushBack(List* plist, LTDataType x);
void ListPopBack(List* plist);
void ListPushFront(List* plist, LTDataType x);
void ListPopFront(List* plist);

ListNode* ListFind(List* plist, LTDataType x);
// ��pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x);
// ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos);
void ListRemove(List* plist, LTDataType x);

void ListPrint(List* plist);
#endif  //_DOUBLE_LINKED_H_