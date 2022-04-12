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

// ���������ѿ�����ʲô�������б�����
class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (not root) return 0;
		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}
};

// ֻ���Ǻ������
class Solution {
public:
	int getDepth(TreeNode* node) {
		if (node == NULL) return 0;
		int leftDepth = getDepth(node->left);       // ��
		int rightDepth = getDepth(node->right);     // ��
		int depth = 1 + max(leftDepth, rightDepth); // ��
		return depth;
	}
	int maxDepth(TreeNode* root) {
		return getDepth(root);
	}
};