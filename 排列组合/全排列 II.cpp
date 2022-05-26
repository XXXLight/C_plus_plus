#include<bits/stdc++.h>
using namespace std;

// 方法一：next_permutation直接调库
// next_permutation方法会直接帮你去重
class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		sort(nums.begin(), nums.end());//必须先排序
		vector<vector<int>> res;
		do {
			res.push_back(nums);
		} while (next_permutation(nums.begin(), nums.end()));
		return res;
	}
};

// 方法2：求出所有结果再去重
//"全排列"+去重
class Solution {
public:
	//作为成员变量的好处是参数不用传来传去
	vector<int> tmp; //理解1：中间结果  理解2：选与不选形成的路径
	vector<vector<int>> res; //存储结果

	void backtrack(vector<int>& nums, vector<bool>& vis) {
		if (tmp.size() == nums.size()) {
			res.push_back(tmp); //已经形成了中间路径
			return;
		}

		for (int i = 0; i < nums.size(); i++) {
			if (not vis[i]) {
				tmp.push_back(nums[i]);
				vis[i] = true;
				backtrack(nums, vis);
				//不放元素
				tmp.pop_back();
				vis[i] = false;
			}
		}
	}

	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<bool> vis(nums.size(), false);//vis与nums有关系，不好放在外面
		backtrack(nums, vis); //这里只需要传原始数组和深度就行了

		//利用set去重
		set<vector<int>>stVec;
		for (auto e : res) {
			stVec.insert(e);
		}
		res.clear();
		for (auto e : stVec) {
			res.push_back(e);
		}
		return res;
	}
};


// 方法3：预先排序+设置访问顺序
// 只需在全排列中的剪枝里再加上一个条件就可以了
class Solution {
public:
	//作为成员变量的好处是参数不用传来传去
	vector<int> tmp; //理解1：中间结果  理解2：选与不选形成的路径
	vector<vector<int>> res; //存储结果

	void backtrack(vector<int>& nums, vector<bool>& vis) {
		if (tmp.size() == nums.size()) {
			res.push_back(tmp); //已经形成了中间路径
			return;
		}
		//  for循环处理横向的遍历，其实每次都会有三个分支，只不过标记过的不用重复访问；depth处理深度
		for (int i = 0; i < nums.size(); i++) {
			// 通过画图，要理解为什么可以这样进行剪枝，a||b,a是和之前一样进行剪枝，b是保证访问顺序
			// if (vis[i] || (i+1 <nums.size() && nums[i] == nums[i + 1] && !vis[i+1]))这样剪枝也可以
			if (vis[i] || (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1])) {// 必须是vis[i-1],不能是vis[i]
				continue;
			}
			tmp.push_back(nums[i]);
			vis[i] = true;
			backtrack(nums, vis);// 递归进去分支数不变，只是进行了剪枝
			//不放元素
			tmp.pop_back();
			vis[i] = false;
		}
	}

	// 注意下面先进排序操作了
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<bool> vis(nums.size(), false);//vis与nums有关系，不好放在外面
		sort(nums.begin(), nums.end());
		backtrack(nums, vis); //这里只需要传原始数组和深度就行了
		return res;
	}
};