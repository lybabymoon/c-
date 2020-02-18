#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

void quicklySort(vector<int>& nums,int left, int right)
{
	int i = left;
	int j = right;
	int div = i;

	if (left >= right)
	{
		return;
	}
	while (i != j)
	{
		while (nums[j] >= nums[div] && i < j)
		{
			j--;
		}

		if (i < j)
		{
			swap(nums[j], nums[div]);
			div = j;
		}

		while (nums[i] <= nums[div] && i < j)
		{
			i++;
		}

		if (i < j)
		{
			swap(nums[i], nums[div]);
			div = i;
		}
	}
	
	quicklySort(nums,left, div);
	quicklySort(nums, div + 1, right);
}


int main1()
{
	vector<int> ans{ 6,4,1,5,2,3,8,7,4,5 };        
	quicklySort(ans, 0, ans.size() - 1);

	for (auto & i : ans)
	{
		cout << i << " ";
	}
	return 0;
}