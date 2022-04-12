#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	vector<vector<int>> res;
	vector<int> tmp;
	vector<vector<int>> setVector(vector<vector<int>>& vv) {
		//����setȥ��
		set<vector<int>>stVec;
		for (auto e : vv) {
			stVec.insert(e);
		}
		vv.clear();
		for (auto e : stVec) {
			vv.push_back(e);
		}
		//����setȥ��
		return vv;
	}
	void DFS(vector<int>& candidates, int target, int depth) {
		if (target == 0) {
			res.push_back(tmp);
			return;
		}
		if (depth == candidates.size()) return;
		if (target - candidates[depth] >= 0) {
			tmp.push_back(candidates[depth]);
			// ���������ظ�ѡ��Ԫ�ص���ϡ��޸ĳ�depth+1���κμ�һ��ȥ�ز����Ϳ�����
			DFS(candidates, target - candidates[depth], depth + 1);
			tmp.pop_back();
			DFS(candidates, target, depth + 1);
		}

	}
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		DFS(candidates, target, 0);
		res = setVector(res);
		return res;
	}
};