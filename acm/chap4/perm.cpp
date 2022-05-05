#include <cstdio>
#include <ctime>
#define mytest 1
using namespace std;
#define Swap(a, b) {int temp = a; a = b; b = temp;}
			// ������Ҳ����ֱ����C++STL�е�swap()�����������ٶ���һЩ
int data[] = {1,2,3,4,5,6,7,8,9,10,11};
int num = 0;	// ͳ��ȫ���еĸ�������֤�ǲ���3628800
void Perm(int begin, int end)
{
	int i;
	if (begin == end) {
//		for (int i = 0; i < end; i++) printf("%d ", data[i]);
//		printf("%d\n", data[end]);
		num++; // ͳ��ȫ���еĸ��� 
	}
	else {
		for (i = begin; i <= end; i++) {
			Swap(data[begin], data[i]); // ��ǰ��һ��������������������λ�� 
			Perm(begin + 1, end);
			Swap(data[begin], data[i]); // �ָ���������һ�ν��� 
		}
	}
}
int main()
{
	#ifdef mytest
	freopen("test/perm.in", "r", stdin);
	freopen("test/perm.out", "w", stdout);
	#endif
	clock_t start, end;
	start = clock();
	Perm(0, 11); // ��10������ȫ����
	printf("%d\n", num);
	end = clock();
	printf("%f\n", (double)(end - start) / CLOCKS_PER_SEC);
	
	return 0;
}
