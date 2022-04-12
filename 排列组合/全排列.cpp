#include<bits/stdc++.h>
using namespace std;

//����
// 1.ȫ���е���ǰ��Ҫ�Ƚ�������
// 2.next_permutation�ķ���ֵ��bool���ͣ�ע�⻹��prev_permutation
// 3.�÷�������ֱ���õ���ȫ����II��ʹ�ã�ֱ��ȥ����
class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		sort(nums.begin(), nums.end());//����������
		vector<vector<int>> res;
		do {
			res.push_back(nums);
		} while (next_permutation(nums.begin(), nums.end()));
		return res;
	}
};

//����������Ҫvis�����������û�з��ʹ�
//��Ӧ����������
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
		//  forѭ���������ı�������ʵÿ�ζ�����������֧��[1,2,3]��ȫ���У���ֻ������ǹ��Ĳ����ظ����ʣ�depth�������,ȫ���������õ�
		for (int i = 0; i < nums.size(); i++) {
			if (vis[i]) continue;
			tmp.push_back(nums[i]);
			vis[i] = true;
			backtrack(nums, vis);// �ݹ��ȥ��֧�����䣬ֻ�ǽ����˼�֦
			//����Ԫ��
			tmp.pop_back();
			vis[i] = false;
		}
	}

	// ע������û���Ƚ���sort����
	vector<vector<int>> permute(vector<int>& nums) {
		vector<bool> vis(nums.size(), false);//vis��nums�й�ϵ�����÷�������
		backtrack(nums, vis); //����ֻ��Ҫ��ԭʼ�������Ⱦ�����
		return res;
	}
};


// swap����
class Solution {
public:
	vector<vector<int>> res;
	void backtrack(vector<int>& nums, int depth, vector<int>&tmp) {
		if (depth == nums.size()) {
			res.push_back(tmp);
		}
		for (int i = depth; i < nums.size(); i++) {
			swap(tmp[i], tmp[depth]);
			backtrack(nums, depth + 1, tmp); // ע��������depth
			swap(tmp[i], tmp[depth]);
		}
	}
	vector<vector<int>> permute(vector<int>& nums) {
		backtrack(nums, 0, nums); // tmp������ԭʼ����
		return res;
	}
};



// �����ǵ��Թ���
class Solution {
public:
	vector<vector<int>> res;
	void backtrack(vector<int>& nums, int depth, vector<int>&tmp) {
		if (depth == nums.size()) {
			res.push_back(tmp);
		}
		for (int i = depth; i < nums.size(); i++) {
			swap(tmp[i], tmp[depth]);
			cout << "����ǰ" << "depth: " << depth << endl;
			for (auto e : tmp) cout << e << " ";
			cout << endl;
			backtrack(nums, depth + 1, tmp); // ע��������depth
			swap(tmp[i], tmp[depth]);
			cout << "��������" << "depth: " << depth << endl;
			for (auto e : tmp) cout << e << " ";
			cout << endl;
		}
	}
	vector<vector<int>> permute(vector<int>& nums) {
		backtrack(nums, 0, nums); // tmp������ԭʼ����
		// ���Ϊʲô��������˳����������
		for (auto v : res) {
			for (auto e : v) {
				cout << e << " ";
			}
			cout << endl;
		}
		return res;
	}
};


// ����Ľ�����յݹ���
class Solution {
public:
	//��Ϊ��Ա�����ĺô��ǲ������ô�����ȥ
	vector<int> tmp; //���1���м���  ���2��ѡ�벻ѡ�γɵ�·��
	vector<vector<int>> res; //�洢���

	void backtrack(vector<int>& nums, vector<bool>& vis, int depth) {
		if (tmp.size() == nums.size()) {
			res.push_back(tmp); //�Ѿ��γ����м�·��
			return;
		}

		for (int i = 0; i < nums.size(); i++) {
			if (vis[i]) continue;
			tmp.push_back(nums[i]);
			vis[i] = true;
			cout << "���" << depth << " ";
			for (auto e : tmp) cout << e << " ";
			cout << endl;
			backtrack(nums, vis, depth + 1);
			//����Ԫ��
			tmp.pop_back();
			vis[i] = false;
			cout << "���" << depth << " ";
			for (auto e : tmp) cout << e << " ";
			cout << endl;
		}
	}

	vector<vector<int>> permute(vector<int>& nums) {
		vector<bool> vis(nums.size(), false);//vis��nums�й�ϵ�����÷�������
		backtrack(nums, vis, 0); //����ֻ��Ҫ��ԭʼ�������Ⱦ�����
		for (auto v : res) {
			for (auto e : v) {
				cout << e << " ";
			}
			cout << endl;
		}
		return res;
	}
};
