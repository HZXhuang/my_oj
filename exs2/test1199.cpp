/**
 * �ַ�����ȫ���� 
 **/

#include <cstdio>
#include <cstring>
//#define mytest 1
using namespace std; 
char s[10];
int a[10];
bool visited[10];
int len;

void dfs(int idx) // idx��¼��ǰ�Ѿ����ʵ��ַ��ĸ��� 
{
	if (idx == len) { // �ﵽ����ĳ��� 
		for (int i = 0; i < len; i++) {
			printf("%c", s[a[i]]);
		}
		printf("\n");
	}
	for (int i = 0;i < len; i++) {
		if (!visited[i]) {
			a[idx] = i; // ��¼�ַ��ķ���˳�� 
			visited[i] = 1; // ���Ϊ�ѷ��� 
			dfs(idx + 1); // �������� 
			visited[i] = 0; // �ָ�Ϊδ���� 
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
