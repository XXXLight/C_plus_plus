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
	vector<int> tmp;
	vector<vector<int>> res;
	void DFS(TreeNode* root, int target) {
		if (root == nullptr) return;
		tmp.push_back(root->val);
		if (target == root->val&&root->left == nullptr&&root->right == nullptr) res.push_back(tmp);
		DFS(root->left, target - root->val);
		DFS(root->right, target - root->val);
		tmp.pop_back();
	}
	vector<vector<int>> pathSum(TreeNode* root, int target) {
		DFS(root, target);
		return res;
	}
};


// 调试输出看
class Solution {
public:
	vector<int> tmp;
	vector<vector<int>> res;
	void DFS(TreeNode* root, int target) {
		if (root == nullptr) return;
		tmp.push_back(root->val);
		if (target == root->val&&root->left == nullptr&&root->right == nullptr) res.push_back(tmp);
		for (auto e : tmp) cout << e << " ";
		cout << endl;
		DFS(root->left, target - root->val);
		DFS(root->right, target - root->val);
		tmp.pop_back();
		for (auto e : tmp) cout << e << " ";
		cout << endl;
	}
	vector<vector<int>> pathSum(TreeNode* root, int target) {
		DFS(root, target);
		return res;
	}
};