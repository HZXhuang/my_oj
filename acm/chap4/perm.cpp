#include <cstdio>
#include <ctime>
#define mytest 1
using namespace std;
#define Swap(a, b) {int temp = a; a = b; b = temp;}
			// 交换，也可以直接用C++STL中的swap()函数，但是速度慢一些
int data[] = {1,2,3,4,5,6,7,8,9,10,11};
int num = 0;	// 统计全排列的个数，验证是不是3628800
void Perm(int begin, int end)
{
	int i;
	if (begin == end) {
//		for (int i = 0; i < end; i++) printf("%d ", data[i]);
//		printf("%d\n", data[end]);
		num++; // 统计全排列的个数 
	}
	else {
		for (i = begin; i <= end; i++) {
			Swap(data[begin], data[i]); // 当前第一个数与后面的所有数交换位置 
			Perm(begin + 1, end);
			Swap(data[begin], data[i]); // 恢复，用于下一次交换 
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
	Perm(0, 11); // 求10个数的全排列
	printf("%d\n", num);
	end = clock();
	printf("%f\n", (double)(end - start) / CLOCKS_PER_SEC);
	
	return 0;
}
