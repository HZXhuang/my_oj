/**
 * @author hzx007
 * �˻ʺ�����   �����ͻ��� 
 **/

#include <cstdio>
#include <cstring>
#include <cmath>
//#define mytest 1
using namespace std;
bool c[9], v1[17], v2[17]; // c���ĳһ���Ƿ��лʺ�v1��v2���б�����Ƿ��лʺ� 
int r[9], sum; // r��¼�ʺ��λ�ã�����Ϊ�У�ֵΪ�� 
void dfs(int pos)
{
	for (int i = 1; i <= 8; i++) {
		// ��λ���Ƿ�Ϸ� 
		if (!c[i] && !v1[i + pos] && !v2[i - pos + 7]) {
			r[pos] = i;
			c[i] = 1;
			v1[i + pos] = 1;
			v2[i - pos + 7] = 1;
			if (pos == 8) {
				sum++;
				printf("No. %d\n", sum);
				// ��ӡ���� 
				for (int x = 1; x <= 8; x++) {
					for (int y = 1; y <= 8; y++) {
						if (x == r[y]) printf("%-2d", 1);
						else printf("%-2d", 0);
					}
					printf("\n");
				}
			} 
			else dfs(pos + 1); // ����������һ��
			// ����
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
	dfs(1); // �ӵ�һ�п�ʼ���� 
	
	return 0;
}
