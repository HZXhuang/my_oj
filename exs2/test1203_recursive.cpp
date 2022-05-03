/**
 * @author hzx
 * 括号匹配问题
 * 递归算法 
 **/

#include <cstdio>
#include <cstring>
//#define mytest 1
using namespace std;

int llen, rlen,len; // llen为l数组中有效的数字的个数 
char l[101],r[101], s[101]; // l记录尚未匹配的左括号，r记录尚未匹配的右括号 
void f(int pos)
{
	if (pos == len) return; // 搜索完成，退出 
	if (s[pos] == '(') l[llen++] = pos; // 左括号，直接记录 
	else if (s[pos] == ')') {
		if (llen == 0) r[rlen++] = pos; // 记录右括号
		else llen--; // 弹出右边的左括号 
	}
	s[pos] = ' '; // 将当前位置的字符改为空格 
	f(pos + 1); // 向右继续搜索 
}
int main()
{
	#ifdef mytest
	freopen("debug/test1203.in", "r", stdin);
	freopen("debug/test1203.out", "w", stdout);
	#endif
	while(~scanf("%s", s)){
		printf("%s\n", s);
		len = strlen(s);
		llen = 0;rlen = 0;
		f(0);
		// 看是否还有尚未匹配的左括号和右括号 
		for (int i = 0; i < llen; i++) s[l[i]] = '$';
		for (int i = 0; i < rlen; i++) s[r[i]] = '?';
		printf("%s\n", s);
	}
	
	return 0;
}
