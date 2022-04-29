#include <bits/stdc++.h>

using namespace std;

#define _fori(a,b) for(int i = a; i < b; i++)
#define _forj(a,b) for(int j = a; j < b; j++)
long long dp[30];
int x,y,n,m;

inline int mread()
{
    int num = 0;
    char c = getchar();
    while(!isdigit(c)) c = getchar();
    while (isdigit(c))
        (num = (num << 3) + (num << 1) + (c ^ '0')),c = getchar();
    return num;
}

inline bool check_(int x1, int y1)
{
    if (x1 == x && y1 == y) return 1;
    return (abs(x1 - x) + abs(y1 - y) == 3) && max(abs(x1 - x), abs(y1 - y)) == 2;
}

int main()
{
    n = mread();m = mread();x = mread();y = mread();
    x += 2;y += 2;m += 2;n += 2;
    dp[2] = 1;
    _fori(2, n + 1)
    {
        _forj(2, m + 1)
        {
            if (check_(i, j)) {
                dp[j] = 0;  // 当前位置被马拦住，对应位置赋值为零
                continue;
            }
            dp[j] = dp[j] + dp[j - 1]; // i & 1相当于 i % 2，速度更快
        }
    }
    printf("%lld\n", dp[m]);
    return 0;
}
