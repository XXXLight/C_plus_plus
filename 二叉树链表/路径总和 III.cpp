#include<bits/stdc++.h>
#include<unordered_map>
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
	int ans = 0;

	void dfs(TreeNode* root, int sum)//dfs�����ĺ��壬�Ըýڵ㿪ʼ��������·����Ϊsum�ĸ���
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
	unordered_map<int, int> prefix;         // <ǰ׺�ͣ�����ִ���>
	void dfs(TreeNode* root, int sum, int cur_sum, int& res)
	{
		if (!root) return;
		cur_sum += root->val;               // ����ǰ׺��
		// ��ǰ·���д����Ե�ǰ�ڵ�Ϊ�յ�ĺ�Ϊsum����·��
		if (prefix.find(cur_sum - sum) != prefix.end())
			res += prefix[cur_sum - sum];
		prefix[cur_sum]++;                  // ����ǰ�ڵ����·��
		dfs(root->left, sum, cur_sum, res); // �����������еݹ�Ѱ��
		dfs(root->right, sum, cur_sum, res);// �����������еݹ�Ѱ��
		prefix[cur_sum]--;                  // ����
	}
public:
	int pathSum(TreeNode* root, int sum)
	{
		int res = 0;    // ����������·������
		prefix[0] = 1;  // ǰ׺��Ϊ0��·��ֻ��һ�����ĸ��ڵ㶼��ѡ
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