#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	// 这里必须传引用
	void reverseString(string& s, int l, int r) {
		for (int i = l, j = r; i < j; i++, j--) swap(s[i], s[j]);
	}
	string reverseLeftWords(string s, int n) {
		n %= s.size();
		reverseString(s, 0, s.size() - 1);
		reverseString(s, 0, s.size() - n - 1);
		reverseString(s, s.size() - n, s.size() - 1);
		return s;
	}
};