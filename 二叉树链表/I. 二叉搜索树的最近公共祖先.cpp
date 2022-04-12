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
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		// 都在左子树上，公共祖先是左叶子节点
		if ((p->val < root->val) && (q->val < root->val))  return lowestCommonAncestor(root->left, p, q);
		// 都在右子树上，公共祖先是右叶子节点
		else if ((p->val > root->val) && (q->val > root->val)) return lowestCommonAncestor(root->right, p, q);
		// 一左一右，就是根节点
		else return root;
	}
};