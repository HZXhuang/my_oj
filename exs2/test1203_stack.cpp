/**
 * @author hzx
 * 使用栈，括号匹配问题 
 **/

#include <cstdio>
#include <cstring>
#include <stack>
//#define mytest 1
using namespace std;

char s[101];
stack<char> st;
int idx[101];
int main()
{
	#ifdef mytest
	freopen("debug/test1203.in", "r", stdin);
	freopen("debug/test1203.out", "w",stdout);
	#endif
	int len;
	while (~scanf("%s", s)) {
		memset(idx, 0, sizeof(idx));
		printf("%s\n", s);
		len = strlen(s);
		for (int i = 0; i < len; i++) {
			if (s[i] == '(') {  // 左括号进栈 
				st.push(i);
			}
			else if (s[i] == ')') { // 右括号，进行处理 
				if (st.empty()) idx[i] = 2;
				else {
					st.pop();
				}
			}
		}
		while (!st.empty()) { // 如果栈没空，把栈里的索引标记为左括号未匹配 
			idx[st.top()] = 1;
			st.pop();
		}
		for (int i = 0;i < len; i++) {
			if (idx[i] == 0) putchar(' ');
			else if (idx[i] == 1) putchar('$');
			else if (idx[i] == 2) putchar('?');
		}
		putchar('\n');
	}
	
	return 0;
} 
