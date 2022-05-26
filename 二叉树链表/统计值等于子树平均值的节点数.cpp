#include<bits/stdc++.h>
using namespace std;



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
	int getCount(TreeNode* root) {
		if (root == nullptr) return 0;
		int l = getCount(root->left);
		int r = getCount(root->right);
		return l + r + 1;
	}
	int getSum(TreeNode* root) {
		if (root == nullptr) return 0;
		return (root->val + getSum(root->left) + getSum(root->right));
	}
	int cnt = 0;
	void dfs(TreeNode* root) {
		if (root == nullptr) return;
		dfs(root->left);
		if (getSum(root) / getCount(root) == root->val) cnt++;
		dfs(root->right);
	}
	int averageOfSubtree(TreeNode* root) {
		dfs(root);
		return cnt;

	}
};




class Solution {
	typedef pair<int, int> pii;
	int ans;
	pii dfs(TreeNode *node) {
		if (node == nullptr) return pii(0, 0);
		pii L = dfs(node->left), R = dfs(node->right);
		int cnt = L.first + R.first + 1, sm = L.second + R.second + node->val;
		if (sm / cnt == node->val) ans++;
		return pii(cnt, sm);
	}

public:
	int averageOfSubtree(TreeNode* root) {
		dfs(root);
		return ans;
	}
};
