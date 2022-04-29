#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
//#define debug
using namespace std;
char words[100][50];

int main()
{
    #ifdef debug
    freopen("debug/test1185.in", "r", stdin);
    freopen("debug/test1185.out", "w", stdout);
    #endif // debug
    char temp[50] = {0};
    int n = 0;
    while (scanf("%s", temp) == 1) {
        strcpy(words[n++],temp);
    }
    for (int i = n - 1; i > 0; i--) {
        bool ok = true;
        for (int j = 0; j < i; j++) {
            if (strcmp(words[j], words[j + 1]) > 0) {
                swap(words[j], words[j + 1]);
                ok = false;
            }
        }
        if (ok) break;
    }
    memset(temp, 0, sizeof(temp));
    for (int i = 0; i < n; i++) {
        if (strcmp(words[i], temp)) {
            printf("%s\n", words[i]);
            strcpy(temp, words[i]);
        }
    }

    return 0;
}
