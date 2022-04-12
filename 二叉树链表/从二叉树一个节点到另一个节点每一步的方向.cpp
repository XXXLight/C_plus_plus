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
	bool check(TreeNode* root, int x, string& str) {
		if (root->val == x) return true;
		if (root->left) {
			str.push_back('L');
			if (check(root->left, x, str)) return true;
			str.pop_back();
		}
		if (root->right) {
			str.push_back('R');
			if (check(root->right, x, str)) return true;
			str.pop_back();
		}
		return false;
	}
	string getDirections(TreeNode* root, int startValue, int destValue) {
		string str1, str2;
		check(root, startValue, str1);
		check(root, destValue, str2);
		reverse(str1.begin(), str1.end()); reverse(str2.begin(), str2.end());
		while (str1.size() && str2.size() && str1.back() == str2.back()) {
			str1.pop_back();
			str2.pop_back();
		}
		reverse(str1.begin(), str1.end()); reverse(str2.begin(), str2.end());
		string ans = string(str1.size(), 'U') + str2;
		return ans;

	}
};

