#include<bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
	priority_queue<ll, vector<ll>, greater<ll>> p;
	int nthUglyNumber(int n) {
		vector<ll> v;
		int st = 1;
		int cnt = 0;
		while (1) {
			p.emplace(st * 2);
			p.emplace(st * 3);
			p.emplace(st * 5);
			int cur = p.top();
			v.push_back(cur);
			cnt++;
			if (cnt == n) break;
			st = cur;
		}
		return v.back();
	}
};
int main() {

	return 0;
}