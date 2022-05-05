/**
 * @author hzx007
 * 八皇后问题   搜索和回溯 
 **/

#include <cstdio>
#include <cstring>
#include <cmath>
//#define mytest 1
using namespace std;
bool c[9], v1[17], v2[17]; // c标记某一列是否有皇后，v1和v2标记斜线上是否有皇后 
int r[9], sum; // r记录皇后的位置，索引为行，值为列 
void dfs(int pos)
{
	for (int i = 1; i <= 8; i++) {
		// 该位置是否合法 
		if (!c[i] && !v1[i + pos] && !v2[i - pos + 7]) {
			r[pos] = i;
			c[i] = 1;
			v1[i + pos] = 1;
			v2[i - pos + 7] = 1;
			if (pos == 8) {
				sum++;
				printf("No. %d\n", sum);
				// 打印方案 
				for (int x = 1; x <= 8; x++) {
					for (int y = 1; y <= 8; y++) {
						if (x == r[y]) printf("%-2d", 1);
						else printf("%-2d", 0);
					}
					printf("\n");
				}
			} 
			else dfs(pos + 1); // 继续搜索下一个
			// 回溯
			c[i] = 0;
			v1[i + pos] = 0;
			v2[i - pos + 7] = 0;
		}
	}
}
int main()
{
	#ifdef mytest
	//freopen("debug/test1213.in", "r", stdin);
	freopen("debug/test1213.out", "w", stdout);
	#endif
	dfs(1); // 从第一行开始搜索 
	
	return 0;
}
