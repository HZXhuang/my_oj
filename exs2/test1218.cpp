/**
取石子
这个提示很重要：
假设石子数目为(a,b)且a >= b,如果[a/b] >= 2则先手必胜,如果[a/b]<2,
那么先手只有唯一的一种取法。[a/b]表示a除以b取整后的值。

*/

#include <cstdio>
#include <cstring>
//#define mytest 1
using namespace std;
int x;
void dfs(int n1, int n2)
{
    if (!n1 || !n2) return;
    if (n1 > n2) {
        x++;
        if (n1 / n2 >= 2) return; // 如果发现a / b >= 2直接停止搜索
        dfs(n1 - n2, n2); // 唯一的取法
    }
    else {
        x++;
        if (n2 / n1 >= 2) return;
        dfs(n1, n2 - n1);
    }
}
int main()
{
    #ifdef mytest
    freopen("debug/test1218.in", "r", stdin);
    freopen("debug/test1218.out", "w", stdout);
    #endif // mytest
    int a,b;
    while (1) {
        scanf("%d %d", &a, &b);
        if (!a && !b) break;
        x = 0;
        dfs(a,b);
        if (x % 2 == 0) printf("lose\n");
        else printf("win\n");
    }

    return 0;
}
