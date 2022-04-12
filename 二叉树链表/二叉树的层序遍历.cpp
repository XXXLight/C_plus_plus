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
	vector<vector<int>> levelOrder(TreeNode* root) {
		if (root == NULL) return {};
		vector<vector<int>> res; // 结果
		queue<TreeNode*> q; //队列存放地址
		q.push(root);
		int cnt = 0;
		while (!q.empty()) {
			res.push_back({}); // 空元素占位
			for (int i = q.size(); i > 0; i--) {
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
};