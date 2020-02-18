#include <iostream>
using namespace std;
#include <vector>

void bubbleSort(vector<int> & nums)
{
	int len = nums.size();
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (nums[j] > nums[j+1])
			{
				swap(nums[j+1], nums[j]);
			}
		}
	}
}
int main()
{
	vector<int> a = { 4, 7, 6, 8, 5, 3, 2, 1 };
	bubbleSort(a);

	for (auto &i : a)
	{
		cout << i << " ";
	}
	return 0;
}