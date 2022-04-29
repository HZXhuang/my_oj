#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define debug 1

int main()
{
    #ifdef debug
    freopen("debug/test.in", "r", stdin);
    freopen("debug/test.out", "w", stdout);
    #endif // debug
    int a;
    cin >> a;

    cout << a << endl;

    return 0;
}
