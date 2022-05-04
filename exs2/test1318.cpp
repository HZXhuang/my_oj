/**
 * @author hzx007
 * 自然数的拆分  深度优先搜索，递归 
 **/

#include <cstdio>
#include <cstring>
//#define mytest 1
using namespace std;
int n, a[101];
void dfs(int len, int pos, int from) // len: 数字累和，pos：索引，from：搜索起始 
{
	if (len == n) { // 符合要求，输出 
		printf("%d=", n);
		printf("%d", a[0]);
		for (int i = 1; i < pos; i++) {
			printf("+%d", a[i]);
		}
		printf("\n");
		return;
	}
	if (len > n) return; // 超过了原数，直接返回 
	for (int i = from; i < n; i++) { // 从原来的from开始迭代 
		a[pos] = i;
		dfs(len + i, pos + 1, i); // 向后搜索，from不变 
	}
}
int main()
{
	#ifdef mytest
	freopen("debug/test1318.in", "r", stdin);
	freopen("debug/test1318.out", "w", stdout);
	#endif
	scanf("%d", &n);
	dfs(0, 0, 1);
	
	return 0;
} 
