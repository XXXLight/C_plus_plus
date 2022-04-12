#include<bits/stdc++.h>
using namespace std;

// 环形的一个思路，开两倍长度数组
class Solution {
public:
	bool isFlipedString(string s1, string s2) {
		return s1.size() == s2.size() && (s1 + s1).find(s2) != -1;
	}
};

