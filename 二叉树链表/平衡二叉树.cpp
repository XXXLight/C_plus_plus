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
	int height(TreeNode* root) {
		if (root == nullptr) return 0;
		return max(height(root->left), height(root->right)) + 1;
	}
	bool isBalanced(TreeNode* root) {
		if (root == nullptr) return true;
		if (abs(height(root->left) - height(root->right)) > 1) return false; // �ٷ���
		return isBalanced(root->left) && isBalanced(root->right);
	}
};


// ע������д���Ǵ���ģ��������뵱Ȼ
class Solution {
public:
	int depth(TreeNode* root) {
		if (!root) return 0;
		return max(depth(root->left), depth(root->right)) + 1;
	}
	bool isBalanced(TreeNode* root) {
		if (!root) return true;
		if (abs(depth(root->left) - depth(root->right)) <= 1) return true; //һ������ƽ�ⲻ��֤������ƽ��
		else if (abs(depth(root->left) - depth(root->right)) > 1) return false;
		return isBalanced(root->left) && isBalanced(root->right);
	}
};