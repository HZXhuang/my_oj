/**
 * @author hzx007
 * ��Ȼ���Ĳ��  ��������������ݹ� 
 **/

#include <cstdio>
#include <cstring>
//#define mytest 1
using namespace std;
int n, a[101];
void dfs(int len, int pos, int from) // len: �����ۺͣ�pos��������from��������ʼ 
{
	if (len == n) { // ����Ҫ����� 
		printf("%d=", n);
		printf("%d", a[0]);
		for (int i = 1; i < pos; i++) {
			printf("+%d", a[i]);
		}
		printf("\n");
		return;
	}
	if (len > n) return; // ������ԭ����ֱ�ӷ��� 
	for (int i = from; i < n; i++) { // ��ԭ����from��ʼ���� 
		a[pos] = i;
		dfs(len + i, pos + 1, i); // ���������from���� 
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
