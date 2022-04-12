#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

/*****************************************************************
二叉树节点定义以及各种算法
*****************************************************************/

//树节点的定义,要会写初始化列表
//编辑器会帮你区分相同的left
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {} // 无参构造
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} // 有参构造
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} // 有参构造
};

class Solution {
public:
	vector<int> res;
	vector<int> inorderTraversal(TreeNode* root) {
		if (!root) return {};
		inorderTraversal(root->left);
		res.push_back(root->val);
		inorderTraversal(root->right);
		return res;
	}
};