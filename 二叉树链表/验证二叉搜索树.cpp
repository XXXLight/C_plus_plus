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

// ʱ�临�Ӷȣ�o(n),���� n Ϊ�������Ľڵ��������������ÿ���ڵ���౻����һ�Σ����ʱ�临�Ӷ�Ϊ O(n)O(n)��
// �ռ临�Ӷȣ�o(n)
class Solution {
public:
	vector<int> res;
	vector<int> inorder(TreeNode* root) {
		if (root == nullptr) return {};
		inorder(root->left);
		res.push_back(root->val);
		inorder(root->right);
		return res;
	}
	bool isValidBST(TreeNode* root) {
		vector<int> r = inorder(root);
		for (int i = 0; i < r.size() - 1; i++) {
			if (r[i] >= r[i + 1])
				return false;
		}
		return true;
	}
};