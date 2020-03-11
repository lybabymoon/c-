#pragma once
#include <vector>
using namespace std;
typedef int HPDataType;

class Heap{
	//vector<HPDataType> m_nums;
	
public:
	//Heap()
	//	:m_nums(m_nums)
	//{

	//}

void Heapify(vector<HPDataType>& m_nums, int i, int low, int high)
{
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int _max;     //保存最大值下标    
	if (l <= high && m_nums[l] > m_nums[i])
	{
		_max = l;
	}
	else
	{
		_max = i;
	}

	if (r <= high && m_nums[r] > m_nums[_max])
	{
		_max = r;
	}

	if (_max != i)
	{
		swap(m_nums[i], m_nums[_max]);
		Heapify(m_nums, _max, low, high);
	}
}
	void HeapInit(vector<HPDataType>& m_nums)    //初始化为大堆
	{
		int len = m_nums.size();
		for (int i = len / 2 - 1; i >= 0; i--)
		{
			Heapify(m_nums, i, 0, len - 1);
		}
	}

	void HeapSort(vector<HPDataType>& m_nums)
	{
		int len = m_nums.size();
		for (int i = len - 1; i >= 0; i--)
		{
			swap(m_nums[i], m_nums[0]);
			Heapify(m_nums, 0, 0, i - 1);
		}
	}

	void HeapPush(HPDataType n, vector<HPDataType>& m_nums)
	{
		m_nums.push_back(n);
		HeapInit(m_nums);
	}

	void HeapPop(vector<HPDataType>& m_nums)
	{
		swap(m_nums[0], m_nums[m_nums.size() - 1]);
		m_nums.pop_back();
		Heapify(m_nums,0,0,m_nums.size()-1);
	}

	
};
