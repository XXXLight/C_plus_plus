#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	vector<long long> state;
	// a e i o u
	// 0 1 2 3 4
	// 01 10 12 20 21 23 24 32 34 40
	long long mod = 1e9 + 7;

	vector<long long> run(vector<long long>& s) {
		vector<long long> s_(5);
		s_[0] = (s[1] + s[2] + s[4]) % mod;
		s_[1] = (s[0] + s[2]) % mod;
		s_[2] = (s[1] + s[3]) % mod;
		s_[3] = s[2] % mod;
		s_[4] = (s[2] + s[3]) % mod;

		return s_;
	}
	int countVowelPermutation(int n) {
		state = vector<long long>(5, 1);
		for (int i = 1; i < n; i++) {
			state = run(state);
		}
		long long sum = 0;
		for (int i = 0; i < 5; i++) {
			sum += state[i];
			sum %= mod;
		}
		return sum;
	}
};

