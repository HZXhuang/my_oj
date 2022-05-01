#include <cstdio>
#include <cstring>
//#define debug 1
using namespace std;

int main()
{
	#ifdef debug
	freopen("debug/test1189.in", "r", stdin);
	freopen("debug/test1189.out", "w", stdout);
	#endif
	int n,mx = -1;
	scanf("%d", &n);
	int* num = new int[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
		if (num[i] > mx) mx = num[i];
	}
	int* f = new int[mx + 1]; // �Ӷѿռ俪���ڴ棬���������ʱ������� 
	f[1] = 1;f[2] = 2;
	for (int i = 3; i <= mx; i++) {
		f[i] = (2 * f[i - 1] + f[i - 2]) % 32767;
	}
	for (int i = 0; i < n; i++) {
		printf("%d\n", f[num[i]]);
	}
	// �ͷſռ� 
	delete[] num;
	delete[] f;
	
	return 0;
} 
