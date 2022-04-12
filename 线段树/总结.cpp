// 都是两个指针i，j对问题
#include<bits/stdc++.h>
using namespace std;



// 树状数组
// C[1] = A[0];
// C[2] = A[0] + A[1];
// C[3] = A[2];
// C[4] = A[0] + A[1] + A[2] + A[3];
// C[5] = A[4];
// C[6] = A[4] + A[5];
// C[7] = A[6];
// C[8] = A[0] + A[1] + A[2] + A[3] + A[4] + A[5] + A[6] + A[7];
class BIT {
private:
	vector<int> tree;// 树状数组的大小比原始数组大1
	int n;

public:
	// 构造出长度为n的数组，利用n+1长度的树状数组tree维护单点修改和区间查询
	BIT(int _n) : n(_n), tree(_n + 1) {}
	// 取低位操作，如1010110，取到的是10
	static constexpr int lowbit(int x) {
		return x & (-x);
	}
	// 假设原始数组是A[0]、A[1]....A[n-1], update(x,d)表示A[x-1]+=d
	void update(int x, int d) {
		while (x <= n) {
			tree[x] += d;
			x += lowbit(x);
		}
	}
	// 查询前缀和A[0]+A[1]+....+A[x-1]
	int query(int x) const {
		int ans = 0;
		while (x) {
			ans += tree[x];
			x -= lowbit(x);
		}
		return ans;
	}
};