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

//����ڵ�Ķ���
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		if (root == NULL) return {};
		vector<vector<int>> res; // ���
		queue<TreeNode*> q; //���д�ŵ�ַ
		q.push(root);
		int cnt = 0;
		while (!q.empty()) {
			res.push_back({}); // ��Ԫ��ռλ
			for (int i = q.size(); i > 0; i--) {
				TreeNode* now = q.front();
				q.pop();
				res[cnt].push_back(now->val);
				if (now->left) q.push(now->left);
				if (now->right) q.push(now->right);
			}
			cnt++;
		}
		return res;
	}
	ListNode* change(vector<int>&v) {
		ListNode* h = new ListNode(-1);
		ListNode* p = h;
		for (auto e : v) {
			ListNode* tmp = new ListNode(e);
			p->next = tmp;
			p = p->next;
		}
		return h->next;
	}
	vector<ListNode*> listOfDepth(TreeNode* tree) {
		vector<vector<int>> r = levelOrder(tree);
		vector<ListNode*> res;
		for (auto e : r) {
			ListNode* tmp = change(e);
			res.push_back(tmp);
		}
		return res;
	}
};