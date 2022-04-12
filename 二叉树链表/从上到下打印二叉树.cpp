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

//	д���˾ͻᷢ�ֲ�������ܼ򵥣�����������������������
class Solution {
public:
	vector<int> levelOrder(TreeNode* root) {
		if (root == nullptr) return {};
		vector<int> res;
		queue<TreeNode*> q;	//�������ŵ��ǵ�ַ
		q.push(root);
		while (!q.empty()) {
			// BFS����Ҫ��ÿ����д���ʱ����Ҫдforѭ��
			TreeNode* now = q.front();
			res.push_back(now->val);
			if (now->left) q.push(now->left);
			q.pop(); //��仰λ�����⣬ֻҪλ��TreeNode* now = q.front();�󼴿�
			if (now->right) q.push(now->right);
		}
		return res;
	}
};