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

// 层序遍历所用的数据结构queue
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		if (root == NULL) return {};
		vector<vector<int>> res;
		queue<TreeNode*> q; //队列里存放的是地址
		q.push(root); // 根节点入队
		int cnt = 0; // cnt用来记录层数
		while (!q.empty()) { // 队列非空
			int len = q.size(); //队列长度
			res.push_back({});
			while (len--) { // 里面用到的都是now
				TreeNode* now = q.front(); //now其实相当于变量，指向队首的指针
				q.pop();
				res[cnt].push_back(now->val);
				if (now->left) q.push(now->left); //放地址
				if (now->right) q.push(now->right); //放地址
			}
			cnt++; //cnt的位置
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
		// 当BFS要处理每一层时就需要内部嵌入for循环
		while (!q.empty()) {
			res.push_back({});
			int len = q.size();
			while (len--) {
				TreeNode* now = q.front();
				q.pop();
				res.back().push_back(now->val); //可以不用cnt来记录层数
				if (now->left) q.push(now->left);
				if (now->right) q.push(now->right);
			}
		}
		return res;
	}
};