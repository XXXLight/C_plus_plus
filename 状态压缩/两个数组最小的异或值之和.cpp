#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size();
		vector<int> f(1 << n, INT_MAX);
		f[0] = 0;
		for (int mask = 1; mask < (1 << n); ++mask) {
			for (int i = 0; i < n; ++i) {
				if (mask & (1 << i)) {
					f[mask] = min(f[mask], f[mask ^ (1 << i)] + (nums1[__builtin_popcount(mask) - 1] ^ nums2[i]));
				}
			}
		}
		return f[(1 << n) - 1];
	}
};



// 输出调试，还是不理解
class Solution {
public:
	int minimumXORSum(vector<int>& a, vector<int>& b) {
		using ll = long long;
		int n = a.size();
		const int INF = 0x3f3f3f3f;
		vector<int> f(1 << n, INF);
		f[0] = 0;
		for (int mask = 1; mask < (1 << n); mask++) {
			for (int i = 0; i < n; i++) {
				if (mask&(1 << i)) {
					cout << bitset<3>(mask) << " " << "取b的第" << i << "个元素 ";
					f[mask] = min(f[mask], f[mask ^ (1 << i)] + (a[__builtin_popcount(mask) - 1] ^ b[i]));
					cout << bitset<3>(mask ^ (1 << i)) << " " << "取a的第" << __builtin_popcount(mask) - 1 << "个元素" << endl;
				}
			}
		}
		return f[(1 << n) - 1];
	}
};




// 模拟退火算法，有点秀
const double eps = 1e-18;
const double delta = 0.999;//调了一年的参数一般为0.97~1.0
class Solution {
public:
	vector<int> a, b;
	int ans = INT_MAX;//答案
	double fun() {
		int res = 0;
		for (int i = 0; i < a.size(); i++)
			res += (a[i] ^ b[i]);
		ans = min(ans, res); //取最小
		return res;
	}

	int sa() {
		random_shuffle(b.begin(), b.end()); //打乱，随机分布
		int n = a.size();
		for (double t = 1e6; t > eps; t *= delta) {
			int x = rand() % n, y = rand() % n;
			int last = fun(); //没有交换前的异或值之和
			swap(b[x], b[y]); //交换后的异或值之和
			int now = fun();
			int de = now - last;
			if (de < 0) { //比当前优秀就要
			}
			else if (!(exp(-1.0*de / t)*RAND_MAX > rand()))  // 模拟退火的法则，我也搞不懂，背一下就好了
				swap(b[x], b[y]);  //不符合法则，回溯。
		}
		return ans;
	}

	int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
		for (int i : nums1) a.push_back(i);
		for (int i : nums2) b.push_back(i);
		return sa();
	}
};