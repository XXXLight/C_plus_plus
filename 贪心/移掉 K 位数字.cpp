#include<bits/stdc++.h>
using namespace std;

// 删除第一个波峰的位置
class Solution {
public:
	string removeKdigits(string num, int k) {
		string res;
		// 总共n位，移除k位，剩余n-k位
		int n = num.size(), m = n - k;
		for (auto c : num) {
			while (k && res.size() && res.back() > c) {
				res.pop_back();
				--k;
			}
			res.push_back(c);
		}
		res.resize(m);
		//去除前导0， 如10200，k = 1
		while (!res.empty() && res[0] == '0') {
			res.erase(res.begin());
		}
		return res.empty() ? "0" : res;
	}
};



class Solution {
public:
	string removeKdigits(string num, int k) {
		while (k--) {
			int n = num.size(), i = 0;
			while (i + 1 < n && num[i] <= num[i + 1]) ++i;
			num.erase(i, 1); // 每次 erase 的时间复杂度为O(n)
		}
		auto i = num.find_first_not_of("0");
		return i == string::npos ? "0" : num.substr(i);
	}
};
