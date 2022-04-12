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

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		// �����������ϣ�������������Ҷ�ӽڵ�
		if ((p->val < root->val) && (q->val < root->val))  return lowestCommonAncestor(root->left, p, q);
		// �����������ϣ�������������Ҷ�ӽڵ�
		else if ((p->val > root->val) && (q->val > root->val)) return lowestCommonAncestor(root->right, p, q);
		// һ��һ�ң����Ǹ��ڵ�
		else return root;
	}
};