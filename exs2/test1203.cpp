/**
 * @author hzx
 * ����ƥ������
 * ���ݹ飬Ҳ��ʹ��ջ�ķ��� 
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
			if (s[i] == ')') { // �����������Ȳ��ܣ�������������ǰƥ�� 
				for (int j = i - 1; j >= 0; j--) {
					if (s[j] == '(') {
						s[j] = ' ';
						s[i] = ' ';
						break;
					}
				}
			}
			// ������ĸ�����Ϊ�ո��ֱ������ 
			else if (s[i] != '(' && s[i] != ')') {
				s[i] = ' ';
			}
		}
		// ����黹����Щ����û��ƥ�� 
		for (int i = 0; i < len; i++) {
			if (s[i] == '(') s[i] = '$';
			else if (s[i] == ')') s[i] = '?';
		}
		printf("%s\n", s);
	}
	
	return 0;
} 
