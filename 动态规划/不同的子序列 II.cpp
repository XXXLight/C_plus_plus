#include<bits/stdc++.h>
using namespace std;

// 由python代码改写而来，唯一需要注意的就是大数的时候要自己处理
class Solution {
public:
	const long long n = 1e9 + 7;
	int distinctSubseqII(string S) {
		vector<long long> dp = { 1 };
		map<char, long long> mp;
		for (long long i = 0; i < S.size(); i++) {
			dp.push_back((dp.back() * 2) % n);
			if (mp.count(S[i])) {
				dp.back() -= dp[mp[S[i]]];
				if (dp.back() < 0) dp.back() += n;
			}
			mp[S[i]] = i;
		}
		long long res = (dp.back() - 1) % n;
		return res;
	}
};