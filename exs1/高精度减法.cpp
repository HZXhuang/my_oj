#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;


int main()
{
    //ios::sync_with_stdio(false);
    int a[256], b[256], c[256], lena, lenb, lenc, i;
    char n[256], n1[256], n2[256];
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
    printf("Input minuend: ");
    gets(n1);
    printf("Input subtrahend: ");
    gets(n2);
    if (strlen(n1) < strlen(n2) || (strlen(n1) == strlen(n2) && strcmp(n1, n2) < 0)) {
        // ����n1��n2��ֵ
        strcpy(n, n1);
        strcpy(n1, n2);
        strcpy(n2, n);
        printf("-"); // �����˼����뱻���������Ϊ����
    }
    lena = strlen(n1);
    lenb = strlen(n2);
    for (i = 0; i <= lena - 1; i++) a[lena - i] = n1[i] - '0';
    for (i = 0; i <= lenb - 1; i++) b[lenb - i] = n2[i] - '0';
    i = 1;
    while (i <= lena || i <= lenb) {
        if (a[i] < b[i]) {
            a[i] += 10;  // ����������ô���λ��1��10
            a[i + 1]--;
        }
        c[i] = a[i] - b[i];  // ��Ӧλ���
        i++;
    }
    lenc = i;
    while ((c[lenc] == 0) && (lenc > 1)) lenc--;    // ���λ��0�����
    for (i = lenc; i >= 1; i--) printf("%d", c[i]); // ������
    printf("\n");

	return 0;
}
