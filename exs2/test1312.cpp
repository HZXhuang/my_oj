#include <cstdio>
#include <cstring>
#include <algorithm>
//#define debug 1
#define ll long long
using namespace std;

int main()
{
    #ifdef debug
    freopen("debug/test1312.in", "r", stdin);
    freopen("debug/test1312.out", "w", stdout);
    #endif // debug
    ll f[55];
    int x,y,z;
    scanf("%d %d %d", &x, &y, &z);
    for (int i = 1; i <= x + 2; i++) f[i] = 1;
    for (int i = x + 3; i <= z + 1; i++) {
        f[i] = f[i - 1] + f[i- x - 2] * y;
    }
    printf("%lld\n", f[z + 1]);

    return 0;
}
