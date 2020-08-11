#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <deque>
class LRU
{
	deque<pair<int,int>> qu;
	int k;
public:
	LRU(int K)
	{
		k = K;
	}
	void Set(int key,int value)
	{
		pair<int, int> pa(key,value);
		qu.find
		if (qu.size() == k)
		{
			qu.pop_front();
		}
	}

	int Get(int key)
	{
		//unordered_map<int, int>::iterator it;
		
		if (mp.find(key) != mp.end())
			return mp[key];
		else
			return -1;
	}
};

int main()
{
	int N, K;
	cin >> N >> K;
	LRU lru(K);
	while (N--)
	{
		int opt;
		cin >> opt;

		if (opt == 1)
		{
			int x, y;
			cin >> x >> y;
			lru.Set(x, y);
		}
		else if(opt == 2)
		{
			int x;
			cin >> x;
			cout << lru.Get(x) <<endl;
		}
	}
	return 0;
}