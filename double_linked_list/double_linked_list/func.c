#include "double_linked_list.h"
//双链表的初始化
void ListInit(List* plist){
	plist->_head = (ListNode *)malloc(sizeof(ListNode));
	memset(&plist->_head->_data, 0, sizeof(LTDataType));
	plist->_head->_next = plist->_head->_prev = plist->_head;
}
//双链表的前插
void ListPushFront(List* plist, LTDataType x){
	ListNode * cur = (ListNode *)malloc(sizeof(ListNode));
	cur->_data = x;
	plist->_head->_next->_prev = cur;          //将要插入节点的下一个节点的上一个节点的prev指向cur的地址
	cur->_next = plist->_head->_next;          //将要插入节点cur的next指向头结点下一个节点的地址
	plist->_head->_next = cur;                 //将头节点的next指向cur的地址
	cur->_prev = plist->_head;                 //将cur的prev指向头结点
}
//双链表的后插
void ListPushBack(List* plist, LTDataType x){
	ListNode * cur = (ListNode *)malloc(sizeof(ListNode));
	cur->_data = x;
	plist->_head->_prev->_next = cur;          //插入节点的上一个的节点的next节点指向cur
	cur->_prev = plist->_head->_prev;          //插入节点的prev指向插入节点上一个节点的prev
	plist->_head->_prev = cur;                 //将头节点的prev指向cur
	cur->_next = plist->_head;                 //将cue的next指向头结点
}
void ListPrint(List* plist)
{
	ListNode * cur;
	printf("head<-->");
	for(cur = plist->_head->_next; cur != plist->_head;cur = cur->_next){     
		//双链表的遍历
		printf("%d<-->", cur->_data);
	}
	printf("head\n");
}
//后删
void ListPopBack(List* plist){
	ListNode * tmp = plist->_head->_prev;
	if (tmp != plist->_head){
		tmp->_prev->_next = tmp->_next;
		tmp->_next->_prev = tmp->_prev;
		free(tmp);
	}

}
//前删
void ListPopFront(List* plist){
	ListNode * tmp = plist->_head->_next;
	if (tmp != plist->_head){
		tmp->_prev->_next = tmp->_next;
		tmp->_next->_prev = tmp->_prev;
		free(tmp);
	}

}
//双链表的删除
void ListDestory(List* plist){

	ListNode * tmp = plist->_head->_next;
	while (tmp != plist->_head){
		tmp->_prev->_next = tmp->_next;
		tmp->_next->_prev = tmp->_prev;
		free(tmp);
		tmp = plist->_head->_next;
	}
	free(plist->_head);
	plist->_head = NULL;
}
//查找
ListNode* ListFind(List* plist, LTDataType x){
	assert(plist);
	ListNode * cur;
	for (cur = plist->_head->_next; cur != plist->_head; cur = cur->_next){          //
		if (cur->_data == x){
			return cur;
		}
	}
}
//在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x){
	assert(pos);
	ListNode * tmp;
	ListNode * cur;
	tmp = ListFind(pos, x);
	
}
// 删除pos位置的节点
void ListErase(ListNode* pos){

}
