#include <iostream>
#include <vector>
using namespace std;

vector<int> findCommonNums(vector<int>& n1, vector<int>& n2)
{
	vector<int> ans;
	int i = 0;
	int j = 0;
	int n = n1.size();
	int m = n2.size();
	while (i < n && j < m)
	{
		if (n1[i] == n2[j])
		{
			ans.push_back(n1[i]);
			++i;
			++j;
		}
		else if (n1[i] < n2[j])
		{
			++i;
		}
		else if (n1[i] > n2[j])
		{
			++j;
		}
	}
	return ans;
}

int main()
{
	// 1 2 3 4 5 6
	// 1 2 5 6 7 8
	vector<int> nums1{ 1,2,3,4,5,6 };
	vector<int> nums2{ 1,2,5,6,7,8 };

	nums1 = findCommonNums(nums1, nums2);
	for (auto& i : nums1)
	{
		cout << i << " ";
	}
	cout << endl;
	return 0;
}