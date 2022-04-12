#include<bits/stdc++.h>
#include<regex>
using namespace std;

// 优化后的版本 20ms
class Solution {
public:
	bool isMatch(string s, string p) {
		return isMatch(s.c_str(), p.c_str());
	}

	bool isMatch(const char* s, const char* p) {
		if (*p == 0) return *s == 0;

		auto first_match = *s && (*s == *p || *p == '.');

		if (*(p + 1) == '*') {
			return isMatch(s, p + 2) || (first_match && isMatch(++s, p));
		}
		else {
			return first_match && isMatch(++s, ++p);
		}
	}
};


class Solution {
public:
	bool isMatch(string s, string p) {
		if (regex_match(s, regex(p)))
		{
			return true;
		}
		return false;
	}
};


// 容易理解的版本 200ms
class Solution {
public:
	bool isMatch(string s, string p) {
		if (p.empty()) return s.empty();

		auto first_match = !s.empty() && (s[0] == p[0] || p[0] == '.');

		if (p.length() >= 2 && p[1] == '*') {
			return isMatch(s, p.substr(2)) || (first_match && isMatch(s.substr(1), p));
		}
		else {
			return first_match && isMatch(s.substr(1), p.substr(1));
		}
	}
};