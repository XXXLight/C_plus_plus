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

// ʱ�临�Ӷ� O(MN) �� ���� M,N �ֱ�Ϊ�� A �� �� B �Ľڵ�����
// �ռ临�Ӷ� O(M) �� ���� A ���� B ���˻�Ϊ����ʱ���ݹ����������
class Solution {
public:
	bool isSubStructure(TreeNode* A, TreeNode* B) {
		// ��һ����Ϊ�վͷ���false
		if (A == NULL || B == NULL) return false;
		// Ҫô����������B��Ҫô����������B��Ҫô����������B
		return isSame(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
	}
	// A�Ƿ�B
	bool isSame(TreeNode* A, TreeNode* B) {
		// ������������˳�򻹲��ܽ�����Ҫ��Ȼ�ᱨ��
		// B�գ�A�϶�����B
		if (B == NULL) return true;
		// A�գ�A�϶�������B
		if (A == NULL) return false;
		return (A->val == B->val) && (isSame(A->left, B->left)) && (isSame(A->right, B->right));
	}
};