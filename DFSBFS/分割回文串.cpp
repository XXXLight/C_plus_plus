#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
	vector<vector<int>> f;
	vector<vector<string>> ret;
	vector<string> ans;
	int n;

public:
	void dfs(const string& s, int i) {
		if (i == n) {
			ret.push_back(ans);
			return;
		}
		for (int j = i; j < n; ++j) {
			if (f[i][j]) {
				ans.push_back(s.substr(i, j - i + 1));
				dfs(s, j + 1);
				ans.pop_back();
			}
		}
	}

	vector<vector<string>> partition(string s) {
		n = s.size();
		f.assign(n, vector<int>(n, true));

		for (int i = n - 1; i >= 0; --i) {
			for (int j = i + 1; j < n; ++j) {
				f[i][j] = (s[i] == s[j]) && f[i + 1][j - 1];
			}
		}

		dfs(s, 0);
		return ret;
	}
};


// 分割问题，一个是复原IP地址，另一个是分割回文串
// 分割回文串好像看起来挺简单了
class Solution {
private:
	vector<vector<string>> result;
	vector<string> path; // 放已经回文的子串
	void backtracking(const string& s, int startIndex) {// 字符串和切割的起点，在递归中确定切割的终点，并将终点作为下一次的起点
		// 如果起始位置已经大于s的大小，说明已经找到了一组分割方案了
		if (startIndex >= s.size()) {
			result.push_back(path);
			return;
		}
		for (int i = startIndex; i < s.size(); i++) {
			if (isPalindrome(s, startIndex, i)) {   // 是回文子串
				// 获取[startIndex,i]在s中的子串
				string str = s.substr(startIndex, i - startIndex + 1);
				path.push_back(str);
				backtracking(s, i + 1); // 寻找i+1为起始位置的子串
				path.pop_back(); // 回溯过程，弹出本次已经填在的子串
			}
		}
	}
	//两个指针往中间走
	bool isPalindrome(const string& s, int start, int end) {
		for (int i = start, j = end; i < j; i++, j--) {
			if (s[i] != s[j]) {
				return false;
			}
		}
		return true;
	}
public:
	vector<vector<string>> partition(string s) {
		result.clear();
		path.clear();
		backtracking(s, 0);
		return result;
	}
};



class Solution {
public:
	vector<vector<string>> res;
	vector<string> tmp;
	// 字符串s,切割起点startIndex,传引用更快
	void dfs(string& s, int startIndex) {
		int len = s.size();
		if (startIndex == len) {
			res.push_back(tmp);
			return;
		}
		// 确定切割终点
		for (int endIndex = startIndex; endIndex < len; endIndex++) {
			// [startIndex,endIndex]切下来
			string subs = s.substr(startIndex, endIndex - startIndex + 1);
			if (isPalindrome(subs)) {
				tmp.push_back(subs);
				dfs(s, endIndex + 1);// 上一轮的终点作为下一轮的起点
				tmp.pop_back();// 回溯
			}
		}
	}
	vector<vector<string>> partition(string s) {
		dfs(s, 0);
		return res;
	}
	bool isPalindrome(string& s) {
		int len = s.size();
		for (int i = 0, j = len - 1; i < j; i++, j--) {
			if (s[i] != s[j]) return false;
		}
		return true;
	}
};