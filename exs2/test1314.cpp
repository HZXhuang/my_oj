#include <cstdio>
#include <algorithm>
#include <cstring>
//#define debug 1
#define ll long long
using namespace std;
ll f[31];
int x,y;

bool check(int a, int b)
{
	if (a == x && b == y) return 1;
	return (abs(x - a) + abs(y - b) == 3) && (max(abs(x - a), abs(y - b)) == 2);
}
int main()
{
	#ifdef debug
	freopen("debug/test1314.in", "r", stdin);
	freopen("debug/test1314.out", "w", stdout);
	#endif
	int n,m;
	f[1] = 1;
	scanf("%d %d %d %d", &n, &m ,&x, &y);
	n += 1;m += 1; x += 1; y += 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (check(i, j)) {
				f[j] = 0; // 是马的控制点，清零 
				continue;
			}
			f[j] += f[j - 1];
		}
	}
	printf("%lld\n", f[m]);
	
	return 0;
}
