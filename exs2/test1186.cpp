#include <cstdio>
#include <algorithm>
#include <cstring>
//#define debug 1
using namespace std;
int arr[100];
int main()
{
    #ifdef debug
    freopen("debug/test1186.in", "r", stdin);
    freopen("debug/test1186.out", "w", stdout);
    #endif // debug
    int n,temp,i,ok = false;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        arr[temp + 49]++;
    }
    for (i = 0; i <= 98; i++) {
        if (arr[i] > n/2.0) {
            printf("%d\n", i - 49);
            ok = true;
        }
    }
    if (!ok) printf("no\n");

    return 0;
}
