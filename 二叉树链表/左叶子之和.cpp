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

// ������������ۣ�
// ���� ��ֻ���Ұ�� �����ֻ��һ��Ҷ�ڵ� ���ұ߶��кܶ�ڵ�
class Solution {
public:
	int sumOfLeftLeaves(TreeNode* root) {
		if (root == NULL) return 0;
		// �������Ѿ����ǿ�����
		if (root->left == NULL) return sumOfLeftLeaves(root->right);
		// ��������Ҷ�ӿ϶�Ҳ��Ϊ��
		if (root->left->left == NULL && root->left->right == NULL) return root->left->val + sumOfLeftLeaves(root->right);
		// ��������Ҷ������϶��нڵ�
		return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
	}
};

// sumOfLeftLeaves��������������
class Solution {
public:
	int sumOfLeftLeaves(TreeNode* root) {
		return sumOfLeftLeaves(root, false);
	}
	// �ഫһ��flag��ȥ
	int sumOfLeftLeaves(TreeNode* root, bool flag) {
		if (root == nullptr) {
			return 0;
		}
		// ��Ҷ��
		if (flag && root->left == nullptr && root->right == nullptr) {
			return root->val;
		}
		// �����ߣ����Ϊtrue
		int leftSum = sumOfLeftLeaves(root->left, true);
		// �����ߣ����Ϊfalse
		int rightSum = sumOfLeftLeaves(root->right, false);
		return leftSum + rightSum;
	}
};
