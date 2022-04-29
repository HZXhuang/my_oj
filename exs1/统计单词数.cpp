#include <bits/stdc++.h>

using namespace std;

int main()
{
    int len,len2, cnt = 0, idx = 0;
    string tgt,src;
    getline(cin, tgt);getline(cin, src);
    len = src.length();len2 = tgt.length();
    for (int i = 0; i <= len - len2; i++) {
        int j;
        for (j = 0; j < len2; j++) {
            if (toupper(src[i + j]) != toupper(tgt[j])) break;
            if (i > 0 && src[i - 1] != ' ') break;
        }
        if ((j == len2) && (src[i + j] == ' ' || i + j == len)) {
            cnt++;
            if (cnt == 1) idx = i;
        }
    }
    if (cnt == 0) printf("-1\n");
    else printf("%d %d\n", cnt, idx);

    return 0;
}
