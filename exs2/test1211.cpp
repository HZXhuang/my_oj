/**
 * @author hzx007
 * �ж�Ԫ���Ƿ���� 
 **/

#include <cstdio>
#include <cstring>
//#define mytest 1
using namespace std;
int k,x;
bool f(int y)
{
	if (y > x) return false; // �Ҳ����� 
	if (y == x) return true; // �ҵ��� 
	return f(2 * y + 1) || f(3 * y + 1);  // ��û�ҵ��������ݹ�Ѱ�� 
}
int main()
{
	#ifdef mytest
	freopen("debug/test1211.in", "r", stdin);
	freopen("debug/test1211.out", "w", stdout);
	#endif
	scanf("%d,%d", &k, &x);
	if (f(k)) printf("YES");
	else printf("NO");
	
	return 0;
} 
