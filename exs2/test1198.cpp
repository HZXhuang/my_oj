#include <cstdio>
#include <cstring>
#include <cstdlib>
//#define mytest 1
using namespace std;
/*求波兰表达式的值*/
char s[30];
double cal()
{
	scanf("%s", s);
	switch(s[0]) {
		case '+':
			return cal() + cal();
		case '-':
			return cal() - cal();
		case '*':
			return cal() * cal();
		case '/':
			return cal() / cal();
		default:
			return atof(s);
	}
}
int main()
{
	#ifdef mytest
	freopen("debug/test1198.in", "r", stdin);
	freopen("debug/test1198.out", "w", stdout);
	#endif
	double res;
	res = cal();
	printf("%f\n", res);
	
	return 0;
}
