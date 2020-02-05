#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> cur;
	int tmp;
	while (cin >> tmp)
	{
		if (tmp == 0)
		{
			break;
		}
		cur.push_back(tmp);
	}

	for (int i = cur.size() - 1; i >= 0; i--)
	{

		cout << cur[i];
		if (i != 0)
		{
			cout << " ";
		}
	}
	return 0;
}#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> cur;
	int tmp;
	while (cin >> tmp)
	{
		if (tmp == 0)
		{
			break;
		}
		cur.push_back(tmp);
	}

	for (int i = cur.size() - 1; i >= 0; i--)
	{

		cout << cur[i];
		if (i != 0)
		{
			cout << " ";
		}
	}
	return 0;
}