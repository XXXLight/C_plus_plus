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


// 知识点：中序遍历二叉搜索树是有序的
class Solution {
public:
	vector<int> res;
	// 中序遍历存储结果
	vector<int> inorder(TreeNode* root) {
		if (root == nullptr) return {};
		inorder(root->left);
		res.push_back(root->val);
		inorder(root->right);
		return res;
	}
	int kthLargest(TreeNode* root, int k) {
		vector<int> r = inorder(root);
		reverse(r.begin(), r.end());
		return r[k - 1];
	}
};
