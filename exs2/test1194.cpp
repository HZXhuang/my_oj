#include <cstdio>
#include <cstring>
//#define debug 1
using namespace std;
long long f[21];
int main()
{
	#ifdef debug
	freopen("debug/test1194.in", "r", stdin);
	freopen("debug/test1194.out", "w", stdout);
	#endif
	int m,n;
	f[1] = 1;
	scanf("%d %d", &m, &n);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			f[j] += f[j - 1];
		}
	}
	printf("%lld\n", f[n]);
	
	return 0;
} 
