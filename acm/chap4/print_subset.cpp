#include <bits/stdc++.h>
using namespace std;
void print_subset(int n) // ��ӡ���еĶ����� 
{
	for (int i = 0; i < (1<<n); i++) {
		// ÿ��i�Ķ���������Ӧһ���Ӽ���һ�δ�ӡһ���Ӽ������õ����е��Ӽ� 
		for (int j = 0; j < n; j++) // ��ӡһ���Ӽ�������ӡi�Ķ��������е�����1 
			if (i & (1<<j)) // ��i�����λ��ʼ������ÿһλ�������1��ӡ 
				cout << j << " ";
		cout << endl;
	}
}

void print_set(int n, int k) // ��ӡԪ�ظ�����k���Ӽ� 
{
	for (int i = 0; i < (1<<n); i++) {
		int num = 0, kk = i;  // numͳ��i��1�ĸ�����kk��������i
		while (kk) {
			kk = kk & (kk - 1); // ���kk�е����һ��1
			num++; // ͳ��1�ĸ��� 
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
	cin >> n >> k;		// n��������Ԫ�ص�������, k: ����Ϊk���Ӽ� 
	//print_subset(n);	// ��ӡ���е��Ӽ� 
	print_set(n, k);
	
	return 0;
}
