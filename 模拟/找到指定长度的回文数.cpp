#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	long long  huiwen(int n, int k) {
		long long res;
		if (n % 2 == 0) {
			int cnt = n / 2;
			long long st = 1, en = 1;
			while (cnt--) {
				st *= 10;
				en *= 10;
			}
			st /= 10, en -= 1;
			if (k > en - st + 1) return -1;
			string t1, t2;
			t1 = to_string(st + k - 1);
			t2 = t1;
			reverse(t1.begin(), t1.end());
			t2 += t1;
			res = stoll(t2);
			return res;
		}
		else {
			int cnt = n / 2;
			long long st = 1;
			long long en = 1;
			while (cnt--) {
				st *= 10;
				en *= 10;
			}
			en *= 10;
			en -= 1;
			if (k > en - st + 1) return -1;
			string t1, t2;
			t1 = to_string(st + k - 1);
			t2 = t1;
			reverse(t1.begin(), t1.end());
			t1.erase(t1.begin());
			t2 += t1;
			res = stoll(t2);
			return res;
		}
	}
	vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
		vector<long long> res;
		for (auto& e : queries) {
			res.push_back(huiwen(intLength, e));
		}
		return res;
	}
};