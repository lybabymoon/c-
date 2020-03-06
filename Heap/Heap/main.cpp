#include "heap.h"
#include <vector>
using namespace std;
#include <iostream>

void test()
{
	vector<int> nums = { 1, 5, 2, 6, 4, 3 };
	Heap a;
	a.HeapInit(nums);
	a.HeapSort(nums);
	for (auto & i : nums)
	{
		cout << i << endl;
	}
	
	
}
int main()
{
	test();
	return 0;
}