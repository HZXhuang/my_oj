#include <bits/stdc++.h>
using namespace std;
void print_subset(int n) // 打印所有的二进制 
{
	for (int i = 0; i < (1<<n); i++) {
		// 每个i的二进制数对应一个子集，一次打印一个子集，最后得到所有的子集 
		for (int j = 0; j < n; j++) // 打印一个子集，即打印i的二进制数中的所有1 
			if (i & (1<<j)) // 从i的最低位开始逐个检查每一位，如果是1打印 
				cout << j << " ";
		cout << endl;
	}
}

void print_set(int n, int k) // 打印元素个数是k的子集 
{
	for (int i = 0; i < (1<<n); i++) {
		int num = 0, kk = i;  // num统计i中1的个数，kk用来处理i
		while (kk) {
			kk = kk & (kk - 1); // 清除kk中的最后一个1
			num++; // 统计1的个数 
		}
		if (num == k) {
			for (int j = 0; j < n; j++) {
				if (i & (1<<j)) cout << j << " ";
			}
			cout << endl;
		}
	}
}
int main()
{	
	int n,k;
	cin >> n >> k;		// n：集合中元素的总数量, k: 个数为k的子集 
	//print_subset(n);	// 打印所有的子集 
	print_set(n, k);
	
	return 0;
}
