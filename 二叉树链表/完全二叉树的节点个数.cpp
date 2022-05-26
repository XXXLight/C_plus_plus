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

// 理解递归函数的作用，相信递归函数可以做到相应功能，即有整体思想
// 和求树的高度完全一样
class Solution {
public:
	// 接口定义：以root作为根节点的二叉树的所有节点数目
	int countNodes(TreeNode* root) {
		if (root == nullptr) return 0;
		return countNodes(root->left) + countNodes(root->right) + 1;
	}
};

// 本质是后序遍历
class Solution {
private:
	int getNodesNum(TreeNode* cur) {
		if (cur == nullptr) return 0;
		int leftNum = getNodesNum(cur->left);      // 左
		int rightNum = getNodesNum(cur->right);    // 右
		int treeNum = leftNum + rightNum + 1;      // 中
		return treeNum;
	}
public:
	int countNodes(TreeNode* root) {
		return getNodesNum(root);
	}
};

// 使用层序遍历的方法
class Solution {
public:
	int countNodes(TreeNode* root) {
		queue<TreeNode*> que;
		if (root != NULL) que.push(root);
		int result = 0;
		while (!que.empty()) {
			int size = que.size();
			for (int i = 0; i < size; i++) {
				TreeNode* node = que.front();
				que.pop();
				result++;   // 记录节点数量
				if (node->left) que.push(node->left);
				if (node->right) que.push(node->right);
			}
		}
		return result;
	}
};