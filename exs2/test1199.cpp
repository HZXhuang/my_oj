/**
 * 字符串的全排序 
 **/

#include <cstdio>
#include <cstring>
//#define mytest 1
using namespace std; 
char s[10];
int a[10];
bool visited[10];
int len;

void dfs(int idx) // idx记录当前已经访问的字符的个数 
{
	if (idx == len) { // 达到输出的长度 
		for (int i = 0; i < len; i++) {
			printf("%c", s[a[i]]);
		}
		printf("\n");
	}
	for (int i = 0;i < len; i++) {
		if (!visited[i]) {
			a[idx] = i; // 记录字符的访问顺序 
			visited[i] = 1; // 标记为已访问 
			dfs(idx + 1); // 继续访问 
			visited[i] = 0; // 恢复为未访问 
		}
	}
}

int main()
{
	#ifdef mytest
	freopen("debug/test1199.in", "r", stdin);
	freopen("debug/test1199.out", "w", stdout);
	#endif
	scanf("%s", s);
	len = strlen(s);
	dfs(0);
	
	return 0;
}
