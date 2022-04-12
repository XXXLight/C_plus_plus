#include<bits/stdc++.h>
using namespace std;



#define _sacheck(x,t) (fabs(x)/t*1.0f*RAND_MAX > rand())
using vvi = vector<vector<int>>;

class Solution {
public:
	int ans = 0;
	void sa(vvi& s, vvi& m) {
		int sum = 0, n = s.size();
		for (double t = 1e8; t >= 1e-12; t *= 0.98) {
			int x = rand() % n;
			int y = rand() % n;
			int  sum1 = 0, sum2 = 0, sum3, sum4;
			for (int i = 0; i < m[x].size(); ++i) {
				sum1 += (s[x][i] == m[x][i]);
				sum2 += (s[y][i] == m[y][i]);
				sum3 += (s[x][i] == m[y][i]);
				sum4 += (s[y][i] == m[x][i]);
			}
			if (sum1 + sum2 < sum3 + sum4 or _sacheck(sum1 + sum2 - sum3 - sum4, t)) {
				swap(m[x], m[y]);
				if (sum1 + sum2 < sum3 + sum4) {
					int sum = 0;
					for (int i = 0; i < m.size(); ++i)for (int j = 0; j < m[i].size(); ++j)sum += (s[i][j] == m[i][j]);
					ans = max(ans, sum);
				}
			}
		}
	}
	int solve(vvi& s, vvi& m) {
		int sum = 0;
		for (int i = 0; i < m.size(); ++i)for (int j = 0; j < m[i].size(); ++j)sum += (s[i][j] == m[i][j]);
		ans = max(ans, sum);
		for (int step = 0; step <= 13; ++step) {
			//if(step%2==1)
				//random_shuffle(m.begin(),m.end());
			sa(s, m);
		}
		return ans;
	}
	int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
		srand(133333333331);
		//srand(time(NULL));
		return solve(students, mentors);
	}
};

