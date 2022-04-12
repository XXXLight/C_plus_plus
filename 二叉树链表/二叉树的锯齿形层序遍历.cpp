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
	vector<vector<int>> levelOrder(TreeNode* root) {
		if (not root) return {};
		vector<vector<int>> res;
		queue<TreeNode*> q;
		q.push(root);
		int cnt = 0;
		while (!q.empty()) {
			res.push_back({});
			int len = q.size();
			while (len--) {
				TreeNode* now = q.front();
				q.pop();
				res[cnt].push_back(now->val);
				if (now->left) q.push(now->left);
				if (now->right) q.push(now->right);
			}
			cnt++;
		}
		return res;
	}
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		// ���ò���������
		vector<vector<int>> res = levelOrder(root);
		vector<vector<int>> r;
		for (int i = 0; i < res.size(); i++) {
			if (not (i & 1)) { // ������Ҫע�⣬not (i & 1)��not i & 1��ȫ��һ��
				r.push_back(res[i]);
			}
			else if (i & 1) {
				reverse(res[i].begin(), res[i].end());
				r.push_back(res[i]);
			}
		}
		return r;
	}
};