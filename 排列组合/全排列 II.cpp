#include<bits/stdc++.h>
using namespace std;

// ����һ��next_permutationֱ�ӵ���
// next_permutation������ֱ�Ӱ���ȥ��
class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		sort(nums.begin(), nums.end());//����������
		vector<vector<int>> res;
		do {
			res.push_back(nums);
		} while (next_permutation(nums.begin(), nums.end()));
		return res;
	}
};

// ����2��������н����ȥ��
//"ȫ����"+ȥ��
class Solution {
public:
	//��Ϊ��Ա�����ĺô��ǲ������ô�����ȥ
	vector<int> tmp; //���1���м���  ���2��ѡ�벻ѡ�γɵ�·��
	vector<vector<int>> res; //�洢���

	void backtrack(vector<int>& nums, vector<bool>& vis) {
		if (tmp.size() == nums.size()) {
			res.push_back(tmp); //�Ѿ��γ����м�·��
			return;
		}

		for (int i = 0; i < nums.size(); i++) {
			if (not vis[i]) {
				tmp.push_back(nums[i]);
				vis[i] = true;
				backtrack(nums, vis);
				//����Ԫ��
				tmp.pop_back();
				vis[i] = false;
			}
		}
	}

	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<bool> vis(nums.size(), false);//vis��nums�й�ϵ�����÷�������
		backtrack(nums, vis); //����ֻ��Ҫ��ԭʼ�������Ⱦ�����

		//����setȥ��
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


// ����3��Ԥ������+���÷���˳��
// ֻ����ȫ�����еļ�֦���ټ���һ�������Ϳ�����
class Solution {
public:
	//��Ϊ��Ա�����ĺô��ǲ������ô�����ȥ
	vector<int> tmp; //���1���м���  ���2��ѡ�벻ѡ�γɵ�·��
	vector<vector<int>> res; //�洢���

	void backtrack(vector<int>& nums, vector<bool>& vis) {
		if (tmp.size() == nums.size()) {
			res.push_back(tmp); //�Ѿ��γ����м�·��
			return;
		}
		//  forѭ���������ı�������ʵÿ�ζ�����������֧��ֻ������ǹ��Ĳ����ظ����ʣ�depth�������
		for (int i = 0; i < nums.size(); i++) {
			// ͨ����ͼ��Ҫ���Ϊʲô�����������м�֦��a||b,a�Ǻ�֮ǰһ�����м�֦��b�Ǳ�֤����˳��
			// if (vis[i] || (i+1 <nums.size() && nums[i] == nums[i + 1] && !vis[i+1]))������֦Ҳ����
			if (vis[i] || (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1])) {// ������vis[i-1],������vis[i]
				continue;
			}
			tmp.push_back(nums[i]);
			vis[i] = true;
			backtrack(nums, vis);// �ݹ��ȥ��֧�����䣬ֻ�ǽ����˼�֦
			//����Ԫ��
			tmp.pop_back();
			vis[i] = false;
		}
	}

	// ע�������Ƚ����������
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<bool> vis(nums.size(), false);//vis��nums�й�ϵ�����÷�������
		sort(nums.begin(), nums.end());
		backtrack(nums, vis); //����ֻ��Ҫ��ԭʼ�������Ⱦ�����
		return res;
	}
};