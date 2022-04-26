#include<bits/stdc++.h>
using namespace std;



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

