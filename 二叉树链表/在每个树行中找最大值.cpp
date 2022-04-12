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
	vector<int> largestValues(TreeNode* root) {
		vector<int> res;
		if (!root) return res;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			int len = q.size();
			int ans = INT_MIN;
			while (len--) {
				TreeNode* temp = q.front();
				q.pop();
				ans = max(ans, temp->val);
				if (temp->left) q.push(temp->left);
				if (temp->right) q.push(temp->right);
			}
			res.push_back(ans);
		}
		return res;
	}
};