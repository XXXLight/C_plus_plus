#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;



vector<string> split(const string& str)
{
	stringstream ss(str);
	vector<string> res;
	string curr;
	while (std::getline(ss, curr, '/'))
	{
		if (curr.size() > 0)
		{
			res.push_back(curr);
		}
	}

	return res;
}

struct Node
{
	// 子节点到结点的映射
	unordered_map<string, Node*> str2node;
	// 表示是否完整结点
	bool isEnd;
	// 当前完整路径的名字
	string str;

	void insert(const string& str)
	{
		vector<string> strs = split(str);
		Node* curr = this;

		for (auto& s : strs)
		{
			if (curr->str2node.find(s) == curr->str2node.end())
			{
				curr->str2node[s] = new Node();
			}
			curr = curr->str2node[s];
			// 直接忽略已经存在end的路径，这里就实现了subfolder
			if (curr->isEnd)
			{
				cout << "ignore " << str << endl;
				return;
			}
		}

		curr->isEnd = true;
		curr->str = str;
	}
};

class Solution {
public:
	vector<string> removeSubfolders(vector<string>& folder) {
		vector<string> res;
		Node* root = new Node();

		for (const string & str : folder)
		{
			root->insert(str);
		}

		// 基于广度优先，再次遍历找出所有结点
		queue<Node*> q;
		q.push(root);

		while (!q.empty())
		{
			for (int i = q.size(); i > 0; --i)
			{
				Node* curr = q.front();
				q.pop();
				if (curr->isEnd)
				{
					res.push_back(curr->str);
					// 这里需要忽略，因为找到最短的路径了
					continue;
				}
				for (auto iter = curr->str2node.begin(); iter != curr->str2node.end(); ++iter)
				{
					q.push(iter->second);
				}
			}
		}

		return res;
	}
};

