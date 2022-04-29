#include <cstdio>
#include <cstring>
using namespace std;

int a1[301], b1[301], c1[301];

void numcpy(int a[], int b[], int det)  // 将a赋值到b从det开始后的空间
{
    for (int i = 1; i <= a[0]; i++) {
        b[i + det - 1] = a[i];
    }
    b[0] = a[0] + det - 1;
}

int numcmp(int a[], int b[])
{
    if (a[0] > b[0]) return 1;
    if (a[0] < b[0]) return -1;
    for (int i = a[0]; i > 0; i--) {
        if (a[i] > b[i]) return 1;
        else if (a[i] < b[i]) return -1;
    }
    return 0;
}

void jian(int a[], int b[])  //   a = a - b
{
    int f = numcmp(a, b);
    if (f == 0) {
        a[0] = 0;
        return;
    }
    else if (f == 1) {
        for (int i = 1; i <= a[0]; i++) {
            if (a[i] < b[i]) {
                a[i + 1] -= 1;
                a[i] += 10;
            }
            a[i] -= b[i];
        }
        while (a[0] > 0 && a[a[0]] == 0) a[0] -= 1; // 去除前置零
    }
}

int pow2(int x, int n)
{
    if (n == 0) return 1;
    else {
        int res = 1;
        for (int i = 0; i < n; i++) {
            res *= x;
        }
        return res;
    }
}

void init(int a[])
{
    char c[305];
    int len,k = 0;
    scanf("%s", c);
    len = strlen(c);
    a[0] = len;
    for (int i = 1; i <= len; i++) {
        a[i] = c[len - i] - '0';
    }
}

void print(int arr[])
{
    if (arr[0] == 0) {
        printf("0\n");
        return;
    }
    else {
        for (int i = arr[0]; i >= 1; i--) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

int main()
{
    int tmp[301];
    init(a1);init(b1);
    c1[0] = a1[0] - b1[0] + 1;
    for (int i = c1[0]; i >= 1; i--) {
        memset(tmp, 0, sizeof(tmp));
        numcpy(b1, tmp, i);
        while (numcmp(a1, tmp) >= 0) {
            jian(a1, tmp);
            c1[i]++;
        }
    }
    while (c1[0] > 0 && c1[c1[0]] == 0) c1[0]--;
    print(c1);
    print(a1);
    return 0;
}
