#include <cstdio>
#include <cstring>
//#define debug 1
using namespace std;
int num[100]; // ��Ų������� 
long long f[72]; // ��Ŵ�  ע�⿪long long ��Ȼ����� 
int main()
{
	#ifdef debug
	freopen("debug/test1190.in", "r", stdin);
	freopen("debug/test1190.out", "w", stdout);
	#endif
	int n = 0, mx = -1,temp;
	while (true) {
		scanf("%d", &temp);
		if (!temp) break;
		if (temp > mx) mx = temp;
		num[n++] = temp;
	}
	f[1] = 1;f[2] = 2; f[3] = 4;
	for (int i = 4; i <= mx; i++) {
		f[i] = f[i - 1] + f[i - 2] + f[i - 3]; // ����ʽ 
	}
	for (int i = 0;i < n; i++) {
		printf("%lld\n", f[num[i]]);
	}
	
	return 0;
}
