#include<bits/stdc++.h>
using namespace std;


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
	vector<vector<int>> verticalTraversal(TreeNode* root) {
		// col, depth, val
		map<int, vector<pair<int, int>>> mym;
		vector<vector<int>> res;
		queue<pair<TreeNode*, int>> myq;
		if (root == NULL)
			return res;
		myq.push(make_pair(root, 0));
		int depth = 0;
		while (!myq.empty())
		{
			int cnt = myq.size();
			// ����ĳһ������н��
			while (cnt--)
			{
				pair<TreeNode*, int>& cur = myq.front();
				// cur ���ݶ԰��� �����ָ�룬���������
				// ��Ӧ�����ҽ��������Ҫ -1 / +1
				if ((cur.first)->left)
					myq.push(make_pair((cur.first)->left, cur.second - 1));
				if ((cur.first)->right)
					myq.push(make_pair((cur.first)->right, cur.second + 1));
				mym[cur.second].push_back(make_pair(depth, cur.first->val));
				myq.pop();
			}
			++depth;
		}
		res.resize(mym.size());
		int index = 0;
		for (auto&[k, vec] : mym)
		{
			res[index].resize(vec.size());
			sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
				if (a.first == b.first)
					return a.second < b.second;
				return a.first < b.first;
			});
			for (int i = 0; i < vec.size(); ++i)
				res[index][i] = vec[i].second;
			++index;
		}
		return res;
	}
};

