#include<bits/stdc++.h>
using namespace std;

//"组合总和"+去重
class Solution {
public:
	vector<int> tmp; //理解1：中间结果  理解2：选与不选形成的路径
	vector<vector<int>> res; //存储结果

	void backtrack(int depth, vector<int>& candidates, int target) {
		if (target < 0) return;
		if (target == 0) {//
			res.push_back(tmp); //已经形成了中间路径
			return;//这里是return
		}
		for (int i = depth; i < candidates.size(); i++) {
			tmp.push_back(candidates[i]);
			//仅仅改了一个地方
			backtrack(i + 1, candidates, target - candidates[i]);//每个数字在每个组合中只能使用一次，所以是i+1
			tmp.pop_back();
		}

	}
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		backtrack(0, candidates, target);

		//利用set对二维vector去重，理解元素是vector
		set<vector<int>>stVec;
		for (auto e : res) {
			stVec.insert(e);
		}
		res.clear();
		for (auto e : stVec) {
			res.push_back(e);
		}
		//利用set对二维vector去重，理解元素是vector
		return res;
	}
};


class Solution {
public:
	vector<vector<int>> res;
	vector<int> tmp;
	void backtrack(vector<int>& candidates, int target, int depth) {
		if (target == 0) {
			res.push_back(tmp);
			return;
		}
		if (depth == candidates.size() || target - candidates[depth] < 0) return;
		tmp.push_back(candidates[depth]);
		backtrack(candidates, target - candidates[depth], depth + 1);
		tmp.pop_back();
		backtrack(candidates, target, depth + 1);

	}
	vector<vector<int>> setVector(vector<vector<int>>& vv) {
		//利用set去重
		set<vector<int>>stVec;
		for (auto e : vv) {
			stVec.insert(e);
		}
		vv.clear();
		for (auto e : stVec) {
			vv.push_back(e);
		}
		//利用set去重
		return vv;
	}
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		backtrack(candidates, target, 0);
		res = setVector(res);
		return res;
	}
};