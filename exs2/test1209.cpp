/**
 * @author hzx007
 * ������� 
 **/

#include <cstdio>
#include <cstring>
#include <cmath>
//#define mytest 1
using namespace std;
int a,b,resa,resb;
int gcd(int x, int y)
{
	while (x != y) {
		int temp = x;
		x = abs(x - y);
		y = temp;
	}
	return x;
}
int main()
{
	#ifdef mytest
	freopen("debug/test1209.in", "r", stdin);
	freopen("debug/test1209.out", "w", stdout);
	#endif
	int n,g;
	scanf("%d", &n);
	scanf("%d/%d", &a, &b);
	resa = a;resb = b;
	for (int i = 1; i < n; i++) {
		scanf("%d/%d", &a, &b);
		// ͨ�� 
		resa = resa * b + a * resb;
		resb *= b;
		g = gcd(resa, resb); // �����Լ�� 
		resa /= g; resb /= g; // ÿ�ζ�����Լ�֣���������Լ�ֿ�һЩ 
	}
	if (resb == 1) printf("%d\n", resa); // ��ĸΪ1 
	else printf("%d/%d\n", resa, resb);
	
	return 0;
}
