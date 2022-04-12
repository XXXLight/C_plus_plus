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
	TreeNode* mirrorTree(TreeNode* root) {
		if (!root) return nullptr;
		// 左边镜像处理
		mirrorTree(root->left);
		// 右边镜像处理
		mirrorTree(root->right);
		// 交换左右节点
		swap(root->left, root->right);
		return root;
	}
};

// 宏观的理解,对递归的理解
class Solution {
public:
	TreeNode* mirrorTree(TreeNode* root) {
		if (root == nullptr) return nullptr;
		// 换的是地址
		swap(root->left, root->right);
		// 递归下去
		mirrorTree(root->left);// 镜像处理左边
		mirrorTree(root->right);// 镜像处理右边
		return root;
	}
};