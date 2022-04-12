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

// 时间复杂度：o(n),其中 n 为二叉树的节点个数。二叉树的每个节点最多被访问一次，因此时间复杂度为 O(n)O(n)。
// 空间复杂度：o(n)
class Solution {
public:
	vector<int> res;
	vector<int> inorder(TreeNode* root) {
		if (root == nullptr) return {};
		inorder(root->left);
		res.push_back(root->val);
		inorder(root->right);
		return res;
	}
	bool isValidBST(TreeNode* root) {
		vector<int> r = inorder(root);
		for (int i = 0; i < r.size() - 1; i++) {
			if (r[i] >= r[i + 1])
				return false;
		}
		return true;
	}
};