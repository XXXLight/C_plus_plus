#include<bits/stdc++.h>
using namespace std;


class UnionFind
{
public:
	unordered_map<string, string> parent;

	UnionFind()
	{
	}

	string Find(string x)
	{
		if (parent[x] != x)
			parent[x] = Find(parent[x]);
		return parent[x];
	}

	void Union(string x, string y)
	{
		string root_x = Find(x);
		string root_y = Find(y);
		parent[root_x] = root_y;
	}
};

class Solution
{
public:
	vector<string> generateSentences(vector<vector<string>>& synonyms, string text)
	{
		UnionFind UF;
		for (auto & v : synonyms)   //初始化
		{
			UF.parent[v[0]] = v[0];
			UF.parent[v[1]] = v[1];
		}
		for (auto & v : synonyms)    //建图
		{
			UF.Union(v[0], v[1]);
		}

		unordered_map<string, set<string>> root_childs;
		for (auto & v : synonyms)
		{
			string root = UF.Find(v[0]);
			root_childs[root].insert(v[0]);
			root_childs[root].insert(v[1]);
		}

		vector<string> t = split(text, ' ');

		vector<vector<string>> res;
		for (string & x : t)
		{
			if (UF.parent.count(x) == 0)
			{
				if (res.size() == 0)
					res.push_back(vector<string>{x});
				else
				{
					for (auto & re : res)
						re.push_back(x);
				}
			}
			else
			{
				string root = UF.Find(x);
				if (res.size() == 0)
				{
					for (auto & y : root_childs[root])
						res.push_back(vector<string>{y});
				}
				else
				{
					vector<vector<string>> tmp;
					for (auto & re : res)
					{
						for (auto & y : root_childs[root])
						{
							auto v = re;
							v.push_back(y);
							tmp.push_back(v);
						}
					}
					res = tmp;
				}
			}
		}
		vector<string> ans;
		for (auto & re : res)
		{
			string tmp = "";
			for (int i = 0; i < re.size(); i++)
			{
				tmp += re[i];
				tmp += ' ';
			}
			tmp.pop_back();
			ans.push_back(tmp);
		}
		return ans;
	}
	//----------切分函数，以c为分割符---------//
	vector<string> split(string s, char c)
	{
		vector<string> res;
		int n = s.size();
		int L = 0;
		int R = 0;
		while (R < n)
		{
			if (s[R] != c)
				R++;
			else
			{
				string word = s.substr(L, R - L);
				res.push_back(word);
				R++;
				L = R;
			}
		}
		if (L != R)
			res.push_back(s.substr(L, R - L));
		return res;
	}
};
