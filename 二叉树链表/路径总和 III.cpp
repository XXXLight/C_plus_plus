#include<bits/stdc++.h>
#include<unordered_map>
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

class Solution {
public:
	int ans = 0;

	void dfs(TreeNode* root, int sum)//dfs函数的含义，以该节点开始的树存在路径和为sum的个数
	{
		if (root == nullptr)
			return;
		sum -= root->val;
		if (sum == 0)
			ans++;
		dfs(root->left, sum);
		dfs(root->right, sum);

	}

	int pathSum(TreeNode* root, int sum) {
		if (root == nullptr)
			return ans;
		pathSum(root->left, sum);
		pathSum(root->right, sum);
		dfs(root, sum);
		return ans;
	}
};



class Solution {
private:
	unordered_map<int, int> prefix;         // <前缀和，其出现次数>
	void dfs(TreeNode* root, int sum, int cur_sum, int& res)
	{
		if (!root) return;
		cur_sum += root->val;               // 更新前缀和
		// 当前路径中存在以当前节点为终点的和为sum的子路径
		if (prefix.find(cur_sum - sum) != prefix.end())
			res += prefix[cur_sum - sum];
		prefix[cur_sum]++;                  // 将当前节点加入路径
		dfs(root->left, sum, cur_sum, res); // 在其左子树中递归寻找
		dfs(root->right, sum, cur_sum, res);// 在其右子树中递归寻找
		prefix[cur_sum]--;                  // 回溯
	}
public:
	int pathSum(TreeNode* root, int sum)
	{
		int res = 0;    // 满足条件的路径数量
		prefix[0] = 1;  // 前缀和为0的路径只有一条：哪个节点都不选
		dfs(root, sum, 0, res);
		return res;
	}
};

class Solution {
public:
	unordered_map<int, int>mp;
	int res = 0;
	void DFS(TreeNode* root, int targetSum, int curSum) {
		if (root == nullptr) return;
		curSum += root->val;
		if (mp.find(curSum - targetSum) != mp.end())
			res += mp[curSum - targetSum];
		mp[curSum]++;
		DFS(root->left, targetSum, curSum);
		DFS(root->right, targetSum, curSum);
		mp[curSum]--;
	}
	int pathSum(TreeNode* root, int targetSum) {
		if (root == nullptr) return 0;
		mp[0] = 1;
		DFS(root, targetSum, 0);
		return res;
	}
};