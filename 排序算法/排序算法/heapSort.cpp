#include <iostream>
#include <vector>
using namespace std;
#define left(x) 2*x+1   //�����ڵ��������е��±�
#define right(x) 2*(x+1)  //����ҽڵ��������е��±�

// a Ҫ����������� i���ڵ������ low,highҪ��ά�����±� 
void maxHeapify(vector<int> &a, int i, int low, int high)   //ά������
{
	int l = left(i);
	int r = right(i);
	int largest;     //����i��l��r ���ڵ�����������±�

	if (l <= high && a[l] > a[i])     //�����ڵ��ֵ���ڸ��ڵ㣬����ڵ���±걣��
	{
		largest = l;
	}
	else
	{
		largest = i;
	}

	if (r <= high && a[r] > a[largest])    //����ҽڵ��ֵ���ڸ��ڵ㣬���ҽڵ���±걣��
	{
		largest = r;
	}

	if (largest != i)         //�����ֵ������Ҫά���ĶѶ�
	{
		swap(a[i], a[largest]);
		maxHeapify(a, largest, low, high);
	}
}

void buildMaxHeap(vector<int> &a, int length)  //����
{
	for (int i = length / 2 - 1; i >= 0; i--)   //�����һ����Ҷ�ӽ�㿪ʼ
	{
		maxHeapify(a, i, 0, length - 1);
	}
}

void heapSort(vector<int> &a, int length)    //������
{
	buildMaxHeap(a, length);      //��������

	for (int i = length - 1; i >= 1; i--)
	{
		swap(a[i], a[0]);
		maxHeapify(a, 0, 0, i - 1);
	}
}
int main2()
{
	vector<int> a = { 4, 7, 6, 8, 5, 3, 2, 1 };
	heapSort(a, a.size());

	for (auto &i : a)
	{
		cout << i << " ";
	}
	return 0;
}