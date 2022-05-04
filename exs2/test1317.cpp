/**
 * @author hzx007
 * ��ϵ����  �����������  �ݹ� 
 **/

#include <cstdio>
#include <cstring>
#include <cstdlib>
//#define mytest 1
using namespace std;
int n,r, a[22];
void dfs(int x, int len)
{
	if (len == r) { // �ﵽ������� 
		for (int i = 0; i < len; i++) {
			printf("%3d", a[i]);
		}
		printf("\n");
		return;
	}
	for (int i = x; i <= n; i++) {
		if (len < 1 && i > n - r + 1) return; // ���Ȳ��� 
		a[len] = i;
		dfs(i + 1, len + 1); // �������� 
	}
}
int main()
{
	#ifdef mytest
	freopen("debug/test1317.in", "r", stdin);
	freopen("debug/test1317.out", "w", stdout);
	#endif
	scanf("%d %d", &n, &r);
	dfs(1, 0);
	
	return 0;
}
