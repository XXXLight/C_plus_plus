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

// ������ν��������ֱ������������������
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (q == root || p == root || root == nullptr) return root; // ��1��
		// �����������ҹ�������
		TreeNode* left = lowestCommonAncestor(root->left, p, q);
		// �����������ҹ�������
		TreeNode* right = lowestCommonAncestor(root->right, p, q);
		// left��rightͬʱ���ڣ��϶����Ǹ��ڵ���
		// ��p��q������ʱ��left��right�ķ���ֵ����p��q����Ϊ��һ�䣨1��
		if (left && right) return root; //��仰һ��Ҫ���
		// ��Ϊ�յľ��Ǵ���
		return left ? left : right;
	}
};
