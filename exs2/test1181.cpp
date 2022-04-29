#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
//#define debug 1
int a[10],b[10];
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}
int main()
{
    #ifdef debug
    freopen("debug/test1181.in", "r", stdin);
    freopen("debug/test1181.out", "w", stdout);
    #endif // debug
    int temp,x = 0,y = 0;
    for (int i = 0; i < 10; i++) {
        scanf("%d", &temp);
        if (temp % 2 == 0) b[y++] = temp;
        else a[x++] = temp;
    }
    for (int i = 0; i < x - 1; i++) {
        int p = i;
        for (int j = i + 1; j < x; j++) {
            if (a[p] < a[j]) p = j;
        }
        if (p != i) swap(a[p], a[i]);
    }
    for (int i = 0; i < y - 1; i++) {
        int p = i;
        for (int j = i + 1; j < y; j++) {
            if (b[p] > b[j]) p = j;
        }
        if (p != i) swap(b[p], b[i]);
    }
    print(a, x);
    print(b, y);

    return 0;
}
