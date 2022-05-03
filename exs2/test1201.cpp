/**
 * @author hzx
 * 斐波那契数列 
 * 题号：1201 
 **/

#include <cstdio>
#include <cstring>
//#define mytest 1
using namespace std;
int res[21]; // 备忘录，记忆数组 
int fibo(int a)
{
	if (res[a]) return res[a]; // 如果答案存在备忘录中，直接返回 
	return res[a] = fibo(a - 1) + fibo(a - 2);
}
int main()
{
	#ifdef mytest
	freopen("debug/test1201.in", "r", stdin);
	freopen("debug/test1201.out", "w", stdout);
	#endif
	int n,temp;
	res[1] = 1;res[2] = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		printf("%d\n", fibo(temp));
	}
	
	return 0;
} 
