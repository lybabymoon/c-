#include <iostream>
using namespace std;
#include <list>
#include <unordered_map>

class LRUCache
{
	unordered_map<int, list<pair<int,int>>::iterator> mp;
	list<pair<int,int>> ls;
	int _capacity;
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }

    int get(int key) {
        if (!mp.count(key))
        {
            return -1;
        }
        list<pair<int, int>>::iterator it = mp[key];
        pair<int, int> cur = *it;
        ls.erase(it);
        ls.push_front(cur);
        mp[key] = ls.begin();
        return cur.second;
    }

    void put(int key, int value) {

        if (mp.count(key) == 1)
        {
            list<pair<int, int>>::iterator it = mp[key];
            it->second = value;
            pair<int, int> cur = *it;
            ls.erase(it);
            ls.push_front(cur);
            mp[key] = ls.begin();
        }
        else
        {
            ls.push_front(pair<int, int>(key, value));
            auto it = ls.begin();
            mp[key] = it;
            if (ls.size() > _capacity)
            {
                int cur = ls.back().first;
                ls.pop_back();
                mp.erase(cur);
            }
        }
    }
};
int main()
{
    LRUCache k(2);
    k.put(2, 1);
    k.put(2, 2);
    cout << k.get(2);
    k.put(1, 1);
    k.put(4, 1);
    cout << k.get(2);
    cout << k.get(1);
	return 0;
}