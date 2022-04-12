#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;


#define N 1005
// 树状数组类
class NumArray {
public:
	int n;
	int tree[N + 1];
	int lowbit(int x) {
		return (x) & (-x);
	}
	NumArray(int len) {
		n = len;
		memset(tree, 0, 4 * n + 1);
	}

	void update(int index) {
		int i = index + 1;
		while (i <= n) {
			tree[i] ++;
			i += lowbit(i);
		}
		return;
	}
	int query(int p) {
		// 查询 下标 {0,1,...,p-1} 的前缀和
		int res = 0;
		while (p > 0) {
			res += tree[p];
			p -= lowbit(p);
		}
		return res;
	}
};
class Solution {
public:
	unordered_map<int, int> mp;// 构建索引 mp[i] = j 表示 i 是在原数组中第 j 小的
	int numTeams(vector<int>& rating) {
		int n = rating.size();
		NumArray* u = new NumArray(n + 1);
		vector<int> h(n, 0);
		for (int i = 1; i < n; i++) h[i] = i;
		sort(h.begin(), h.end(), [&](int& a, int& b) {
			return rating[a] < rating[b];
		});// 排序
		for (int i = 0; i < n; i++) mp[rating[h[i]]] = i + 1;// 构建索引
		int res = 0;
		for (int i = 0; i < n; i++) {
			// 在当前数前面的数有 i 个 在当前数后面的数有 n - i - 1 个
			// 其中在它前面比它小的数有 a 个 比它大的数就是 b = i - a 个
			int index = mp[rating[i]];
			int a = u->query(index);// 前面比它小的个数
			int b = i - a;// 前面比它大的个数
			int c = index - 1 - a;// 后面比它小的个数
			int d = n - 1 - a - b - c;// 后面比它大的个数
			res += a * d + b * c;// 按照要求更新答案
			u->update(index);
		}
		return res;
	}
};

