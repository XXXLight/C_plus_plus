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

//	对称二叉树的思路：拷贝两份一样的树进行比较（WHY?）
class Solution {
public:
	// check函数功能：检查两棵树是否对称
	bool check(TreeNode* root1, TreeNode* root2) {
		if (root1 == nullptr&&root2 == nullptr) return true; //都为空树，对称
		if (root1 == nullptr || root2 == nullptr) return false;//1空1非空，肯定不对称
		return root1->val == root2->val&&check(root1->left, root2->right) && check(root1->right, root2->left);//节点值相同，左与右对称，右与左对称（宏观整体）
	}
	bool isSymmetric(TreeNode* root) {
		return check(root, root);
	}
};

// 用层序遍历的方法存放到二维数组里，对二维数组进行检查验证即可
class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (root == NULL) return true;
		queue<TreeNode*> que;
		que.push(root->left);   // 将左子树头结点加入队列
		que.push(root->right);  // 将右子树头结点加入队列
		while (!que.empty()) {  // 接下来就要判断这这两个树是否相互翻转
			TreeNode* leftNode = que.front(); que.pop();
			TreeNode* rightNode = que.front(); que.pop();
			if (!leftNode && !rightNode) {  // 左节点为空、右节点为空，此时说明是对称的
				continue;
			}

			// 左右一个节点不为空，或者都不为空但数值不相同，返回false
			if ((!leftNode || !rightNode || (leftNode->val != rightNode->val))) {
				return false;
			}
			que.push(leftNode->left);   // 加入左节点左孩子
			que.push(rightNode->right); // 加入右节点右孩子
			que.push(leftNode->right);  // 加入左节点右孩子
			que.push(rightNode->left);  // 加入右节点左孩子
		}
		return true;
	}
};

class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (root == NULL) return true;
		stack<TreeNode*> st; // 这里改成了栈
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
