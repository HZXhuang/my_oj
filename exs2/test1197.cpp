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
		s[i] += s[i - 1]; // s[i]为村子i到村子1的距离 
	}
	// 在村子i到j之间修1一所学校，修在(i + j) / 2处，各村上学的距离之和最小 
	for (int i = 1; i <= m; i++) c[i][i] = 0; // 在一个村子建一所小学 
	for (int i = 1; i <= m; i++) {
		for (int j = i + 1; j <= m; j++) {
			// 计算在不同的村区间建一所小学的在最短距离和 
			c[i][j] = c[i][j - 1] + s[j] - s[(i + j) / 2];
		}
	}
	// 前i个村子都只修一所小学的情况 
	for (int i = 1; i <= m; i++) dp[i][1] = c[1][i];
	for (int i = 1; i <= m; i++) { // dp[i][i]为0，不用计算了，因为数组的元素默认都是0 
		for (int j = 2; j <= n && j < i; j++) {
			// 从修j - 1所小学的所有情况中取最小值 
			int mn = 0x3f3f3f3f; // INF 
			for (int k = j - 1; k <= i - 1; k++) {
				temp = dp[k][j - 1] + c[k + 1][i];
				if (temp < mn) mn = temp;
			}
			dp[i][j] = mn; // 取最小值 
		}
	}
	printf("%d\n", dp[m][n]);
	
	return 0;
}
