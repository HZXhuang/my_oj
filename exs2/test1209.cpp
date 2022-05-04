/**
 * @author hzx007
 * 分数求和 
 **/

#include <cstdio>
#include <cstring>
#include <cmath>
//#define mytest 1
using namespace std;
int a,b,resa,resb;
int gcd(int x, int y)
{
	while (x != y) {
		int temp = x;
		x = abs(x - y);
		y = temp;
	}
	return x;
}
int main()
{
	#ifdef mytest
	freopen("debug/test1209.in", "r", stdin);
	freopen("debug/test1209.out", "w", stdout);
	#endif
	int n,g;
	scanf("%d", &n);
	scanf("%d/%d", &a, &b);
	resa = a;resb = b;
	for (int i = 1; i < n; i++) {
		scanf("%d/%d", &a, &b);
		// 通分 
		resa = resa * b + a * resb;
		resb *= b;
		g = gcd(resa, resb); // 求最大公约数 
		resa /= g; resb /= g; // 每次都进行约分，比最后进行约分快一些 
	}
	if (resb == 1) printf("%d\n", resa); // 分母为1 
	else printf("%d/%d\n", resa, resb);
	
	return 0;
}
