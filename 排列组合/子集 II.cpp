#include<bits/stdc++.h>
using namespace std;

//"�Ӽ�"+ȥ��
class Solution {
public:
	//��Ϊ��Ա�����ĺô��ǲ������ô�����ȥ
	vector<int> tmp; //���1���м���  ���2��ѡ�벻ѡ�γɵ�·��
	vector<vector<int>> res; //�洢���

	void backtrack(int depth, vector<int>& nums) {
		res.push_back(tmp); //�Ѿ��γ����м�·��
		for (int i = depth; i < nums.size(); i++) {
			//3��ʽ
			tmp.push_back(nums[i]);
			backtrack(i + 1, nums);
			//����Ԫ��
			tmp.pop_back();
		}
	}

	//// ��ά����ȥ��API
	//vector<vector<int>> setVector(vector<vector<int>>& vv) {
	//	//����setȥ��
	//	set<vector<int>>stVec;
	//	for (auto e : vv) {
	//		stVec.insert(e);
	//	}
	//	vv.clear();
	//	for (auto e : stVec) {
	//		vv.push_back(e);
	//	}
	//	//����setȥ��
	//	return vv;
	//}

	// ��ά����ȥ��API
	vector<vector<int>> setVector(vector<vector<int>>& vv) {
		//����setȥ��
		set<vector<int>> stVec(vv.begin(), vv.end());
		vector<vector<int>> res(stVec.begin(), stVec.end());
		return res;
	}

	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		backtrack(0, nums); //����ֻ��Ҫ��ԭʼ�������Ⱦ�����

		//����setȥ��
		res = setVector(res);
		return res;
	}
};


// ��֦ȥ��
class Solution {
public:
	vector<vector<int>> res;
	vector<int> path;
	void backtrack(vector<int>& nums, int start)
	{
		res.push_back(path);
		for (int i = start; i < nums.size(); i++)
		{
			if (i > start&&nums[i] == nums[i - 1])//��֦ȥ��
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