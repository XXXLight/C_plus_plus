#include<bits/stdc++.h>
using namespace std;


const int mod = 1e9 + 7;
class Solution {
public:
	priority_queue<int, vector<int>, greater<>> p; // Ð¡¸ù¶Ñ
	int maximumProduct(vector<int>& nums, int k) {
		for (auto& e : nums) {
			p.emplace(e);
		}
		while (k--) {
			int v = p.top() + 1;
			p.pop();
			p.emplace(v);
		}
		int res = 1;
		while (!p.empty()) {
			res = 1LL * res*(p.top()) % mod;
			p.pop();
		}
		return res;
	}
};