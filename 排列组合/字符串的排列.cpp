#include<bits/stdc++.h>
using namespace std;

//调库它不香吗？？？？
//  {a,b,c}的全排列：abc，acb，bac，bca，cab，cba
//  1.abc没有prev_permutation；cba没有next_permutation
//  2.生成的全排列是按照字典顺序进行排列的
class Solution {
public:
	vector<string> permutation(string s) {
		vector<string> ans;
		// sort以后的字母是字典序最小的字母，所以是有next_permutation的，所以必须进行排序
		sort(s.begin(), s.end());
		do {
			ans.push_back(s);
		} while (next_permutation(s.begin(), s.end()));
		return ans;
	}
};



class Solution {
public:
	vector<string> res;
	set<string> st;
	// 两个都必须传引用？？？
	// 排列临时变量必须传进去
	void backtrack(string& s, string& tmp, int depth) {
		if (depth == s.size()) {
			res.push_back(tmp);
			return;
		}
		for (int i = depth; i < s.size(); i++) {
			swap(s[i], s[depth]);
			backtrack(s, tmp, depth + 1);
			swap(s[i], s[depth]);
		}
	}
	vector<string> permutation(string s) {
		backtrack(s, s, 0);
		// 去重
		for (auto e : res) st.insert(e);
		res.clear();
		for (auto e : st) res.push_back(e);
		return res;
	}
};