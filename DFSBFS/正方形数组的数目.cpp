#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool checkNum(int num) {
		int sqr = sqrt(num);
		return sqr * sqr == num;
	}
	int DFS(vector<int>& A, vector<bool> vis, int depth, int prev) {
		if (depth == A.size()) return 1;
		int cnt = 0;
		for (int i = 0; i < A.size(); i++) {
			if (vis[i]) continue;
			if (i > 0 && A[i] == A[i - 1] && !vis[i - 1]) continue;
			if (depth > 0 && !checkNum(prev + A[i])) continue;
			vis[i] = true;
			cnt += DFS(A, vis, depth + 1, A[i]);
			vis[i] = false;
		}
		return cnt;
	}
	int numSquarefulPerms(vector<int>& A) {
		vector<bool> vis(A.size());
		sort(A.begin(), A.end());
		return DFS(A, vis, 0, -1);
	}
};




class Solution {
public:
	int ans;
	vector<int>t;
	int used[12] = { 0 };
	int numSquarefulPerms(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		dfs(nums);
		return ans;

	}
	bool checkNum(int num) {
		int sqr = sqrt(num);
		return sqr * sqr == num;
	}
	void dfs(vector<int>& nums) {
		if (t.size() == nums.size()) {
			ans++;
			return;
		}
		for (int i = 0; i < nums.size(); i++) {
			if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])continue;
			if (!used[i]) {
				if (t.size() == 0 || checkNum(nums[i] + t.back())) {//就是排列加了一个限制
					used[i] = 1;
					t.push_back(nums[i]);
					dfs(nums);
					used[i] = 0;
					t.pop_back();
				}
			}
		}
	}
};




// 由全排列2进行改进，本质是环形且a[i]和a[i+1]之间具有函数关系
class Solution1 {
public:
	vector<vector<int>> res;
	vector<int> tmp;
	bool checkNum(int num) {
		int sqr = sqrt(num);
		return sqr * sqr == num;
	}
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int len = nums.size();
		vector<bool> v(len, false);
		dfs(nums, v);
		return res;
	}
	void dfs(vector<int>& nums, vector<bool>& vis) {

		int len = nums.size();
		if (tmp.size() == len) {
			res.push_back(tmp);
			return;
		}
		for (int i = 0; i < nums.size(); i++) {
			// 排列问题的剪枝
			if (vis[i] || (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1])) {
				continue;
			}
			// 改动的地方（本题的剪枝）,注意这里的或条件顺序不可以交换，因为后面的依赖前面的
			if (tmp.size() == 0 || checkNum(nums[i] + tmp.back())) {
				tmp.push_back(nums[i]);
				vis[i] = true;
				dfs(nums, vis);
				tmp.pop_back();
				vis[i] = false;
			}
		}
	}
};
class Solution {
public:
	int numSquarefulPerms(vector<int>& nums) {
		Solution1 s1;
		s1.permuteUnique(nums);
		for (auto e : s1.res) {
			for (auto e1 : e) cout << e1 << " ";
			cout << endl;
		}
		return s1.res.size();
	}
};