/**
 * @author hzx007
 * 汉诺塔问题 递归 
 **/

#include <cstdio>
#include <cstring>
//#define mytest 1
using namespace std;
char l,mid,r;
int n;
void move(char from, char to, char another, int idx)
{
	if (idx == 1) {
		printf("%c->%d->%c\n", from, idx, to);
		return;
	}
	move(from, another,to, idx - 1); // 把idx - 1个盘子从from移动到another，借助to 
	printf("%c->%d->%c\n", from, idx, to);
	move(another, to, from, idx - 1);
}
int main()
{
	#ifdef mytest
	freopen("debug/test1205.in", "r", stdin);
	freopen("debug/test1205.out", "w", stdout);
	#endif
	scanf("%d %c %c %c", &n, &l, &mid, &r);
	move(l, mid, r, n);
	
	return 0;
} 
