#include<bits/stdc++.h>
using namespace std;

//"子集"+去重
class Solution {
public:
	//作为成员变量的好处是参数不用传来传去
	vector<int> tmp; //理解1：中间结果  理解2：选与不选形成的路径
	vector<vector<int>> res; //存储结果

	void backtrack(int depth, vector<int>& nums) {
		res.push_back(tmp); //已经形成了中间路径
		for (int i = depth; i < nums.size(); i++) {
			//3行式
			tmp.push_back(nums[i]);
			backtrack(i + 1, nums);
			//不放元素
			tmp.pop_back();
		}
	}

	//// 二维数组去重API
	//vector<vector<int>> setVector(vector<vector<int>>& vv) {
	//	//利用set去重
	//	set<vector<int>>stVec;
	//	for (auto e : vv) {
	//		stVec.insert(e);
	//	}
	//	vv.clear();
	//	for (auto e : stVec) {
	//		vv.push_back(e);
	//	}
	//	//利用set去重
	//	return vv;
	//}

	// 二维数组去重API
	vector<vector<int>> setVector(vector<vector<int>>& vv) {
		//利用set去重
		set<vector<int>> stVec(vv.begin(), vv.end());
		vector<vector<int>> res(stVec.begin(), stVec.end());
		return res;
	}

	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		backtrack(0, nums); //这里只需要传原始数组和深度就行了

		//利用set去重
		res = setVector(res);
		return res;
	}
};


// 剪枝去重
class Solution {
public:
	vector<vector<int>> res;
	vector<int> path;
	void backtrack(vector<int>& nums, int start)
	{
		res.push_back(path);
		for (int i = start; i < nums.size(); i++)
		{
			if (i > start&&nums[i] == nums[i - 1])//剪枝去重
				continue;
			path.push_back(nums[i]);
			backtrack(nums, i + 1);
			path.pop_back();
		}
	}
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		backtrack(nums, 0);
		return res;
	}
};