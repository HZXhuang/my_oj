void init(int a[])
{
    char s[202];
    scanf("%s", s);
    memset(a,0,sizeof(a));
    a[0] = strlen(s);
    for (int i = 1; i <= a[0]; i++) {
        a[i] = s[a[0] - i] - '0';
    }
    while (a[0] > 1 && !a[a[0]]) a[0]--;
}
// 高精度乘法
void num_multi(int a[])
{
    memset(b, 0, sizeof(b));
    int len = a[0],x;
    b[0] = len * 2;
    for (int i = 1; i <= len; i++) {
        x = 0;
        for (int j = 1; j <= len; j++) {
            b[i + j - 1] += x + a[i] * a[j];
            x = b[i + j - 1] / 10;
            b[i + j - 1] %= 10;
        }
        b[len + i] = x;
    }
    while (b[0] > 1 &&!b[b[0]]) b[0]--;
    len = b[0];
    for (int i = 0; i <= len; i++) {
        a[i] = b[i];
    }
}

// 高精度加法
void num_add(int a[])
{
    for (int i = 0; i <= a[0]; i++) {
        b[i] = a[i];
    }
    for (int i = 1; i <= a[0]; i++) {
        a[i + 1] += (a[i] + b[i]) / 10;
        a[i] = (a[i] + b[i]) % 10;
    }
    if (a[a[0] + 1] > 0) a[0]++;
}
