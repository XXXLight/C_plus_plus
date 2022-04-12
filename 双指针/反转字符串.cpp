#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	void reverseString(vector<char>& s) {
		int len = s.size();
		// Ë«Ö¸Õë
		for (int i = 0, j = len - 1; i < j; i++, j--) swap(s[i], s[j]);
	}
};