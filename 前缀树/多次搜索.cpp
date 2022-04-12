#include<bits/stdc++.h>
using namespace std;


const int N = 100000 + 10;
int childs[N][26];
int values[N];
int nodes_cnt;
class Solution {
public:
	vector<vector<int>> multiSearch(string big, vector<string>& smalls) {
		vector<vector<int>> ans(smalls.size());
		memset(childs, 0, sizeof(childs));
		memset(values, 0xff, sizeof(values));
		nodes_cnt = 0;

		//printf("%d \n",smalls.size());

		for (int i = 0; i < smalls.size(); ++i) {
			insert(smalls[i], i);
		}

		for (int i = 0; i < big.size(); ++i) {
			find(big, i, ans);
		}

		return ans;
	}

	void insert(const string& s, int index_of_s) {
		int r = 0;
		for (int i = 0; i < s.size(); ++i) {
			int idx = s[i] - 'a';

			int& next = childs[r][idx];
			//printf("%d %d %d %d\n",r,idx,next,nodes_cnt);
			if (next == 0) {
				next = ++nodes_cnt;
			}
			r = next;
		}
		values[r] = index_of_s;
	}

	void find(const string & t, int beg, vector<vector<int>>& ans) {
		int r = 0;
		for (int j = beg; j < t.size(); ++j) {
			int idx = t[j] - 'a';
			const int& next = childs[r][idx];
			if (next == 0) {//没找到
				return;
			}
			if (values[next] >= 0) {//t[beg,j]是一个串，记录开始位置beg
				ans[values[next]].push_back(beg);
			}
			r = next;
		}
	}
};

