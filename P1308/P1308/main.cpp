#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s1;
	string s2;

	int count = 0;  //记录单词出现的次数
	int place = -1;  //记录单词首次出现的位置

	getline(cin, s1);
	getline(cin, s2);
	for (int i = 0; i < s2.size(); i++)
	{
		s2[i] |= 32;
	}

	for (int i = 0; i < s1.size(); i++)
	{
		s1[i] |= 32;
	}

	if (s2[0] == ' ')
	{

	}
	for (int i = 1; i < s2.size(); i++)
	{
		if
		for (int j = 0; j < s1.size(); i++)
		{
			if ()
		}
	}
	return 0;
}
