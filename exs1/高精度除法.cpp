#include <cstdio>
#include <cstring>

int a[101],res[101];
void init(int arr[])
{
    char s[101];
    scanf("%s", s);
    arr[0] = strlen(s);
    for (int i = 1; i <= arr[0]; i++) {
        arr[i] = s[arr[0] - i] - '0';
    }
    while (arr[0] > 1 && !arr[arr[0]]) arr[0]--;
}
int main()
{
    int j = 1,ans;
    init(a);
    for (int i = a[0]; i >= 2; i--) {
        a[i - 1] += (a[i] % 13) * 10;
        res[j++] = a[i] / 13;
        res[0]++;
    }
    res[j] = a[1] / 13;
    res[0]++;
    ans = a[1] % 13;
    j = 1;
    while (res[0] > j && !res[j]) j++;
    for (;j <= res[0]; j++) {
        printf("%d", res[j]);
    }
    printf("\n%d\n", ans);

    return 0;
}
