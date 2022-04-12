#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

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
	TreeNode* createBinaryTree(vector<vector<int>>& d) {
		int n = d.size();
		unordered_map<int, TreeNode *> ump;
		unordered_set<int> us;
		for (auto e : d) {
			// 创建每个节点
			if (!ump.count(e[0])) {
				ump[e[0]] = new TreeNode(e[0]);
			}
			if (!ump.count(e[1])) {
				ump[e[1]] = new TreeNode(e[1]);
			}
			// 建树
			if (e[2] == 1) {
				ump[e[0]]->left = ump[e[1]];
			}
			else {
				ump[e[0]]->right = ump[e[1]];
			}
			// 通过us这个结构来找根节点
			us.insert(e[1]);
		}
		// 返回根节点
		for (auto &it : ump) {
			if (!us.count(it.first)) return it.second;
		}
		return NULL;
	}
};