#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <set>
int main()
{
    int n = 0;
    while (cin >> n)
    {
        vector<int> cur;
        for (int i = 0;i < n;i++)
        {

            int tmp;
            cin >> tmp;
            cur.push_back(tmp);
        }
        int k;
        cin >> k;
        sort(cur.begin(), cur.end());
        for (int i = 1;i < cur.size();i++)
        {
            if (cur[i - 1] == cur[i])
            {
                cur.erase(cur.begin() + i);
                --i;
             }
        }
        cout << cur[k - 1] << endl;
    }
    return 0;
}