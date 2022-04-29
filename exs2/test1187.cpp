#include <cstdio>
#include <algorithm>
#include <cstring>
//#define debug 1
using namespace std;
int num[26];
int main()
{
    #ifdef debug
    freopen("debug/test1187.in", "r", stdin);
    freopen("debug/test1187.out", "w", stdout);
    #endif // debug
    int mx = -1, res = -1;
    char c;
    while ((c = getchar()) != '\n') {
        num[c - 97]++;
    }
    for (int i = 0; i < 26; i++) {
        if (num[i] > mx) {
            mx = num[i];
            res = i;
        }
    }
    printf("%c %d\n", res + 97, mx);

    return 0;
}
