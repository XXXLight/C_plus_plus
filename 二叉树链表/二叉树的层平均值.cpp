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
	vector<double> averageOfLevels(TreeNode* root) {
		vector<double> res;
		vector<vector<double>> r;
		if (root == NULL) return {};
		queue<TreeNode*> q;
		q.push(root);
		int cnt = 0; // cnt用来控制层数
		while (!q.empty()) {
			r.push_back({}); // 放元素占位
			int len = q.size();
			while (len--) {
				TreeNode* now = q.front();
				q.pop();
				r[cnt].push_back(now->val);
				if (now->left) q.push(now->left);
				if (now->right) q.push(now->right);
			}
			cnt++;
		}
		for (int i = 0; i < r.size(); i++) {
			double avl = 0;
			double sum = 0;
			for (int j = 0; j < r[i].size(); j++) {
				sum += r[i][j];
			}
			avl = sum / r[i].size();
			res.push_back(avl);
		}
		return res;
	}
};