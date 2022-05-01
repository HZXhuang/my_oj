#include <cstdio>
#include <cstring>
//#define debug 1
using namespace std;

int main()
{
	#ifdef debug
	freopen("debug/test1188.in", "r", stdin);
	freopen("debug/test1188.out", "w", stdout);
	#endif //debug
	int temp,n,mx = -1;
	scanf("%d", &n);
	int num[n + 1];
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
		if (num[i] > mx) mx = num[i];
	}
	int fibo[mx + 1];
	fibo[1] = 1; fibo[2] = 1;
	for (int i = 3; i <= mx; i++) {
		fibo[i] = (fibo[i - 1] + fibo[i - 2]) % 1000;
	}
	for (int i = 0; i < n; i++) {
		printf("%d\n", fibo[num[i]]);
	}
	
	return 0;
}
