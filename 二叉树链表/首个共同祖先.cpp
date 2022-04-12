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

// 所有所谓公共祖先直接用这个代码就完事了
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (q == root || p == root || root == nullptr) return root; // （1）
		// 在左子树中找公共祖先
		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		// 在右子树中找公共祖先
		TreeNode* right = lowestCommonAncestor(root->right, p, q);
		// left、right同时存在，肯定就是根节点了
		// 当p、q在两边时，left、right的返回值就是p、q，因为第一句（1）
		if (left && right) return root; //这句话一定要理解
		// 不为空的就是答案了
		return left ? left : right;
	}
};
