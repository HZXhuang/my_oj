/**
 * @author hzx007
 * �����Լ��
 * �ݹ�ͷǵݹ�  շת�������շת����� 
 **/

#include <cstdio>
#include <cstring>
#include <cmath>
//#define mytest 1
using namespace std;

int gcd(int m, int n)
{
	// �ݹ� 
//	if (n == 0) return m;
//	return gcd(n, m % n);
// ���� 
//	while (n != 0) {
//		int rem = m % n;
//		m = n;
//		n = rem;
//	}
//	return m;
	while (m != n) { // ���ַ����ٶȿ�һЩ ������ 
		int temp = n;
		n = abs(m - n);
		m = temp;
	}
	return m;
}
int main()
{
	#ifdef mytest
	freopen("debug/test1207.in", "r", stdin);
	freopen("debug/test1207.out", "w", stdout);
	#endif
	int x,y;
	scanf("%d %d", &x, &y);
	printf("%d\n", gcd(x, y));
	
	return 0;
}
