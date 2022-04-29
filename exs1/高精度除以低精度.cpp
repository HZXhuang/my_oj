#include <bits/stdc++.h>

using namespace std;

int main()
{
    char a1[100];
    int a[100], c[100], lena,i, x = 0, lenc, b;
    memset(a, 0, sizeof(a));
    memset(c, 0, sizeof(c));
    scanf("%s", a1);
    scanf("%d", &b);
    lena = strlen(a1);
    for (i = 0; i <= lena - 1; i++) {
        a[i + 1] = a1[i] - '0';
    }
    for (i = 1; i <= lena; i++) {   // 按位相除
        c[i] = (x * 10 + a[i]) / b;
        x = (x * 10 + a[i]) % b;
    }
    lenc = 1;
    while (c[lenc] == 0 && lenc < lena)
        lenc++; // 删除前导零
    for (i = lenc; i <= lena; i++) printf("%d", c[i]);
    printf("\n");

    return 0;
}
