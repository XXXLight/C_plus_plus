#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

/*****************************************************************
�������ڵ㶨���Լ������㷨
*****************************************************************/

//���ڵ�Ķ���,Ҫ��д��ʼ���б�
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



class Solution {
public:
	vector<string> res;
	// ����ת��
	int Atoi(string s, int radix)    //s�Ǹ�����radix�����ַ���
	{
		int ans = 0;
		for (int i = 0; i < s.size(); i++)
		{
			char t = s[i];
			if (t >= '0'&&t <= '9') ans = ans * radix + t - '0';
			else ans = ans * radix + t - 'a' + 10;
		}
		return ans;
	}
	void DFS(TreeNode* root, string tmp) {
		if (root == nullptr) return;
		// �ݹ�߽�
		if (root->left == nullptr&&root->right == nullptr) {
			tmp += to_string(root->val);
			res.push_back(tmp);
			return;
		}
		// �������������������еݹ�
		DFS(root->left, tmp + to_string(root->val));
		DFS(root->right, tmp + to_string(root->val));
	}
	int sumRootToLeaf(TreeNode* root) {
		DFS(root, "");
		int sum = 0;
		for (auto& e : res) {
			sum += Atoi(e, 2);
		}
		return sum;
	}
};


class Solution {
public:
	vector<string> res;
	void DFS(TreeNode* root, string tmp) {
		if (root == nullptr) return;
		if (root->left == nullptr&&root->right == nullptr) {
			tmp += to_string(root->val);
			res.push_back(tmp);
			return;
		}
		DFS(root->left, tmp + to_string(root->val));
		DFS(root->right, tmp + to_string(root->val));
	}
	int sumRootToLeaf(TreeNode* root) {
		DFS(root, "");
		int sum = 0;
		char *result;// �Ѳ�������ȥ�ͺ���
		for (auto& e : res) {
			sum += strtol(e.c_str(), &result, 2);// C++�еĽ���ת������
		}
		return sum;
	}
};