/**
 * @author hzx007
 * 放苹果  递归
 * 递推式为res[x,y] = res[x, y - 1] + res[x - y, y] 空一个盘子和不空盘子的情况 
 **/

#include <cstdio>
#include <cstring>
//#define mytest 1
using namespace std;
int res[11][11],n,temp1,temp2;
int divide(int x, int y)
{
	if (res[x][y]) return res[x][y];
	if (x >= y) return res[x][y] = divide(x, y-1) + divide(x - y, y);
	else return res[x][y] = divide(x,x); // x < y时，和x个苹果放x个盘子情况相同 
}
int main()
{
	#ifdef mytest
	freopen("debug/test1206.in", "r", stdin);
	freopen("debug/test1206.out", "w", stdout);
	#endif
	res[1][1] = 1;
	for (int i = 1; i <= 10; i++) {
		res[i][1] = 1;
		res[1][i] = 1;
		res[i][0] = 1;
		res[0][i] = 1;
	}
	scanf("%d", &n);
	while (n--) {
		scanf("%d %d", &temp1, &temp2);
		printf("%d\n", divide(temp1, temp2));
	}
	
	return 0;
}
