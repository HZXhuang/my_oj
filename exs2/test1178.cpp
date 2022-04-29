#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
//#define debug 1
int score[21];
char name[21][21];
int main()
{
    #ifdef debug
    freopen("debug/test.in", "r", stdin);
    freopen("debug/test1178.out", "w", stdout);
    #endif // debug
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", name[i]);
        scanf("%d", &score[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        int p = i;
        for (int j = i +1; j < n; j++) {
            if (score[p] < score[j]) p = j;
            else if (score[p] == score[j] && strcmp(name[p], name[j]) > 0)
                p = j;
        }
        if (p != i) {
            swap(score[p], score[i]);
            swap(name[p], name[i]);
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%s %d\n", name[i], score[i]);
    }

    return 0;
}
