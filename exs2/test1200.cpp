/**
 * �ֽ����� 
 **/

#include <cstdio>
#include <cstring>
#include <cmath>
//#define mytest 1
using namespace std;
int res;

void cal(int from, int num)
{
	for (int i = from; i <= num / i; i++) {
		if (num % i == 0) {
			res++;
			cal(i, num / i); // ��֤֮�����ʼ���ִ��ڵ���i�������ظ� 
		}
	}
}
int main()
{
	#ifdef mytest
	freopen("debug/test1200.in", "r", stdin);
	freopen("debug/test1200.out", "w", stdout);
	#endif
	int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		res = 1;
		scanf("%d", &m);
		cal(2, m);
		printf("%d\n", res);
	}
	
	return 0;
}
