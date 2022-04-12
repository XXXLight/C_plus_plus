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
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} //	left(nullptr), right(nullptr)һ��Ҫ��
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
	void construct_paths(TreeNode* root, string path, vector<string>& paths) {
		if (root == nullptr) return;
		path += to_string(root->val);
		if (root->left == nullptr && root->right == nullptr) {  // ��ǰ�ڵ���Ҷ�ӽڵ�
			paths.push_back(path);                              // ��·�����뵽����
		}
		else {
			path += "->";  // ��ǰ�ڵ㲻��Ҷ�ӽڵ㣬�����ݹ����
			construct_paths(root->left, path, paths);
			construct_paths(root->right, path, paths);
		}

	}

	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> paths;
		construct_paths(root, "", paths);
		return paths;
	}
};