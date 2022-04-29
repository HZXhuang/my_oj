#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
//#define debug 1
struct stu
{
    int number;
    int chi;
    int total;
};

int main()
{
    #ifdef debug
    freopen("debug/test1179.in", "r", stdin);
    freopen("debug/test1179.out", "w", stdout);
    #endif // debug
    int n,a,b;
    scanf("%d", &n);
    stu lst[n];
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &lst[i].chi, &a, &b);
        lst[i].number = i + 1;
        lst[i].total = lst[i].chi + a + b;
    }
    for (int i = 0; i < n - 1; i++) {
        int p = i;
        for (int j = i + 1; j < n; j++) {
            if (lst[p].total < lst[j].total) p = j;
            else if (lst[p].total == lst[j].total) {
                if (lst[p].chi < lst[j].chi) p = j;
                else if (lst[p].chi == lst[j].chi && lst[p].number > lst[j].number) p = j;
            }
        }
        if (p != i) {
            swap(lst[p], lst[i]);
        }
    }
    for (int i = 0; i < 5; i++) {
        printf("%d %d\n", lst[i].number, lst[i].total);
    }

    return 0;
}
