#include <cstdio>
#include <algorithm>
//#define debug 1
using namespace std;

int f[1001][2];
int main()
{
#ifdef debug
	freopen("debug/test1313.in", "r", stdin);
	freopen("debug/test1313.out", "w", stdout);
#endif // debug
	int n;
	f[1][0] = 8;f[1][1] = 1;
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		f[i][0] = (f[i - 1][0] * 9 + f[i - 1][1]) % 12345;
		f[i][1] = (f[i - 1][0] + f[i - 1][1] * 9) % 12345;
	}
	if (n == 1) f[1][0] = 9;
	printf("%d\n", f[n][0]);
	
	return 0;
}
