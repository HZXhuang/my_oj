#include <cstdio>
#include <cstring>
//#define mytest 1
using namespace std;
/*集合的划分*/
#define ll long long
ll sum;
ll divide(int n, int k)
{
	if (k == 0 || k > n) return 0;
	if (k == n || k == 1) return 1;
	return divide(n - 1, k - 1) + k * divide(n - 1, k);
}
int main()
{
	#ifdef mytest
	freopen("debug/test1315.in", "r", stdin);
	freopen("debug/test1315.out", "w", stdout);
	#endif
	int n,k;
	scanf("%d %d", &n, &k);
	sum = divide(n, k);
	printf("%lld\n", sum);
	
	return 0;
}
