#include<bits/stdc++.h>
using namespace std;

// ���ظ�Ԫ��+ֻ��ѡȡһ��


//"����ܺ�"+ȥ��
class Solution {
public:
	vector<int> tmp; //���1���м���  ���2��ѡ�벻ѡ�γɵ�·��
	vector<vector<int>> res; //�洢���

	void backtrack(int depth, vector<int>& candidates, int target) {
		if (target < 0) return;
		if (target == 0) {//
			res.push_back(tmp); //�Ѿ��γ����м�·��
			return;//������return
		}
		for (int i = depth; i < candidates.size(); i++) {
			tmp.push_back(candidates[i]);
			//��������һ���ط�
			backtrack(i + 1, candidates, target - candidates[i]);//ÿ��������ÿ�������ֻ��ʹ��һ�Σ�������i+1
			tmp.pop_back();
		}

	}
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		backtrack(0, candidates, target);

		//����set�Զ�άvectorȥ�أ����Ԫ����vector
		set<vector<int>>stVec;
		for (auto e : res) {
			stVec.insert(e);
		}
		res.clear();
		for (auto e : stVec) {
			res.push_back(e);
		}
		//����set�Զ�άvectorȥ�أ����Ԫ����vector
		return res;
	}
};


// ���ݽ��м�ǿ�ˣ��������ַ���������
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
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		backtrack(candidates, target, 0);
		res = setVector(res);
		return res;
	}
};





// �Ӽ�������һ���汾�����޸�
class Solution {
private:
	vector<int> candidates;
	vector<vector<int>> res;
	vector<int> path;
public:
	void DFS(int start, int target) {
		if (target == 0) {
			res.push_back(path);
			return;
		}

		for (int i = start; i < candidates.size() && target - candidates[i] >= 0; i++) {
			if (i > start && candidates[i] == candidates[i - 1])
				continue;
			path.push_back(candidates[i]);
			// Ԫ�ز����ظ����ã�ʹ����һ����i+1
			DFS(i + 1, target - candidates[i]);
			path.pop_back();
		}
	}

	vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
		sort(candidates.begin(), candidates.end());
		this->candidates = candidates;
		DFS(0, target);
		return res;
	}
};
