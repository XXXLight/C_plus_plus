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

//	写多了就会发现层序遍历很简单，真正理解才是王道！！！！
class Solution {
public:
	vector<int> levelOrder(TreeNode* root) {
		if (root == nullptr) return {};
		vector<int> res;
		queue<TreeNode*> q;	//队列里存放的是地址
		q.push(root);
		while (!q.empty()) {
			// BFS不需要对每层进行处理时不需要写for循环
			TreeNode* now = q.front();
			res.push_back(now->val);
			if (now->left) q.push(now->left);
			q.pop(); //这句话位置随意，只要位于TreeNode* now = q.front();后即可
			if (now->right) q.push(now->right);
		}
		return res;
	}
};