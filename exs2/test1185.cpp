#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
//#define debug
using namespace std;
class MyComp
{
public:
    bool operator()(string a, string b)
    {
        return a < b;
    }
};
int main()
{
    #ifdef debug
    freopen("debug/test1185.in", "r", stdin);
    freopen("debug/test1185.out", "w", stdout);
    #endif // debug
    string temp;
    set<string> words;
    while (cin >> temp) {
        words.insert(temp);
    }
    for (set<string, MyComp>::iterator it = words.begin(); it != words.end(); it++) {
        cout << *it << endl;
    }

    return 0;
}
