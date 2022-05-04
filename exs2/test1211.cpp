/**
 * @author hzx007
 * 判断元素是否存在 
 **/

#include <cstdio>
#include <cstring>
//#define mytest 1
using namespace std;
int k,x;
bool f(int y)
{
	if (y > x) return false; // 找不到了 
	if (y == x) return true; // 找到了 
	return f(2 * y + 1) || f(3 * y + 1);  // 还没找到，继续递归寻找 
}
int main()
{
	#ifdef mytest
	freopen("debug/test1211.in", "r", stdin);
	freopen("debug/test1211.out", "w", stdout);
	#endif
	scanf("%d,%d", &k, &x);
	if (f(k)) printf("YES");
	else printf("NO");
	
	return 0;
} 
