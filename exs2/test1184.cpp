#include <cstdio>
#include <algorithm>
using namespace std;
//#define debug 1
int a[1001];
int main()
{
    #ifdef debug
    freopen("debug/test1184.in", "r", stdin);
    freopen("debug/test1184.out", "w", stdout);
    #endif // debug
    int n,temp,sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        if (!a[temp]) sum++;
        a[temp]++;
    }
    printf("%d\n", sum);
    for (int i = 1; i <= 1000; i++) {
        if (a[i] > 0) printf("%d ", i);
    }

    return 0;
}
