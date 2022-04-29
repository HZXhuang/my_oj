#include <bits/stdc++.h>
using namespace std;

#define _for(i, a) for(i = 0; i < a; i++)


int main()
{
    int count1, i, count2, j, res[20] = {0};
    map<char, int>::iterator it;
    cin >> count1;
    _for(i, count1)
    {
        cin >> count2;
        map<char, int> mp;
        char c;
        _for(j, count2)
        {
            cin >> c;
            mp[c] += 1;
        }
        for (it = mp.begin(); it != mp.end(); it++) {
            if (it->second % 2 != 0) {
                res[i] += it->second - 1;
            }
            else {
                res[i] += it->second;
            }
        }
        res[i] += 1;
    }
    _for(i, count1)
    {
        cout << res[i] << endl;
    }

    return 0;
}
