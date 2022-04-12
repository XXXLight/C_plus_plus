#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;


class Solution
{
public:
	vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people)
	{
		int INF = 1e9;
		int n = req_skills.size();

		unordered_map<string, int> skill_ID;    //赋予每个skill唯一ID
		for (int i = 0; i < n; i++)
			skill_ID[req_skills[i]] = i;

		vector<int> people_state;               //每个人的技能，压缩为一个state（bitmask）
		for (auto & v : people)
		{
			int state = 0;
			for (string & skill : v)
				state |= (1 << skill_ID[skill]);
			people_state.push_back(state);
		}

		unordered_map<int, vector<int>> team;   //不同dp状态对应的成员
		vector<int> dp(1 << n, INF);
		dp[0] = 0;
		for (int pi = 0; pi < people.size(); pi++)
		{
			int p = people_state[pi];
			for (int state = (1 << n) - 1; state > -1; state--)
			{
				int nxt_state = state | p;
				if (dp[state] + 1 < dp[nxt_state])
				{
					dp[nxt_state] = dp[state] + 1;
					team[nxt_state] = team[state];
					team[nxt_state].push_back(pi);
				}
			}
		}

		return team[(1 << n) - 1];
	}
};

