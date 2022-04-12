#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<vector<int>> res;
	vector<int> tmp;
	void DFS(vector<int>& candidates, int target, int depth) {
		if (target == 0) {
			res.push_back(tmp);
			return;
		}
		if (depth == candidates.size()) return;
		if (target - candidates[depth] >= 0) {
			tmp.push_back(candidates[depth]);
			DFS(candidates, target - candidates[depth], depth);
			tmp.pop_back();
			DFS(candidates, target, depth + 1);
		}

	}
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		DFS(candidates, target, 0);
		return res;
	}
};


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
			backtrack(i, candidates, target - candidates[i]);
			tmp.pop_back();
		}

	}
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		backtrack(0, candidates, target);
		return res;
	}
};