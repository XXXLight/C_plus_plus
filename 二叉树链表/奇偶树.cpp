#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

/*****************************************************************
二叉树节点定义以及各种算法
*****************************************************************/

//树节点的定义,要会写初始化列表
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
	// 层序遍历存储结果
	vector<vector<int>> levelOrder(TreeNode* root) {
		if (root == NULL) return {};
		vector<vector<int>> res;
		queue<TreeNode*> q;
		q.push(root);
		int cnt = 0;
		while (!q.empty()) {
			int len = q.size();
			res.push_back({});
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
	// 是否严格递增
	bool test_bigger(vector<int>& v) {
		int len = v.size();
		for (int i = 0; i < len - 1; i++) {
			if (v[i] < v[i + 1]) continue;
			else return false;
		}
		for (auto v1 : v) {
			if (v1 % 2 == 0) return false;
		}
		return true;
	}

	// 是否严格递减
	bool test_lower(vector<int>& v) {
		int len = v.size();
		for (int i = 0; i < len - 1; i++) {
			if (v[i] > v[i + 1]) continue;
			else return false;
		}
		for (auto v1 : v) {
			if (v1 % 2 != 0) return false;
		}
		return true;
	}

	bool test_vv(vector<vector<int>>& vv) {
		for (int i = 0; i < vv.size(); i++) {
			if (i % 2 == 0) {
				if (test_bigger(vv[i])) continue;
				else return false;
			}
			else {
				if (test_lower(vv[i])) continue;
				else return false;
			}
		}
		return true;
	}
	bool isEvenOddTree(TreeNode* root) {
		vector<vector<int>> r = levelOrder(root);
		return test_vv(r);
	}
};
