#include<stdio.h>
#include<stdlib.h>
int main(){
	FILE *pFile;
	pFile = fopen("myfile.txt", "w");
	if (pFile != NULL){
		fputs("fopen example", pFile);
		fclose(pFile);
	}
	system("pause");
	return 0;
}

//typedef  struct {
//	short level;                   //�������������򡰿ա��ĳ̶�
//	unsigned flags;                //�ļ�״̬�ı�־
//	char fd;                       //�ļ�������
//	unsigned char hold;            //�绺���������ݲ���ȡ�ַ�
//	short bsize;                   //�������Ĵ�С
//	unsigned char * buffer;        //���ݻ�������λ��
//	unsigned char curp;            //ָ�뵱ǰ��ָ��
//	short token;                   // ������Ч�Լ��
//}FILE;