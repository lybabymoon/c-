#ifndef _DOUBLE_LINKED_H_
#define _DOUBLE_LINKED_H_ 
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int LTDataType;
typedef struct ListNode {          //双向循环带头双链表
	LTDataType _data;              //本节点的数据
	struct ListNode* _next;        //下一个节点的地址
	struct ListNode* _prev;        //上一个节点的地址
}ListNode;

typedef struct List {
	ListNode* _head;           //链表的头指针
}List;

void ListInit(List* plist);
void ListDestory(List* plist);

void ListPushBack(List* plist, LTDataType x);
void ListPopBack(List* plist);
void ListPushFront(List* plist, LTDataType x);
void ListPopFront(List* plist);

ListNode* ListFind(List* plist, LTDataType x);
// 在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x);
// 删除pos位置的节点
void ListErase(ListNode* pos);
void ListRemove(List* plist, LTDataType x);

void ListPrint(List* plist);
#endif  //_DOUBLE_LINKED_H_