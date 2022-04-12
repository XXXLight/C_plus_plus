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
	int height(TreeNode* root) {
		if (root == nullptr) return 0;
		return max(height(root->left), height(root->right)) + 1;
	}
	bool isBalanced(TreeNode* root) {
		if (root == nullptr) return true;
		if (abs(height(root->left) - height(root->right)) > 1) return false; // 举反例
		return isBalanced(root->left) && isBalanced(root->right);
	}
};


// 注意以下写法是错误的，很容易想当然
class Solution {
public:
	int depth(TreeNode* root) {
		if (!root) return 0;
		return max(depth(root->left), depth(root->right)) + 1;
	}
	bool isBalanced(TreeNode* root) {
		if (!root) return true;
		if (abs(depth(root->left) - depth(root->right)) <= 1) return true; //一个子树平衡不能证明该树平衡
		else if (abs(depth(root->left) - depth(root->right)) > 1) return false;
		return isBalanced(root->left) && isBalanced(root->right);
	}
};