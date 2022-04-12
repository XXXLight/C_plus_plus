#include<bits/stdc++.h>
using namespace std;


class trie
{
public:
	bool isEnd = false;
	trie* next[26] = { NULL };
	void insert(string& s)
	{
		trie *cur = this;
		for (int i = 0; i < s.size(); ++i)
		{
			if (!cur->next[s[i] - 'a'])
				cur->next[s[i] - 'a'] = new trie();
			cur = cur->next[s[i] - 'a'];
		}
		cur->isEnd = true;
	}
};
class Solution {
	trie* t;
	vector<string> ans;
	vector<string> temp;
public:
	vector<string> maxRectangle(vector<string>& words) {
		t = new trie();
		map<int, vector<string>> m;
		int maxlen = 0, maxarea = 0, area;
		for (auto& w : words)
		{
			t->insert(w);//���ʲ���trie
			m[w.size()].push_back(w);//���ʰ����ȷ���
			maxlen = max(maxlen, int(w.size()));//��󵥴ʳ���
		}

		for (auto it = m.rbegin(); it != m.rend(); ++it)
		{	//����������ӳ��ȴ�Ŀ�ʼ
			if (maxarea / (it->first) >= maxlen)
				break;//��ĵ���*��� �����������鲻������
			temp.clear();
			area = 0;
			dfs(it->second, maxarea, maxlen, area);
		}
		return ans;
	}

	void dfs(vector<string>& wd, int& maxarea, int maxlen, int area)
	{
		if (wd[0].size()*maxlen <= maxarea)//�ҵ�������������ˣ��˳���
			return;//����Ż������У�û�лᳬʱ
		vector<bool> res;
		for (int i = 0; i < wd.size(); ++i)
		{
			temp.push_back(wd[i]);
			res = isgood(temp);//�Ƿ�Ϸ�
			if (res[0])//�������¼ӵ���
			{
				area = temp.size()*temp[0].size();
				if (res[1] && area > maxarea)//���ǽ�������
				{	//�������ֵ
					maxarea = area;
					ans = temp;
				}
				dfs(wd, maxarea, maxlen, area);
			}
			// else//������else���еĻ� if�ڵ�dfs������û�л���
			temp.pop_back();
		}
	}

	vector<bool> isgood(vector<string>& tp)
	{
		trie *cur;
		bool allend = true;
		int i, j, n = tp[0].size();
		for (j = 0; j < n; ++j)//������trie�м��
		{
			cur = t;
			for (i = 0; i < tp.size(); ++i)
			{
				if (!cur->next[tp[i][j] - 'a'])
					return { false, false };
				cur = cur->next[tp[i][j] - 'a'];
			}
			allend &= cur->isEnd;
		}
		return { true, allend };//���Լ������롢ÿ�����򵥴ʶ����ֵ���
	}
};

