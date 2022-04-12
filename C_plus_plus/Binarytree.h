#pragma once
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

/*****************************************************************
二叉树节点定义以及各种算法
*****************************************************************/

//树节点的定义,要会写初始化列表
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 

//先序遍历，递归版本
void preOrderTraversal(vector<int> &store, TreeNode *root) {
	if (!root) return;
	store.push_back(root->val);
	preOrderTraversal(store, root->left);   //左孩子优先
	preOrderTraversal(store, root->right);
};


//先序遍历，迭代版本
void preOrderTraversal(vector<int> &store, TreeNode *root) {
	stack<TreeNode *> S;
	S.push(root);
	while (!S.empty()) {
		TreeNode *curr_node = S.top();
		S.pop();
		if (curr_node) {
			store.push_back(curr_node->val);
			S.push(curr_node->right);   //左孩子优先，所以右孩子先入栈
			S.push(curr_node->left);
		}
	}
	return;
}



//中序遍历，递归版本
void inOrderTraversal(vector<int> &store, TreeNode *root) {
	if (!root) return;
	inOrderTraversal(store, root->left);
	store.push_back(root->val);
	inOrderTraversal(store, root->right);
	return;
}



//中序遍历，迭代版本
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



//后序遍历，递归版本
void postOrderTraversal(vector<int> &store, TreeNode *root) {
	if (!root) return;
	postOrderTraversal(store, root->left);  //右孩子优先
	postOrderTraversal(store, root->right);
	store.push_back(root->val);
}



//后序遍历，迭代版本
void postOrderTraversal(vector<int> &store, TreeNode *root) {
	stack<TreeNode *> S;
	S.push(root);
	while (!S.empty()) {
		TreeNode *curr_node = S.top();
		S.pop();
		if (curr_node) {
			store.push_back(curr_node->val);
			S.push(curr_node->left);    //右孩子优先，所以左孩子先入栈
			S.push(curr_node->right);
		}
	}
	std::reverse(store.begin(), store.end());   //逆序列即为所求
	return;
}



//层序遍历
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



//树的深度
//递归版本
int TreeDepth(TreeNode *pRoot) {
	return pRoot ? 1 + max(TreeDepth(pRoot->left),
		TreeDepth(pRoot->right)) : 0;
}
//迭代版本
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
	return depth - 1;   //将叶节点的空孩子节点也算作一层了，所以减1
}



//树的子结构
bool isSubtree(TreeNode *pRoot1, TreeNode *pRoot2) {
	//判断以pRoot2为根节点的树是否是以pRoot1为根节点的树的子树
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



//重建二叉树，前序和中序
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



//按之字形顺序打印二叉树
vector<vector<int>> Print(TreeNode *pRoot) {
	if (!pRoot) return {};
	vector<vector<int>> result;
	stack<TreeNode *> odd, even;
	even.push(pRoot);		//从第零行开始
	while (!even.empty() || !odd.empty()) {
		vector<int> line;
		if (odd.empty()) {
			while (!even.empty()) {
				TreeNode *curr_node = even.top();
				even.pop();
				line.push_back(curr_node->val);
				if (curr_node->left) odd.push(curr_node->left);
				if (curr_node->right) odd.push(curr_node->right);	//注意，先左后右
			}
		}
		else {
			while (!odd.empty()) {
				TreeNode *curr_node = odd.top();
				odd.pop();
				line.push_back(curr_node->val);
				if (curr_node->right) even.push(curr_node->right);
				if (curr_node->left) even.push(curr_node->left);		//注意，先右后左
			}
		}
		result.push_back(line);
	}
	return result;
}



//二叉树中和为某一值的路径
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
	store.pop_back();		//回溯
}
vector<vector<int>> FindPath(TreeNode *root, int expectNumber) {
	vector<vector<int>> vec_store;
	vector<int> store;
	if (root) FindPath(vec_store, store, root, expectNumber);
	return vec_store;
}



//把二叉树打印成多行
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
	store.pop_back();   //将叶节点的空孩子节点也算作一层了，所以pop_back()
	return store;
}




