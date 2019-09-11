#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_COLS 20
#define MAX_INPUT 1000
int read_column_numbers(int columns[], int max);
void rearrange(char *output, char const *input,
	int n_columns, int const columns[]);
int main(void){
	int n_columns;    //���д���ı��
	int columns[MAX_COLS];          //��Ҫ���������
	char input[MAX_INPUT];          //���������е�����
	char output[MAX_INPUT];         //��������е�����
	//��ȡ���б��
	n_columns = read_column_numbers(columns, MAX_COLS);
	//��ȡ��������ӡʣ���������
	while (gets(input) != NULL){
		printf("Original input : %s\n", input);
		rearrange(output, input, n_columns, columns);
		printf("Rearranged Line: %s\n", output);
	}
	return EXIT_SUCCESS;
}
//��ȡ�б�ţ���������涨��Χ������ᡣ
int read_column_numbers(int columns[], int max){
	int num = 0;
	int ch;
	//ȡ���б�ţ��������ȡ����С��0��ֹͣ
	while (num < max && scanf("%d", &columns[num]) == 1 && columns[num] >= 0)
		num += 1;
		//ȷ���Ѿ���ȡ�ı��Ϊż��������Ϊ�������ԶԵ���ʽ���ֵġ�
		if (num % 2 != 0){
			puts("Last column number is not paried.");
			exit(EXIT_FAILURE);
	}
		while ((ch = getchar()) != EOF&&ch != '\n')
			;
		return num;
}
//���������У���ָ���е��ַ�������һ���������NUL��β��
void rearrange(char *output, char const *input, int n_columns, int const columns[]){
	int col;            //columns������±�
	int output_col;     //����м�����
	int len;            //�����еĳ���

	len = strlen(input);
	output_col = 0;
	//����ÿ���б��
	for (col = 0; col < n_columns; col += 2){
		int nchars = columns[col + 1] - columns[col] + 1;
		//��������н�����������������������ͽ�������
		if (columns[col] >= len || output_col == MAX_INPUT - 1)
			break;
		//�����������ݿռ䲻����ֻ���ƿ������ɵ����ݡ�
		if (output_col + nchars > MAX_INPUT - 1)
			nchars = MAX_INPUT - output_col - 1;
		//������ص�����
		strncpy(output + output_col, input + columns[col], nchars);
		output_col += nchars;
	}
	output[output_col] = '\0';
}