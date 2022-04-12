#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

/*****************************************************************
�������ڵ㶨���Լ������㷨
*****************************************************************/

//���ڵ�Ķ���,Ҫ��д��ʼ���б�
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// ֪ʶ�㣺������������������������
class Solution {
public:
	vector<int> res;
	// ��������洢���
	vector<int> inorder(TreeNode* root) {
		if (root == nullptr) return {};
		inorder(root->left);
		res.push_back(root->val);
		inorder(root->right);
		return res;
	}
	int kthLargest(TreeNode* root, int k) {
		vector<int> r = inorder(root);
		reverse(r.begin(), r.end());
		return r[k - 1];
	}
};
