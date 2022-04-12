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
	vector<string> res;
	// 进制转换
	int Atoi(string s, int radix)    //s是给定的radix进制字符串
	{
		int ans = 0;
		for (int i = 0; i < s.size(); i++)
		{
			char t = s[i];
			if (t >= '0'&&t <= '9') ans = ans * radix + t - '0';
			else ans = ans * radix + t - 'a' + 10;
		}
		return ans;
	}
	void DFS(TreeNode* root, string tmp) {
		if (root == nullptr) return;
		// 递归边界
		if (root->left == nullptr&&root->right == nullptr) {
			tmp += to_string(root->val);
			res.push_back(tmp);
			return;
		}
		// 向左子树和右子树进行递归
		DFS(root->left, tmp + to_string(root->val));
		DFS(root->right, tmp + to_string(root->val));
	}
	int sumRootToLeaf(TreeNode* root) {
		DFS(root, "");
		int sum = 0;
		for (auto& e : res) {
			sum += Atoi(e, 2);
		}
		return sum;
	}
};


class Solution {
public:
	vector<string> res;
	void DFS(TreeNode* root, string tmp) {
		if (root == nullptr) return;
		if (root->left == nullptr&&root->right == nullptr) {
			tmp += to_string(root->val);
			res.push_back(tmp);
			return;
		}
		DFS(root->left, tmp + to_string(root->val));
		DFS(root->right, tmp + to_string(root->val));
	}
	int sumRootToLeaf(TreeNode* root) {
		DFS(root, "");
		int sum = 0;
		char *result;// 把参数传进去就好了
		for (auto& e : res) {
			sum += strtol(e.c_str(), &result, 2);// C++中的进制转换函数
		}
		return sum;
	}
};