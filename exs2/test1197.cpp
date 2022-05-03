#include <cstdio>
#include <cstring>
//#define mytest
using namespace std;
int dp[501][501], s[501], c[501][501];
int main()
{
	#ifdef mytest
	freopen("debug/test1197.in", "r", stdin);
	freopen("debug/test1197.out", "w", stdout);
	#endif
	int m,n, temp;
	scanf("%d %d", &m, &n);
	s[1] = 0;c[1][1] = 0;
	for (int i = 2; i <= m; i++) {
		scanf("%d", &s[i]);
		s[i] += s[i - 1]; // s[i]Ϊ����i������1�ľ��� 
	}
	// �ڴ���i��j֮����1һ��ѧУ������(i + j) / 2����������ѧ�ľ���֮����С 
	for (int i = 1; i <= m; i++) c[i][i] = 0; // ��һ�����ӽ�һ��Сѧ 
	for (int i = 1; i <= m; i++) {
		for (int j = i + 1; j <= m; j++) {
			// �����ڲ�ͬ�Ĵ����佨һ��Сѧ������̾���� 
			c[i][j] = c[i][j - 1] + s[j] - s[(i + j) / 2];
		}
	}
	// ǰi�����Ӷ�ֻ��һ��Сѧ����� 
	for (int i = 1; i <= m; i++) dp[i][1] = c[1][i];
	for (int i = 1; i <= m; i++) { // dp[i][i]Ϊ0�����ü����ˣ���Ϊ�����Ԫ��Ĭ�϶���0 
		for (int j = 2; j <= n && j < i; j++) {
			// ����j - 1��Сѧ�����������ȡ��Сֵ 
			int mn = 0x3f3f3f3f; // INF 
			for (int k = j - 1; k <= i - 1; k++) {
				temp = dp[k][j - 1] + c[k + 1][i];
				if (temp < mn) mn = temp;
			}
			dp[i][j] = mn; // ȡ��Сֵ 
		}
	}
	printf("%d\n", dp[m][n]);
	
	return 0;
}
