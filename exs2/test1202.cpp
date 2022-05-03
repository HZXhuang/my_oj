/**
 * @author hzx
 * Pell数列
 * 注意：不要使用递归，不然通过不了，会爆栈 
 **/

#include <cstdio>
#include <cstring>
//#define mytest 1
using namespace std;
int res[1000001];
int n,a[100];

int main()
{
	#ifdef mytest
	freopen("debug/test1202.in", "r", stdin);
	freopen("debug/test1202.out", "w", stdout);
	#endif
	int mx = -1;
	res[1] = 1; res[2] = 2;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (a[i] > mx) mx = a[i];
	}
	for (int i = 3; i <= mx; i++) {
		res[i] = (2 * res[i - 1] + res[i - 2]) % 32767;
	}
	for (int i = 0; i < n; i++) {
		printf("%d\n", res[a[i]]);
	}
	
	return 0;
}
