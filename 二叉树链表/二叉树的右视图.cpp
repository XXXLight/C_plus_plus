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
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} //	left(nullptr), right(nullptr)һ��Ҫ��
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (root == NULL) return {};
		queue<TreeNode*> q;
		q.push(root);
		int cnt = 0;
		while (!q.empty()) {
			res.push_back({});
			for (int i = q.size(); i > 0; i--) {
				TreeNode* now = q.front();
				q.pop();
				res[cnt].push_back(now->val);
				if (now->left != NULL) q.push(now->left);
				if (now->right != NULL) q.push(now->right);
			}
			cnt++;
		}
		return res;
	}
	vector<int> rightSideView(TreeNode* root) {
		vector<int> r;
		vector<vector<int>> res = levelOrder(root);
		for (auto e : res) {
			r.push_back(e.back()); // ���β��
		}
		return r;
	}
};