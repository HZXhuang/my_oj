#include <cstdio>
#include <cstring>
//#define debug 1
using namespace std;
short f[102][102];
int main()
{
	#ifdef debug
	freopen("debug/test1191.in", "r", stdin);
	freopen("debug/test1191.out", "w", stdout);
	#endif
	char c;
	int n,m,sum = 0;
	scanf("%d", &n);
	getchar();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			c = getchar(); // ��getchar()��ȡ�ٶȸ��� 
			switch (c) {
				// �ֱ��ò�ͬ�����ֱ�ʾ��������˵�״̬ 
				case '#':
					f[i][j] = -1;
					break;
				case '@':
					f[i][j] = 1;
					sum++;
					break;
				case '.':
					f[i][j] = -2;
					break;
			}
		}
		getchar();
	}
	scanf("%d", &m);
	for (int k = 1; k < m; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (f[i][j] == k) { // ��k��ʾ�ǵڼ����Ⱦ��
				// ���ֲ�ͬ���Ⱦ���� 
					if (f[i - 1][j] == -2) {
						f[i - 1][j] = k + 1;sum++; // sum��ʱ��¼�Ѿ���Ⱦ������ 
					}
					if (f[i + 1][j] == -2) {
						f[i + 1][j] = k + 1;sum++;
					}
					if (f[i][j - 1] == -2) {
						f[i][j - 1] = k + 1;sum++;
					}
					if (f[i][j + 1] == -2) {
						f[i][j + 1] = k + 1;sum++;
					}
				}
			}
		}
	}
	printf("%d", sum);
	
	return 0;
}
