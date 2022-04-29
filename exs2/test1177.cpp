#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
//#define debug 1
int arr[500];

void quicksort(int l, int r)
{
    int i = l,j = r, mid = arr[(l + r) / 2];
    do {
        while (arr[i] < mid) i++;
        while (arr[j] > mid) j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;j--;
        }
    } while (i <= j);
    if (l < j) quicksort(l,j);
    if (i < r) quicksort(i,r);
}

int main()
{
    #ifdef debug
    freopen("debug/test.in", "r", stdin);
    freopen("debug/test1177.out", "w", stdout);
    #endif // debug
    int n,temp,len = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        if (temp % 2 != 0) arr[len++] = temp;
    }
    quicksort(0, len - 1);
    for (int i = 0; i < len; i++) {
        if (i) {
            printf(",%d", arr[i]);
        }
        else {
            printf("%d", arr[i]);
        }
    }

    return 0;
}
