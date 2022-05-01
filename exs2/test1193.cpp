#include <cstdio>
#include <cstring>
//#define debug 1
using namespace std;

int main()
{
	#ifdef debug
	freopen("debug/test1193.in", "r", stdin);
	freopen("debug/test1193.out", "w", stdout);
	#endif
	int n, f1 = 1, f2 = 2, f3;
	scanf("%d", &n);
	for (int i = 3; i <= n; i++) {
		f3 = f2 + f1;
		f1 = f2;
		f2 = f3;
	}
	if (n == 1) printf("1");
	else if (n == 2) printf("2");
	else printf("%d\n", f3);
	
	return 0;
}
