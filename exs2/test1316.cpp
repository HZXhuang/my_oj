#include <cstdio>
#include <cstring>
//#define mytest 1
using namespace std;
/*���ļ���*/
int f[1001];
int main()
{
	#ifdef mytest
	freopen("debug/test1316.in", "r", stdin);
	freopen("debug/test1316.out", "w", stdout);
	#endif
	int n;
	scanf("%d", &n);
	f[1] = 1;
	for (int i = 2; i <= n; i++) {
		// ������ż����ʱ�򣬿ɸ���ǰ��������� 
		if (i % 2 == 0) f[i] = f[i - 1] + f[i / 2];
		else f[i] = f[i - 1];
	}
	printf("%d", f[n]);
	
	return 0;
}
