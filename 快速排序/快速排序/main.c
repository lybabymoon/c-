#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdio.h>
int a[101], n;
void quicksort(int left, int right){
	int j, i, t, tmp;
	if (left > right){
		return;                   //�����ߴ����ұ��˳�ѭ��
	}
	tmp = a[left];                //��ŵ�һ����׼��ֵ
	i = left;
	j = right;
	while (i != j){              //���left �� right ���ཻ��ʼѭ��j--��i++
		while (a[j] >= tmp && i < j)    //�ҵ�С�ڻ�׼������
			j--;
		while (a[i] <= tmp && i < j)    //�ҵ����ڻ�׼������
			i++;
		if (i < j){                    //�������ڻ�׼��������С�ڻ�׼������
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}
	a[left] = a[i];                   //����ͷ��Ϊ��׼�����ֺ�iֹͣ--ǰ�����ֽ��н���
	a[i] = tmp;
	quicksort(left, i - 1);           //�ݹ�������� ֱ��ȫ������
	quicksort(i + 1, right);
}
int main(){
	int i, j, t;
	printf("��������Ҫ��������ֵĸ�����\n");
	scanf("%d", &n);            
	printf("��������Ҫ���������\n");
	for (i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	quicksort(1, n);
	for (i = 1; i <= n; i++)
		printf("%d", a[i]);
	getchar(); getchar();
	system("pause");
	return 0;
}