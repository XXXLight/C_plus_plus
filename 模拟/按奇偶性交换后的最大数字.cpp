#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	int largestInteger(int num) {
		string s = to_string(num);
		for (int i = 0; i < s.size(); ++i)
			for (int j = i + 1; j < s.size(); ++j)
				if (s[i] % 2 == s[j] % 2 && s[i] < s[j])
					swap(s[i], s[j]);
		return stoi(s);
	}
};