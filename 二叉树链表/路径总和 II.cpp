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

// 回溯法
class Solution {
public:
	vector<vector<int>> res;
	void dfs(TreeNode* root, vector<int>&tmp, int sum) {
		if (root == NULL) return;
		tmp.push_back(root->val);
		if (root->val == sum && (root->left == NULL && root->right == NULL)) {
			res.push_back(tmp);
		}
		dfs(root->left, tmp, sum - root->val);
		dfs(root->right, tmp, sum - root->val);
		tmp.pop_back();
	}
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<int> tmp;
		dfs(root, tmp, sum);
		return res;
	}
};

// 传值回溯不回溯都行
class Solution {
public:
	vector<vector<int>> res;
	void dfs(TreeNode* root, vector<int> tmp, int sum) {
		if (!root) return;
		tmp.push_back(root->val);
		if (root->val == sum && (root->left == NULL && root->right == NULL)) {
			res.push_back(tmp);
		}
		dfs(root->left, tmp, sum - root->val);
		dfs(root->right, tmp, sum - root->val);
		//tmp.pop_back();
	}
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<int> tmp;
		dfs(root, tmp, sum);
		return res;
	}
};

// 传引用&必须回溯
class Solution {
public:
	vector<vector<int>> res;
	void dfs(TreeNode* root, vector<int>& tmp, int sum) {
		if (!root) return;
		tmp.push_back(root->val);
		if (root->val == sum && (root->left == NULL && root->right == NULL)) {
			res.push_back(tmp);
		}
		dfs(root->left, tmp, sum - root->val);
		dfs(root->right, tmp, sum - root->val);
		tmp.pop_back();
	}
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<int> tmp;
		dfs(root, tmp, sum);
		return res;
	}
};


class Solution {
public:
	vector<int> path;
	vector<vector<int>> res;
	void DFS(TreeNode* root, int targetSum) {
		if (root == nullptr) return;
		path.push_back(root->val);	//这句话必须放在这
		if (root->left == nullptr&&root->right == nullptr&&root->val == targetSum) {
			//path.push_back(root->val);
			res.push_back(path);
			//return;  // 这里没有return 
		}
		DFS(root->left, targetSum - root->val);
		DFS(root->right, targetSum - root->val);
		path.pop_back();
	}
	vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
		DFS(root, targetSum);
		return res;
	}
};