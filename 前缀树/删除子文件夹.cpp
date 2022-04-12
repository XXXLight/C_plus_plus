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
	// �ӽڵ㵽����ӳ��
	unordered_map<string, Node*> str2node;
	// ��ʾ�Ƿ��������
	bool isEnd;
	// ��ǰ����·��������
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
			// ֱ�Ӻ����Ѿ�����end��·���������ʵ����subfolder
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

		// ���ڹ�����ȣ��ٴα����ҳ����н��
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
					// ������Ҫ���ԣ���Ϊ�ҵ���̵�·����
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

