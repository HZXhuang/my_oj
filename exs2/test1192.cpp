#include <cstdio>
#include <cstring>
//#define debug 1
using namespace std;
int m[20],n[20];
int f[11][11];
int main()
{
	#ifdef debug
	freopen("debug/test1192.in", "r", stdin);
	freopen("debug/test1192.out", "w", stdout);
	#endif
	int t,mxn = -1,mxm = -1;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d %d", &m[i], &n[i]);
		if (m[i] > mxm) mxm = m[i];
		if (n[i] > mxn) mxn = n[i];
	}
	for (int i = 1; i <= mxm; i++) {
		f[i][0] = 1;f[i][1] = 1;
	}
	for (int i = 1; i <= mxn; i++) {
		f[0][i] = 1;f[1][i] = 1;
	}
	for (int i = 2; i <= mxm; i++) {
		for (int j = 2; j <= mxn; j++) {
			// 从上一种情况递推出当前的情况 
			// 考虑是否有空盘子 
			if (i >= j) f[i][j] = f[i][j - 1] + f[i - j][j];
			else f[i][j] = f[i][i];
		}
	}
	for (int i = 0; i < t; i++) {
		printf("%d\n", f[m[i]][n[i]]);
	}
	
	return 0;
} 
