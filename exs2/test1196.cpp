#include <cstdio>
#include <cstring>
//#define debug 1
using namespace std;
int f[21], a[21];
int main()
{
	#ifdef debug
	freopen("debug/test1196.in", "r", stdin);
	freopen("debug/test1196.out", "w", stdout);
	#endif
	int n;
	scanf("%d", &n);
	f[0] = 1;f[1] = 3;a[1] = 2;
	for (int i = 2; i <= n; i++) {
		// 更具规律可以得出该递推公式 
		// f[2] = f[1] + 2 * (f[1] - f[0])
		// f[3] = f[2]/*第一步向北*/ + 2 * (f[2] - (f[1] - f[0])) 
		f[i] = f[i - 1] + 2 * a[i - 1];
		a[i] = f[i] - a[i - 1];
	}
	printf("%d\n", f[n]);
	
	return 0;
}
