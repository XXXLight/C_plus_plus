#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

int p[100005], prime[100005];
class Solution {
public:
	int find(int x) {
		return x == p[x] ? p[x] : p[x] = find(p[x]);
	}
	int largestComponentSize(vector<int>& nums) {
		for (int i = 0; i <= 100000; i++) {
			p[i] = i;
			prime[i] = 1;
		}
		unordered_set<int> s;
		for (int x : nums) {
			s.insert(x);
		}
		for (int i = 2; i <= 100000; i++) {
			if (prime[i]) {
				for (int j = i * 2; j <= 100000; j += i) {
					prime[j] = 0;
					if (s.count(j)) p[find(j)] = find(i);
				}
			}
		}
		int res = 0;
		unordered_map<int, int> m;
		for (int i = 0; i < nums.size(); i++) {
			m[find(nums[i])]++;
			res = max(res, m[find(nums[i])]);
		}
		return res;
	}
};






//并查集模板来做，类定义在外面
class UF {
public:
	vector<int> parent;
	UF(int n) {
		parent.resize(n);
		for (int i = 0; i < n; i++) parent[i] = i;
	}
	int find(int x) {
		while (parent[x] != x) {
			// 进行路径压缩
			parent[x] = parent[parent[x]]; //将x用parent[x]换元
			x = parent[x];
		}
		return x;
	}
	bool check(int a, int b) {
		int fa = find(a);
		int fb = find(b);
		if (fa == fb) return true;
		return false;
	}
	void unionAB(int a, int b) {
		int fa = find(a);
		int fb = find(b);
		if (fa != fb) parent[fa] = fb;
	}
};
class Solution {
public:
	int largestComponentSize(vector<int>& nums) {
		int max_e = *max_element(nums.begin(), nums.end());
		int cnt = max_e + 1;
		UF uf(cnt);
		for (auto e : nums) {
			for (int j = 2; j <= sqrt(e); j++) {
				if (e%j == 0) {
					uf.unionAB(e, j);
					uf.unionAB(e, e / j);
				}
			}
		}
		unordered_map<int, vector<int>> mp;
		for (auto e : nums) {
			mp[uf.find(e)].push_back(e);
		}
		int res = 0;
		for (auto &[u, v] : mp) {
			res = max(res, int(v.size()));
		}
		return res;
	}
};



// 也可以将一个类定义在另一个类里面
class Solution {
public:
	//并查集模板来做
	class UF {
	public:
		vector<int> parent;
		UF(int n) {
			parent.resize(n);
			for (int i = 0; i < n; i++) parent[i] = i;
		}
		int find(int x) {
			while (parent[x] != x) {
				// 进行路径压缩
				parent[x] = parent[parent[x]]; //将x用parent[x]换元
				x = parent[x];
			}
			return x;
		}
		bool check(int a, int b) {
			int fa = find(a);
			int fb = find(b);
			if (fa == fb) return true;
			return false;
		}
		void unionAB(int a, int b) {
			int fa = find(a);
			int fb = find(b);
			if (fa != fb) parent[fa] = fb;
		}
	};
	int largestComponentSize(vector<int>& nums) {
		int max_e = *max_element(nums.begin(), nums.end());
		int cnt = max_e + 1;
		UF uf(cnt);
		for (auto e : nums) {
			for (int j = 2; j <= sqrt(e); j++) {
				if (e%j == 0) {
					uf.unionAB(e, j);
					uf.unionAB(e, e / j);
				}
			}
		}
		unordered_map<int, vector<int>> mp;
		for (auto e : nums) {
			mp[uf.find(e)].push_back(e);
		}
		int res = 0;
		for (auto &[u, v] : mp) {
			res = max(res, int(v.size()));
		}
		return res;
	}
};