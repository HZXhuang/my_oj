/**
 * @author hzx007
 * LETTERS ������������ 
 **/

#include <cstdio>
#include <cstring>
//#define mytest 1
using namespace std;
bool v2[26];
char mat[21][21];
int mx = -1;
int r,s;
void dfs(int x, int y, int sum)
{
	if (x < 0 || y < 0 || x >= r || y >= s) { // �����߽� 
		if (sum > mx) mx = sum;
		return;
	}
	if (!v2[mat[x][y] - 65]) {
		v2[mat[x][y] - 65] = 1;
		dfs(x + 1, y, sum + 1);
		dfs(x - 1, y, sum + 1);
		dfs(x, y + 1, sum + 1);
		dfs(x, y - 1, sum + 1);
		v2[mat[x][y] - 65] = 0; // ���� 
	}
	else { // û�е��߽磬�����޴����ߣ�����mx 
		if (sum > mx) mx = sum;
		return;
	}
}
int main()
{
	#ifdef mytest
	freopen("debug/test1212.in", "r", stdin);
	freopen("debug/test1212.out", "w", stdout);
	#endif
	scanf("%d %d", &r, &s);
	// ��ȡ���� 
	for (int i = 0; i < r; i++) {
		getchar();
		for (int j = 0; j < s; j++) scanf("%c", &mat[i][j]);
	}
	dfs(0,0,0); //��ʼ���� 
	printf("%d", mx);
	
	return 0;
}
