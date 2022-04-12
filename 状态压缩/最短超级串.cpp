#include<bits/stdc++.h>
using namespace std;


class Solution {
	int getOverlap(string a, string b)
	{
		int n = a.size();
		int m = b.size();
		int t = min(n, m);
		for (int i = n; i > 0; --i)
		{
			string at = a.substr(n - i, i);
			string bt = b.substr(0, i);
			if (at == bt)
				return i;
		}
		return 0;
	}

public:
	string shortestSuperstring(vector<string>& words) {
		string ret;
		int n = words.size();
		vector<vector<int>> overlap(n, vector<int>(n, 0));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				overlap[i][j] = getOverlap(words[i], words[j]);
			}
			ret += words[i];
		}
		vector<vector<string>> dp(1 << n, vector<string>(n, ret));
		for (uint32_t state = 1; state < (1 << n); state++)
		{
			for (int j = 0; j < n; j++)
			{
				if (state >> j & 1)
				{
					uint32_t preState = (state ^ (1 << j));
					if (preState == 0)
					{
						dp[state][j] = words[j];
					}
					else
					{
						for (int i = 0; i < n; i++)
						{
							if (state >> i & 1)
							{
								if (j == i)
									continue;
								int t = dp[preState][i].size() + words[j].size() - overlap[i][j];
								if (dp[state][j].size() > t)
									dp[state][j] = dp[preState][i] + words[j].substr(overlap[i][j], words[j].size() - overlap[i][j]);
							}
						}
					}
				}
			}
		}
		uint32_t endNum = (1 << n) - 1;
		for (int i = 0; i < n; i++)
		{
			string s = dp[endNum][i];
			if (ret.size() > s.size())
				ret = s;
		}
		return ret;
	}
};