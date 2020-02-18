#include <iostream>
#include <vector>
using namespace std;
#define left(x) 2*x+1   //获得左节点在数组中的下标
#define right(x) 2*(x+1)  //获得右节点在数组中的下标

// a 要被排序的数组 i根节点的坐标 low,high要被维护的下标 
void maxHeapify(vector<int> &a, int i, int low, int high)   //维护最大堆
{
	int l = left(i);
	int r = right(i);
	int largest;     //保存i，l，r 三节点中最大数的下标

	if (l <= high && a[l] > a[i])     //如果左节点的值大于根节点，则将左节点的下标保存
	{
		largest = l;
	}
	else
	{
		largest = i;
	}

	if (r <= high && a[r] > a[largest])    //如果右节点的值大于根节点，则将右节点的下标保存
	{
		largest = r;
	}

	if (largest != i)         //将最大值移至所要维护的堆顶
	{
		swap(a[i], a[largest]);
		maxHeapify(a, largest, low, high);
	}
}

void buildMaxHeap(vector<int> &a, int length)  //建堆
{
	for (int i = length / 2 - 1; i >= 0; i--)   //从最后一个非叶子结点开始
	{
		maxHeapify(a, i, 0, length - 1);
	}
}

void heapSort(vector<int> &a, int length)    //堆排序
{
	buildMaxHeap(a, length);      //构建最大堆

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