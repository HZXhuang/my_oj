/**
 * @author hzx
 * ����ƥ������
 * �ݹ��㷨 
 **/

#include <cstdio>
#include <cstring>
//#define mytest 1
using namespace std;

int llen, rlen,len; // llenΪl��������Ч�����ֵĸ��� 
char l[101],r[101], s[101]; // l��¼��δƥ��������ţ�r��¼��δƥ��������� 
void f(int pos)
{
	if (pos == len) return; // ������ɣ��˳� 
	if (s[pos] == '(') l[llen++] = pos; // �����ţ�ֱ�Ӽ�¼ 
	else if (s[pos] == ')') {
		if (llen == 0) r[rlen++] = pos; // ��¼������
		else llen--; // �����ұߵ������� 
	}
	s[pos] = ' '; // ����ǰλ�õ��ַ���Ϊ�ո� 
	f(pos + 1); // ���Ҽ������� 
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
		// ���Ƿ�����δƥ��������ź������� 
		for (int i = 0; i < llen; i++) s[l[i]] = '$';
		for (int i = 0; i < rlen; i++) s[r[i]] = '?';
		printf("%s\n", s);
	}
	
	return 0;
}
