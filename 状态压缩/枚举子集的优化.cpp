#include<bits/stdc++.h>
using namespace std;


// �ο��ĵ���https://blog.csdn.net/qq_40586164/article/details/107663649
// λ������ұ߿�ʼ�ǵ�0λ
int main() {
	int n = 4;
	for (int i = 1; i < (1 << n); ++i) {
		for (int j = i; j; j = (j - 1) & i) {
			// ...
			cout << bitset<4>(i) << " " << bitset<4>(j) << endl;
		}
	}
	return 0;
}