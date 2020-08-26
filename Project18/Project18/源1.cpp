#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string>
bool canConvertString(string s, string t, int k) {
    if (s.size() != t.size()) return false;
    int n = s.size();
    int m = t.size();
    int count = 0;
    for (int i = 0;i < n;++i)
    {
        if (s[i] < t[i])
        {
            count += (t[i] - '0')- (s[i] - '0');
        }
        else
        {
            count += (t[i] - 'a' - '0') + ('z' - s[i] - '0');
        }
        if (count > k) return false;
    }

    return true;
}

int main()
{

    string s1{ "abc" };
    string s2{ "bcd" };
    cout << canConvertString(s1,s2,10) << endl;
    
    return 0;
}