#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
	// ���ڣ�bit��������������ʹ�õĵ����е���ĸ����ͳ�Ƴ���
	vector<int> group(vector<string>& words, int bit)
	{
		vector<int> g(26, 0);
		for (int i = 0; i < words.size(); i++)
		{
			if (!(bit & (1 << i))) continue;
			for (auto c : words[i])
			{
				g[c - 'a']++;
			}
		}
		return g;
	}

	// ���ݹ������÷�
	int calcScore(vector<int>& group, vector<int>& lettercnt, vector<int>& score)
	{
		int s = 0;
		for (int j = 0; j < 26; j++)
		{
			if (lettercnt[j] < group[j]) return 0;
			s += group[j] * score[j];
		}
		return s;
	}

	int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score)
	{
		// ͳ�Ƹ�������ĸ������
		vector<int> lettercnt(26, 0);
		for (auto c : letters)
		{
			lettercnt[c - 'a']++;
		}

		int ans = 0;
		for (int i = 0; i < (1 << words.size()); i++)
		{
			auto g = group(words, i);
			ans = max(ans, calcScore(g, lettercnt, score));
		}
		return ans;
	}


};