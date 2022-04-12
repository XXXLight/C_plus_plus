#include<bits/stdc++.h>
#include<unordered_map>
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
	unordered_map<int, int> mp;
	TreeNode* build(vector<int>& preorder, vector<int>& inorder, int preL, int preR, int inL, int inR) {
		if (preL > preR) return nullptr;
		int preRoot = preL;
		int inRoot = mp[preorder[preRoot]];
		TreeNode* r = new TreeNode(preorder[preRoot]);
		int num = inRoot - inL;
		r->left = build(preorder, inorder, preL + 1, preL + num, inL, inRoot - 1);
		r->right = build(preorder, inorder, preL + num + 1, preR, inRoot + 1, inR);
		return r;
	}
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int n = preorder.size();
		for (int i = 0; i < n; i++) {
			mp[inorder[i]] = i;
		}
		return build(preorder, inorder, 0, n - 1, 0, n - 1);
	}
};