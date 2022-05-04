/**
 * @author hzx007
 * 求最大公约数
 * 递归和非递归  辗转相除法和辗转相减法 
 **/

#include <cstdio>
#include <cstring>
#include <cmath>
//#define mytest 1
using namespace std;

int gcd(int m, int n)
{
	// 递归 
//	if (n == 0) return m;
//	return gcd(n, m % n);
// 迭代 
//	while (n != 0) {
//		int rem = m % n;
//		m = n;
//		n = rem;
//	}
//	return m;
	while (m != n) { // 这种方法速度快一些 ，？？ 
		int temp = n;
		n = abs(m - n);
		m = temp;
	}
	return m;
}
int main()
{
	#ifdef mytest
	freopen("debug/test1207.in", "r", stdin);
	freopen("debug/test1207.out", "w", stdout);
	#endif
	int x,y;
	scanf("%d %d", &x, &y);
	printf("%d\n", gcd(x, y));
	
	return 0;
}
