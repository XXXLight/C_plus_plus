#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	long long mostPoints(vector<vector<int>> &questions) {
		int n = questions.size();
		vector<long long> f(n + 1);
		for (int i = n - 1; i >= 0; --i) {
			int j = i + questions[i][1] + 1;
			f[i] = max(f[i + 1], questions[i][0] + (j < n ? f[j] : 0));
		}
		return f[0];
	}
};

