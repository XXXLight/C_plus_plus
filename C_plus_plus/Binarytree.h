#pragma once
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
 

//����������ݹ�汾
void preOrderTraversal(vector<int> &store, TreeNode *root) {
	if (!root) return;
	store.push_back(root->val);
	preOrderTraversal(store, root->left);   //��������
	preOrderTraversal(store, root->right);
};


//��������������汾
void preOrderTraversal(vector<int> &store, TreeNode *root) {
	stack<TreeNode *> S;
	S.push(root);
	while (!S.empty()) {
		TreeNode *curr_node = S.top();
		S.pop();
		if (curr_node) {
			store.push_back(curr_node->val);
			S.push(curr_node->right);   //�������ȣ������Һ�������ջ
			S.push(curr_node->left);
		}
	}
	return;
}



//����������ݹ�汾
void inOrderTraversal(vector<int> &store, TreeNode *root) {
	if (!root) return;
	inOrderTraversal(store, root->left);
	store.push_back(root->val);
	inOrderTraversal(store, root->right);
	return;
}



//��������������汾
void inorderTraversal(vector<int> &store, TreeNode* root) {
	stack<TreeNode *> S;
	while (root || !S.empty()) {
		while (root) {
			S.push(root);
			root = root->left;
		}
		TreeNode *curr_node = S.top();
		S.pop();
		store.push_back(curr_node->val);
		root = curr_node->right;
	}
	return;
}



//����������ݹ�汾
void postOrderTraversal(vector<int> &store, TreeNode *root) {
	if (!root) return;
	postOrderTraversal(store, root->left);  //�Һ�������
	postOrderTraversal(store, root->right);
	store.push_back(root->val);
}



//��������������汾
void postOrderTraversal(vector<int> &store, TreeNode *root) {
	stack<TreeNode *> S;
	S.push(root);
	while (!S.empty()) {
		TreeNode *curr_node = S.top();
		S.pop();
		if (curr_node) {
			store.push_back(curr_node->val);
			S.push(curr_node->left);    //�Һ������ȣ�������������ջ
			S.push(curr_node->right);
		}
	}
	std::reverse(store.begin(), store.end());   //�����м�Ϊ����
	return;
}



//�������
void levelOrderTraversal(vector<int> &store, TreeNode *root) {
	queue<TreeNode *> Q;
	Q.push(root);
	while (!Q.empty()) {
		TreeNode *curr_node = Q.front();
		Q.pop();
		if (curr_node) {
			store.push_back(curr_node->val);
			Q.push(curr_node->left);
			Q.push(curr_node->right);
		}
	}
	return;
}



//�������
//�ݹ�汾
int TreeDepth(TreeNode *pRoot) {
	return pRoot ? 1 + max(TreeDepth(pRoot->left),
		TreeDepth(pRoot->right)) : 0;
}
//�����汾
int TreeDepth2(TreeNode *pRoot) {
	queue<TreeNode *> Q;
	Q.push(pRoot);
	int depth = 0;
	while (!Q.empty()) {
		int len = Q.size();
		++depth;
		while (len--) {
			TreeNode *curr_node = Q.front();
			Q.pop();
			if (curr_node) {
				Q.push(curr_node->left);
				Q.push(curr_node->right);
			}
		}
	}
	return depth - 1;   //��Ҷ�ڵ�Ŀպ��ӽڵ�Ҳ����һ���ˣ����Լ�1
}



//�����ӽṹ
bool isSubtree(TreeNode *pRoot1, TreeNode *pRoot2) {
	//�ж���pRoot2Ϊ���ڵ�����Ƿ�����pRoot1Ϊ���ڵ����������
	if (!pRoot2) return true;
	if (!pRoot1) return false;
	return pRoot1->val != pRoot2->val ? false :
		isSubtree(pRoot1->left, pRoot2->left) &&
		isSubtree(pRoot1->right, pRoot2->right);
}
bool HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2) {
	if (!pRoot1 || !pRoot2) return false;
	return isSubtree(pRoot1, pRoot2) ||
		isSubtree(pRoot1->left, pRoot2) ||
		isSubtree(pRoot1->right, pRoot2);
}



//�ؽ���������ǰ�������
TreeNode *reConstructBinaryTree(vector<int>::iterator pre_first,
	vector<int>::iterator pre_last,
	vector<int>::iterator vin_first,
	vector<int>::iterator vin_last) {
	if (vin_last - vin_first != pre_last - pre_first ||
		pre_last == pre_first ||
		vin_first == vin_last) {
		return nullptr;
	}
	TreeNode *curr_node = new TreeNode(*pre_first);
	if (pre_last == pre_first + 1) return curr_node;
	auto iter = vin_first;
	while (iter < vin_last) {
		if (*iter == *pre_first) break;
		iter++;
	}
	int len = iter - vin_first;
	curr_node->left = reConstructBinaryTree(pre_first + 1, pre_first + len + 1, vin_first, iter);
	curr_node->right = reConstructBinaryTree(pre_first + len + 1, pre_last, iter + 1, vin_last);
	return curr_node;
}
TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin) {
	return reConstructBinaryTree(pre.begin(), pre.end(), vin.begin(), vin.end());
}



//��֮����˳���ӡ������
vector<vector<int>> Print(TreeNode *pRoot) {
	if (!pRoot) return {};
	vector<vector<int>> result;
	stack<TreeNode *> odd, even;
	even.push(pRoot);		//�ӵ����п�ʼ
	while (!even.empty() || !odd.empty()) {
		vector<int> line;
		if (odd.empty()) {
			while (!even.empty()) {
				TreeNode *curr_node = even.top();
				even.pop();
				line.push_back(curr_node->val);
				if (curr_node->left) odd.push(curr_node->left);
				if (curr_node->right) odd.push(curr_node->right);	//ע�⣬�������
			}
		}
		else {
			while (!odd.empty()) {
				TreeNode *curr_node = odd.top();
				odd.pop();
				line.push_back(curr_node->val);
				if (curr_node->right) even.push(curr_node->right);
				if (curr_node->left) even.push(curr_node->left);		//ע�⣬���Һ���
			}
		}
		result.push_back(line);
	}
	return result;
}



//�������к�Ϊĳһֵ��·��
void FindPath(vector<vector<int>> &vec_store,
	vector<int> store,
	TreeNode *root,
	int expNumber) {
	store.push_back(root->val);
	if (!root->left && !root->right) {
		if (expNumber == root->val) vec_store.push_back(store);
		return;
	}
	if (root->left)
		FindPath(vec_store, store, root->left, expNumber - root->val);
	if (root->right)
		FindPath(vec_store, store, root->right, expNumber - root->val);
	store.pop_back();		//����
}
vector<vector<int>> FindPath(TreeNode *root, int expectNumber) {
	vector<vector<int>> vec_store;
	vector<int> store;
	if (root) FindPath(vec_store, store, root, expectNumber);
	return vec_store;
}



//�Ѷ�������ӡ�ɶ���
vector<vector<int>> Print(TreeNode *pRoot) {
	vector<vector<int>> store;
	queue<TreeNode *> Q;
	Q.push(pRoot);
	int index = 0;
	while (!Q.empty()) {
		int length = Q.size();
		store.push_back(vector<int>());
		while (length--) {
			TreeNode *curr_node = Q.front();
			Q.pop();
			if (curr_node) {
				store[index].push_back(curr_node->val);
				Q.push(curr_node->left);
				Q.push(curr_node->right);
			}
		}
		++index;
	}
	store.pop_back();   //��Ҷ�ڵ�Ŀպ��ӽڵ�Ҳ����һ���ˣ�����pop_back()
	return store;
}




