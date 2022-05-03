/**
 * @author hzx
 * 括号匹配问题
 * 不递归，也不使用栈的方法 
 **/

#include <cstdio>
#include <cstring>
#include <iostream>
//#define mytest 1
using namespace std;
char s[101];
int len;
int main()
{
	#ifdef mytest
	freopen("debug/test1203.in", "r", stdin);
	freopen("debug/test1203.out", "w", stdout);
	#endif
	while (cin.getline(s, 100)) {
		printf("%s\n", s);
		len = strlen(s);
		for (int i = 0; i < len; i++) {
			if (s[i] == ')') { // 碰到左括号先不管，碰到右括号往前匹配 
				for (int j = i - 1; j >= 0; j--) {
					if (s[j] == '(') {
						s[j] = ' ';
						s[i] = ' ';
						break;
					}
				}
			}
			// 碰到字母，标记为空格后直接跳过 
			else if (s[i] != '(' && s[i] != ')') {
				s[i] = ' ';
			}
		}
		// 最后检查还有哪些括号没有匹配 
		for (int i = 0; i < len; i++) {
			if (s[i] == '(') s[i] = '$';
			else if (s[i] == ')') s[i] = '?';
		}
		printf("%s\n", s);
	}
	
	return 0;
} 
