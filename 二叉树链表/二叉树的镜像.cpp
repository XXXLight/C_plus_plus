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
	TreeNode* mirrorTree(TreeNode* root) {
		if (!root) return nullptr;
		// ��߾�����
		mirrorTree(root->left);
		// �ұ߾�����
		mirrorTree(root->right);
		// �������ҽڵ�
		swap(root->left, root->right);
		return root;
	}
};

// ��۵����,�Եݹ�����
class Solution {
public:
	TreeNode* mirrorTree(TreeNode* root) {
		if (root == nullptr) return nullptr;
		// �����ǵ�ַ
		swap(root->left, root->right);
		// �ݹ���ȥ
		mirrorTree(root->left);// ���������
		mirrorTree(root->right);// �������ұ�
		return root;
	}
};