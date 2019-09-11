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
//	short level;                   //缓冲区“满”或“空”的程度
//	unsigned flags;                //文件状态的标志
//	char fd;                       //文件描述符
//	unsigned char hold;            //如缓冲区无内容不读取字符
//	short bsize;                   //缓冲区的大小
//	unsigned char * buffer;        //数据缓存区的位置
//	unsigned char curp;            //指针当前的指向
//	short token;                   // 用于有效性检查
//}FILE;