#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x,y;
    cin >> x;
    while (x-->0)
    {
        cin >> y;
        if (y % 3 == 1) cout << "1";
        for (int k = 0; k < y / 3; k++) cout << "21";
        if (y % 3 == 2) cout << "2";
        cout << endl;
    }

    return 0;
}
