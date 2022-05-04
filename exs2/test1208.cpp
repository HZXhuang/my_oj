/**
 * @author hzx007
 * 2的幂次方表示 
 **/

#include <cstdio>
#include <cstring>
//#define mytest 1
using namespace std;

void f(int x, int n)
{
	// 模拟短除法 
	if (n == 0) return;
	int rem = n % 2; // 取得余数 
	n /= 2;
	f(x + 1, n); // 继续 
	if (rem == 1) {
		if (n != 0) putchar('+');
		if (x == 0) printf("2(0)");
		else if (x == 1) putchar('2');
		else if (x > 1) { // 继续拆分 
			putchar('2');
			putchar('(');
			f(0, x);
			putchar(')');
		}
	}
}
int main()
{
	#ifdef mytest
	freopen("debug/test1208.in", "r", stdin);
	freopen("debug/test1208.out", "w", stdout);
	#endif
	int n;
	scanf("%d", &n);
	f(0, n); // 都n运用短除法 
	
	return 0;
}
