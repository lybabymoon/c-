#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int flag = 0;
	int count = 1;
	for (int i = 0; i < s.size()-1; i++)
	{
		if (s[i] != '-')
		{
			flag += (s[i] - '0') * count;
			++count;
		}
	}

	flag = flag % 11;
	if (s[s.size()-1] - '0' == flag)
	{
		cout << "Right" ;
	}
	else if (s[s.size() - 1] == 'X' && flag == 10)
	{
		cout << "Right";
	}
	else
	{
		if (flag != 10)
		{
			s[s.size() - 1] = flag + 48;
			cout << s;
		}
		else
		{
			s[s.size() - 1] = 'X';
			cout << s;
		}
	}
	return 0;
}
