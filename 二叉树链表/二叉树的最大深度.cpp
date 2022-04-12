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

// 精简代码很难看出是什么方法进行遍历的
class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (not root) return 0;
		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}
};

// 只能是后序遍历
class Solution {
public:
	int getDepth(TreeNode* node) {
		if (node == NULL) return 0;
		int leftDepth = getDepth(node->left);       // 左
		int rightDepth = getDepth(node->right);     // 右
		int depth = 1 + max(leftDepth, rightDepth); // 中
		return depth;
	}
	int maxDepth(TreeNode* root) {
		return getDepth(root);
	}
};