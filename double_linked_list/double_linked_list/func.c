#include "double_linked_list.h"
//˫����ĳ�ʼ��
void ListInit(List* plist){
	plist->_head = (ListNode *)malloc(sizeof(ListNode));
	memset(&plist->_head->_data, 0, sizeof(LTDataType));
	plist->_head->_next = plist->_head->_prev = plist->_head;
}
//˫�����ǰ��
void ListPushFront(List* plist, LTDataType x){
	ListNode * cur = (ListNode *)malloc(sizeof(ListNode));
	cur->_data = x;
	plist->_head->_next->_prev = cur;          //��Ҫ����ڵ����һ���ڵ����һ���ڵ��prevָ��cur�ĵ�ַ
	cur->_next = plist->_head->_next;          //��Ҫ����ڵ�cur��nextָ��ͷ�����һ���ڵ�ĵ�ַ
	plist->_head->_next = cur;                 //��ͷ�ڵ��nextָ��cur�ĵ�ַ
	cur->_prev = plist->_head;                 //��cur��prevָ��ͷ���
}
//˫����ĺ��
void ListPushBack(List* plist, LTDataType x){
	ListNode * cur = (ListNode *)malloc(sizeof(ListNode));
	cur->_data = x;
	plist->_head->_prev->_next = cur;          //����ڵ����һ���Ľڵ��next�ڵ�ָ��cur
	cur->_prev = plist->_head->_prev;          //����ڵ��prevָ�����ڵ���һ���ڵ��prev
	plist->_head->_prev = cur;                 //��ͷ�ڵ��prevָ��cur
	cur->_next = plist->_head;                 //��cue��nextָ��ͷ���
}
void ListPrint(List* plist)
{
	ListNode * cur;
	printf("head<-->");
	for(cur = plist->_head->_next; cur != plist->_head;cur = cur->_next){     
		//˫����ı���
		printf("%d<-->", cur->_data);
	}
	printf("head\n");
}
//��ɾ
void ListPopBack(List* plist){
	ListNode * tmp = plist->_head->_prev;
	if (tmp != plist->_head){
		tmp->_prev->_next = tmp->_next;
		tmp->_next->_prev = tmp->_prev;
		free(tmp);
	}

}
//ǰɾ
void ListPopFront(List* plist){
	ListNode * tmp = plist->_head->_next;
	if (tmp != plist->_head){
		tmp->_prev->_next = tmp->_next;
		tmp->_next->_prev = tmp->_prev;
		free(tmp);
	}

}
//˫�����ɾ��
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
//����
ListNode* ListFind(List* plist, LTDataType x){
	assert(plist);
	ListNode * cur;
	for (cur = plist->_head->_next; cur != plist->_head; cur = cur->_next){          //
		if (cur->_data == x){
			return cur;
		}
	}
}
//��pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x){
	assert(pos);
	ListNode * tmp;
	ListNode * cur;
	tmp = ListFind(pos, x);
	
}
// ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos){

}
