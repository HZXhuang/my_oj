#include <cstdio>
#include <cstring>
//#define mytest 1
using namespace std;
int n,m,x,y, v[11][11],sum;
int dx[] = {1,1,-1,-1,2,2,-2,-2},
    dy[] = {2,-2,2,-2,1,-1,1,-1};

void dfs(int x, int y, int cnt)
{
    if (cnt >= m*n) {
        sum++;
        return;
    }
    for (int i = 0; i < 8; i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if (!v[xx][yy] && xx >= 0 && xx <= n - 1 &&
            yy >= 0 && yy <= m - 1) {
                v[xx][yy] = 1;
                dfs(xx, yy, cnt + 1);
                v[xx][yy] = 0;
            }
    }
}
int main()
{
    #ifdef mytest
    freopen("debug/test1219.in", "r", stdin);
    freopen("debug/test1219.out", "w", stdout);
    #endif // mytest
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d %d", &n, &m, &x, &y);
        memset(v, 0, sizeof(v));
        sum = 0;
        v[x][y] = 1;
        dfs(x,y,1);
        printf("%d\n", sum);
    }

    return 0;
}
