#include <iostream>
using namespace std;
#include <vector>

class A
{
public:
	A(int a)
	{
		cout << "A(int a)" << endl;
		
	}
	A(const A& a)
	{
		cout << "A(const A& a)" << endl;
	}
private:
	int _a;
};
class B {
public:
	explicit B(int n)
	{}

	B (const B& b)
	{}
};

void bullpol()
{
	vector<int> nums{ 1,3,5,4,2,6 };
	for (int i = 0;i < nums.size();++i)
	{
		for (int j = 0;j < nums.size() - i - 1;++j)
		{
			if (nums[j] > nums[j+1])
			{
				swap(nums[j+1], nums[j]);
			}
		}
	}

	for (auto i : nums)
	{
		cout << i << endl;
	}
}

void quickSort(vector<int>& nums, int left, int right)
{
	int i = left;
	int j = right;
	if (left >= right)
	{
		return;
	}

	int div = i;

	while (i != j)
	{
		while (i<j && nums[j] >= nums[div])
		{
			--j;
		}

		if (i < j)
		{
			swap(nums[j], nums[div]);
			div = j;
		}

		while (i < j && nums[i] <= nums[div])
		{
			++i;
		}

		if (i < j)
		{
			swap(nums[i], nums[div]);
			div = i;
		}
	}

	quickSort(nums, left, div);
	quickSort(nums, div + 1, right);
}
void main1()
{
	A a1(1);   //
	// ÒþÊ½×ª»»-> A tmp(1); A a2(tmp);
	A a2 = 1;
}
int main()
{
	//main1();
	bullpol();
	return 0;
}