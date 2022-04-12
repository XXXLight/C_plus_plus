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

// ����������õ����ݽṹqueue
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		if (root == NULL) return {};
		vector<vector<int>> res;
		queue<TreeNode*> q; //�������ŵ��ǵ�ַ
		q.push(root); // ���ڵ����
		int cnt = 0; // cnt������¼����
		while (!q.empty()) { // ���зǿ�
			int len = q.size(); //���г���
			res.push_back({});
			while (len--) { // �����õ��Ķ���now
				TreeNode* now = q.front(); //now��ʵ�൱�ڱ�����ָ����׵�ָ��
				q.pop();
				res[cnt].push_back(now->val);
				if (now->left) q.push(now->left); //�ŵ�ַ
				if (now->right) q.push(now->right); //�ŵ�ַ
			}
			cnt++; //cnt��λ��
		}
		return res;
	}
};


class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		if (root == nullptr) return {};
		vector<vector<int>> res;
		queue<TreeNode*> q;
		q.push(root);
		// ��BFSҪ����ÿһ��ʱ����Ҫ�ڲ�Ƕ��forѭ��
		while (!q.empty()) {
			res.push_back({});
			int len = q.size();
			while (len--) {
				TreeNode* now = q.front();
				q.pop();
				res.back().push_back(now->val); //���Բ���cnt����¼����
				if (now->left) q.push(now->left);
				if (now->right) q.push(now->right);
			}
		}
		return res;
	}
};