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

// ���ݹ麯�������ã����ŵݹ麯������������Ӧ���ܣ���������˼��
// �������ĸ߶���ȫһ��
class Solution {
public:
	// �ӿڶ��壺��root��Ϊ���ڵ�Ķ����������нڵ���Ŀ
	int countNodes(TreeNode* root) {
		if (root == nullptr) return 0;
		return countNodes(root->left) + countNodes(root->right) + 1;
	}
};

// �����Ǻ������
class Solution {
private:
	int getNodesNum(TreeNode* cur) {
		if (cur == nullptr) return 0;
		int leftNum = getNodesNum(cur->left);      // ��
		int rightNum = getNodesNum(cur->right);    // ��
		int treeNum = leftNum + rightNum + 1;      // ��
		return treeNum;
	}
public:
	int countNodes(TreeNode* root) {
		return getNodesNum(root);
	}
};

// ʹ�ò�������ķ���
class Solution {
public:
	int countNodes(TreeNode* root) {
		queue<TreeNode*> que;
		if (root != NULL) que.push(root);
		int result = 0;
		while (!que.empty()) {
			int size = que.size();
			for (int i = 0; i < size; i++) {
				TreeNode* node = que.front();
				que.pop();
				result++;   // ��¼�ڵ�����
				if (node->left) que.push(node->left);
				if (node->right) que.push(node->right);
			}
		}
		return result;
	}
};