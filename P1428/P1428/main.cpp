#include <iostream>
#include <vector>
using namespace std;


int main()
{
	int n = 0;
	cin >> n;
	vector<int> cur;
	vector<int> ans;
	int count = 0;
	while (n--)
	{
		int tmp;
		cin >> tmp;
		cur.push_back(tmp);
	}

	for (int i = 0; i < cur.size(); i++)
	{
		count = 0;
		for (int j = 0; j < i; j++)
		{
			if (cur[i] > cur[j])
			{
				count++;
			}
		}

		ans.push_back(count);
	}

	for (auto i : ans)
	{
		cout << i << " ";
	}
	return 0;
}