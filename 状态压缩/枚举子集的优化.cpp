#include<bits/stdc++.h>
using namespace std;


// 参考文档：https://blog.csdn.net/qq_40586164/article/details/107663649
// 位运算从右边开始是第0位
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