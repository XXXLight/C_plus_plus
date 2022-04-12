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

//	�Գƶ�������˼·����������һ���������бȽϣ�WHY?��
class Solution {
public:
	// check�������ܣ�����������Ƿ�Գ�
	bool check(TreeNode* root1, TreeNode* root2) {
		if (root1 == nullptr&&root2 == nullptr) return true; //��Ϊ�������Գ�
		if (root1 == nullptr || root2 == nullptr) return false;//1��1�ǿգ��϶����Գ�
		return root1->val == root2->val&&check(root1->left, root2->right) && check(root1->right, root2->left);//�ڵ�ֵ��ͬ�������ҶԳƣ�������Գƣ�������壩
	}
	bool isSymmetric(TreeNode* root) {
		return check(root, root);
	}
};

// �ò�������ķ�����ŵ���ά������Զ�ά������м����֤����
class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (root == NULL) return true;
		queue<TreeNode*> que;
		que.push(root->left);   // ��������ͷ���������
		que.push(root->right);  // ��������ͷ���������
		while (!que.empty()) {  // ��������Ҫ�ж������������Ƿ��໥��ת
			TreeNode* leftNode = que.front(); que.pop();
			TreeNode* rightNode = que.front(); que.pop();
			if (!leftNode && !rightNode) {  // ��ڵ�Ϊ�ա��ҽڵ�Ϊ�գ���ʱ˵���ǶԳƵ�
				continue;
			}

			// ����һ���ڵ㲻Ϊ�գ����߶���Ϊ�յ���ֵ����ͬ������false
			if ((!leftNode || !rightNode || (leftNode->val != rightNode->val))) {
				return false;
			}
			que.push(leftNode->left);   // ������ڵ�����
			que.push(rightNode->right); // �����ҽڵ��Һ���
			que.push(leftNode->right);  // ������ڵ��Һ���
			que.push(rightNode->left);  // �����ҽڵ�����
		}
		return true;
	}
};

class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (root == NULL) return true;
		stack<TreeNode*> st; // ����ĳ���ջ
		st.push(root->left);
		st.push(root->right);
		while (!st.empty()) {
			TreeNode* leftNode = st.top(); st.pop();
			TreeNode* rightNode = st.top(); st.pop();
			if (!leftNode && !rightNode) {
				continue;
			}
			if ((!leftNode || !rightNode || (leftNode->val != rightNode->val))) {
				return false;
			}
			st.push(leftNode->left);
			st.push(rightNode->right);
			st.push(leftNode->right);
			st.push(rightNode->left);
		}
		return true;
	}
};
