/**
 * @author hzx007
 * ���ӷֽ� 
 **/

#include <cstdio>
#include <cstring>
//#define mytest 1
using namespace std;
void f(int n, int a, int b)
{
	if (n == 1) {
		if (b == 1) {
			printf("%d", a);
		}
		else printf("%d^%d", a, b);
		return;
	}
	if (n % a == 0) { // �ܹ������ͳ��ɾ� 
		f(n / a, a, b + 1);
	}
	else {
		if (b > 0) {
			if (b == 1) {
				printf("%d", a);
			}
			else printf("%d^%d", a, b);
			putchar('*');
		}
		f(n, a + 1, 0); // ����һ�������еݹ� 
	}
}
int main()
{
	#ifdef mytest
	freopen("debug/test1210.in", "r", stdin);
	freopen("debug/test1210.out", "w", stdout);
	#endif
	int n;
	scanf("%d", &n);
	f(n, 2, 0);
	
	return 0;
}
