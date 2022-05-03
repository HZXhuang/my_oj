/**
 * @author hzx007
 * ÅÀÂ¥Ìİ 
 **/

#include <cstdio>
#include <cstring>
//#define mytest 1
using namespace std;
int res[31]; // ±¸ÍüÂ¼ 
int n;
int f(int x)
{
	if (res[x]) return res[x];
	return res[x] = f(x - 1) + f(x - 2);
}
int main()
{
	#ifdef mytest
	freopen("debug/test1204.in", "r", stdin);
	freopen("debug/test1204.out", "w", stdout);
	#endif
	res[1] = 1;res[2] = 2;
	while (~scanf("%d", &n)) {
		printf("%d\n", f(n));
	}
	
	return 0;
} 
