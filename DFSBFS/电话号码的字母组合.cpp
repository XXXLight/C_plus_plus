#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> combinations;
		if (digits.empty()) {
			return combinations;
		}
		unordered_map<char, string> phoneMap{
			{'2', "abc"},
			{'3', "def"},
			{'4', "ghi"},
			{'5', "jkl"},
			{'6', "mno"},
			{'7', "pqrs"},
			{'8', "tuv"},
			{'9', "wxyz"}
		};
		string combination;
		backtrack(combinations, phoneMap, digits, 0, combination);
		return combinations;
	}

	void backtrack(vector<string>& combinations, const unordered_map<char, string>& phoneMap, const string& digits, int index, string& combination) {
		if (index == digits.length()) {
			combinations.push_back(combination);
		}
		else {
			char digit = digits[index];
			const string& letters = phoneMap.at(digit);
			for (const char& letter : letters) {
				combination.push_back(letter);
				backtrack(combinations, phoneMap, digits, index + 1, combination);
				combination.pop_back();
			}
		}
	}
};



// 写递归DFS时，要提前想好需要传递哪些参数
class Solution {
public:
	map<char, vector<char>> mp;
	vector<string> res;
	void init() {
		mp['2'] = { 'a','b','c' };
		mp['3'] = { 'd','e','f' };
		mp['4'] = { 'g','h','i' };
		mp['5'] = { 'j','k','l' };
		mp['6'] = { 'm','n','o' };
		mp['7'] = { 'p','q','r','s' };
		mp['8'] = { 't','u','v' };
		mp['9'] = { 'w','x','y','z' };
	}
	void DFS(string s, int index, string tmp) {
		if (index == s.size()) {
			res.push_back(tmp);
		}
		for (int i = 0; i < mp[s[index]].size(); i++) {
			tmp += mp[s[index]][i];
			DFS(s, index + 1, tmp);
			tmp.pop_back();
		}
	}
	vector<string> letterCombinations(string digits) {
		if (digits.size() == 0) return {};
		init();
		DFS(digits, 0, "");
		return res;
	}
};





// tmp写在外面也可以
class Solution {
public:
	map<char, vector<char>> mp;
	vector<string> res;
	string tmp;
	void init() {
		mp['2'] = { 'a','b','c' };
		mp['3'] = { 'd','e','f' };
		mp['4'] = { 'g','h','i' };
		mp['5'] = { 'j','k','l' };
		mp['6'] = { 'm','n','o' };
		mp['7'] = { 'p','q','r','s' };
		mp['8'] = { 't','u','v' };
		mp['9'] = { 'w','x','y','z' };
	}
	void DFS(string s, int index) {
		if (index == s.size()) {
			res.push_back(tmp);
		}
		for (int i = 0; i < mp[s[index]].size(); i++) {
			tmp += mp[s[index]][i];
			DFS(s, index + 1);
			tmp.pop_back();
		}
	}
	vector<string> letterCombinations(string digits) {
		if (digits.size() == 0) return {};
		init();
		DFS(digits, 0);
		return res;
	}
};