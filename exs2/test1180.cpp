#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
//#define debug 1
struct person
{
    int k = -1;
    int s = 0;
};

int main()
{
    #ifdef debug
    freopen("debug/test1180.in", "r", stdin);
    freopen("debug/test1180.out", "w", stdout);
    #endif // debug
    int n,m, std;
    scanf("%d %d", &n, &m);
    person lst[n + 1];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &lst[i].k, &lst[i].s);
    }
    for (int i = 0; i < n - 1; i++) {
        int p = i;
        for (int j = i + 1; j < n; j++) {
            if (lst[p].s < lst[j].s) p = j;
            else if (lst[p].s == lst[j].s && lst[p].k
                     > lst[j].k) p = j;
        }
        if (p != i) swap(lst[p], lst[i]);
    }
    m = floor(m * 1.5) - 1;
    for (int i = m + 1; i < n; i++) {
        if (lst[i].s >= lst[m].s) m++;
    }
    printf("%d %d\n", lst[m].s, m + 1);
    for (int i = 0; i <= m; i++) {
        printf("%d %d\n", lst[i].k, lst[i].s);
    }

    return 0;
}
