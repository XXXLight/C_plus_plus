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

// 分四种情况讨论：
// 空树 树只有右半边 树左边只有一个叶节点 左右边都有很多节点
class Solution {
public:
	int sumOfLeftLeaves(TreeNode* root) {
		if (root == NULL) return 0;
		// 到这里已经不是空树了
		if (root->left == NULL) return sumOfLeftLeaves(root->right);
		// 到这里左叶子肯定也不为空
		if (root->left->left == NULL && root->left->right == NULL) return root->left->val + sumOfLeftLeaves(root->right);
		// 到这里左叶子下面肯定有节点
		return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
	}
};

// sumOfLeftLeaves函数发生了重载
class Solution {
public:
	int sumOfLeftLeaves(TreeNode* root) {
		return sumOfLeftLeaves(root, false);
	}
	// 多传一个flag进去
	int sumOfLeftLeaves(TreeNode* root, bool flag) {
		if (root == nullptr) {
			return 0;
		}
		// 左叶子
		if (flag && root->left == nullptr && root->right == nullptr) {
			return root->val;
		}
		// 往左走，标记为true
		int leftSum = sumOfLeftLeaves(root->left, true);
		// 往右走，标记为false
		int rightSum = sumOfLeftLeaves(root->right, false);
		return leftSum + rightSum;
	}
};
