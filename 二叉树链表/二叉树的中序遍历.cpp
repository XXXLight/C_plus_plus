#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

/*****************************************************************
�������ڵ㶨���Լ������㷨
*****************************************************************/

//���ڵ�Ķ���,Ҫ��д��ʼ���б�
//�༭�������������ͬ��left
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {} // �޲ι���
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} // �вι���
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} // �вι���
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