#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> ans;
	int tmp = 0;
	int max = 0;
	while ((cin >> tmp) && tmp != EOF)
	{
		if (tmp == 0)
		{
			ans.push_back(max);
			max = 0;
		}
		else
		{
			if (tmp > max)
			{
				max = tmp;
			}
		}
	}
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << endl;
	}
	system("pause");
	return 0;
}