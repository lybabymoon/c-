#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>
#include "MailList.h"
struct MailList g_allMsg[1000];
int g_count;
int menu(){
	int choice = 0 ;
	printf("****1.�����ϵ��              2.ɾ��ָ����ϵ��****\n");
	printf("****3.����ָ����ϵ��          4.�޸�ָ����ϵ��****\n");
	printf("****5.��ʾ������ϵ��          6.���ָ����ϵ��****\n");
	printf("*********************0.�˳�***********************\n");
	printf("��������Ҫѡ���ѡ�");
	scanf("%d", &choice); 
	return choice;
}

void MailList(){
	int op;
	int ret = 0;
	char str[256] = { 0 };
	int searchRes[101] = { 0 };
	while (1){
		op=menu();
		switch (op){
		case ADD_MSG:
			inputData();
			break;
		case DEL_MSG:
			printf("��������Ҫɾ������Ŀ:\n");
			memset(str, 0, sizeof(str));
			scanf("%s", str);
			if (ret > 0){
				deleteOneData(ret);
				printf("ɾ���ɹ�\n");
			}
			else{
				printf("ɾ��ʧ��\n");
			}
			break;
		case SCH_MSG:
			printf("��������Ҫ�������ַ�����\n");
			memset(str, 0, sizeof(str));
			memset(searchRes, 0, sizeof(searchRes));
			scanf("%s", str);
			searchData(str, searchRes);
			outputSearchData(searchRes);
			printf("���ҵ�%d������\n", searchRes[0]);
			break;
		case CHG_MSG:
			break;
		case DIS_MSG:
			outputData();
			break;
		case EMT_MSG:
			memset(g_allMsg, 0, g_count*sizeof(struct MailList));
			g_count = 0;
			break;
		case -1:
			printf("������������������\n");
			break;
		default:
			printf("��������\n");
		}
	}
}

int main(){

	MailList();
	system("pause");
	return 0;
}