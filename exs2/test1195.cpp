#include <cstdio>
#include <cstring>
#include <cmath>
//#define debug 1
using namespace std;
bool f[101], a[101];
int main()
{
	#ifdef debug
	freopen("debug/test1195.in", "r", stdin);
	freopen("debug/test1195.out", "w", stdout);
	#endif
	int n,k, temp;
	scanf("%d %d", &n, &k);
	scanf("%d", &temp);
	f[temp % k] = 1;
	for (int i = 2; i <= n; i++) {
		scanf("%d", &temp);
		memset(a, 0, sizeof(a));
		for (int j = 0; j < k; j++) {
			if (f[j]) {
				// 状态转移，前i - 1个数运算后对k取余的情况，推出当前i个数对k取余的情况 
				a[abs((j + temp) % k)] = 1;
				a[abs((j - temp) % k)] = 1;
			}
		}
		for (int x = 0; x < k; x++) f[x] = a[x];
	}
	if (f[0]) printf("YES\n");
	else printf("NO\n");
	
	return 0;
}
