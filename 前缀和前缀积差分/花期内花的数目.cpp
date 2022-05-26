#include<bits/stdc++.h>
using namespace std;


//  一个函数先求导再积分就是原来的函数，使用差分解决问题可以把区间问题转化到区间的左右端点处
class Solution {
public:
	vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
		map<int, int> mp;
		for (auto &it : flowers) mp[it[0]]++, mp[it[1] + 1]--;
		for (auto x : persons) mp[x];// 这句话等价于下面的语句
		/*for (auto x : persons) {
			if (not mp.count(x)) mp[x] = 0;
		};*/
		int sum = 0;
		for (auto &[x, y] : mp) {
			sum += y;
			y = sum;
		}
		// 直接进行映射，原理是传引用改变原来的数据，这种写法要进行学习
		for (auto &x : persons)
			x = mp[x];
		return persons;
	}
};







// 树状数组解法
class Solution {
public:
	const int n = pow(10, 9) + 1;
	unordered_map<int, int> d;
	int low_bit(int x) {
		return x & -x;
	}
	void add(int x, int w) {
		while (x <= n) {
			d[x] += w;
			x += low_bit(x);
		}
	}
	int sum(int x) {
		int res = 0;
		while (x) {
			res += d[x];
			x -= low_bit(x);
		}
		return res;
	}
	vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
		for (auto fl : flowers) {
			int l = fl[0], r = fl[1];
			add(l, 1);
			add(r + 1, -1);
		}
		int size = persons.size();
		vector<int> res(size, 0);
		for (int i = 0; i < size; i++) {
			res[i] = sum(persons[i]);
		}
		return res;
	}
};




// 二分查找的做法，挺多二分查找的题目，凭直觉写出来的代码
class Solution {
public:
	vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
		vector<vector<int>> v1, v2;
		v1 = flowers, v2 = flowers;
		// 按照左端点排序
		sort(v1.begin(), v1.end(), [](auto& e1, auto& e2) {
			return e1[0] < e2[0];
		});
		// 按照右端点排序
		sort(v2.begin(), v2.end(), [](auto& e1, auto& e2) {
			return e1[1] < e2[1];
		});
		// 存储排序后的左右端点
		vector<int> vv1, vv2;
		for (auto& e : v1) {
			vv1.push_back(e[0]);
		}
		for (auto& e : v2) {
			vv2.push_back(e[1]);
		}
		vector<int> res;
		// 二分查找
		for (auto& e : persons) {
			int ind1 = upper_bound(vv1.begin(), vv1.end(), e) - vv1.begin();
			int ind2 = lower_bound(vv2.begin(), vv2.end(), e) - vv2.begin();
			res.push_back(abs(ind2 - ind1));
		}
		return res;
	}
};
