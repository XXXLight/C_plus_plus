#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;


typedef unsigned long long ULL;
const int P = 133331, N = 100010;
ULL h[N], p[N];
ULL get(int l, int r) {
	if (l == 0) return h[r];// 特别l=0时返回h[r]，考虑边界情况
	return h[r] - h[l - 1] * p[r - l + 1];// 公式
}
void Init(string s) {
	int n = s.size();
	p[0] = 1;
	h[0] = s[0] - 'a' + 1;
	for (int i = 1; i < n; i++) {
		p[i] = p[i - 1] * P;
		h[i] = h[i - 1] * P + s[i] - 'a' + 1;
	}
}
class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		vector<string> res;
		Init(s);
		int n = s.size();
		unordered_map<int, int> cnt;
		for (int i = 0; i + 10 <= n; i++) {
			cnt[get(i, i + 9)]++;
			if (cnt[get(i, i + 9)] == 2) {
				res.push_back(s.substr(i, 10));
			}
		}
		return res;
	}
};