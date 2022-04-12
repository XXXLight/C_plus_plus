#include<bits/stdc++.h>
using namespace std;

//根据子集代码改写而来

//方式一：放与不放
class Solution {
public:
	vector<int> tmp; //理解1：中间结果  理解2：选与不选形成的路径
	vector<vector<int>> res; //存储结果

	void backtrack(int depth, vector<int>& candidates, int target) {
		if (target == 0) {//
			res.push_back(tmp); //已经形成了中间路径
			return;//这里是return
		}
		// 因为下标[0,candidates.size()-1),越界了
		if (depth == candidates.size() || target - candidates[depth] < 0) return;//到数组结尾或者已经是不够减了
		//下一次还取这个元素，所以一个元素可以重复选择
		// if(target-candidates[depth]>=0) 可以有
		tmp.push_back(candidates[depth]);
		backtrack(depth, candidates, target - candidates[depth]);
		//不取这个元素
		tmp.pop_back();
		backtrack(depth + 1, candidates, target);//注意不取时是depth+1

	}
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());//这里必须要sort
		backtrack(0, candidates, target); // 下标[0,candidates.size()-1)
		return res;
	}
};

//方式二：写成for循环形式的"三段论"
// 1.理解前要画出树形结构
// 2.for代表横向遍历，每次递归的分支数目相同，表示树的每个节点都有相同个数分支
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
		sort(candidates.begin(), candidates.end());// 这里sort没有必要
		backtrack(0, candidates, target);
		return res;
	}
};