#include<bits/stdc++.h>
using namespace std;

// ���ε�һ��˼·����������������
class Solution {
public:
	bool isFlipedString(string s1, string s2) {
		return s1.size() == s2.size() && (s1 + s1).find(s2) != -1;
	}
};

