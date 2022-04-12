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


// �ָ����⣬һ���Ǹ�ԭIP��ַ����һ���Ƿָ���Ĵ�
// �ָ���Ĵ���������ͦ����
class Solution {
private:
	vector<vector<string>> result;
	vector<string> path; // ���Ѿ����ĵ��Ӵ�
	void backtracking(const string& s, int startIndex) {// �ַ������и����㣬�ڵݹ���ȷ���и���յ㣬�����յ���Ϊ��һ�ε����
		// �����ʼλ���Ѿ�����s�Ĵ�С��˵���Ѿ��ҵ���һ��ָ����
		if (startIndex >= s.size()) {
			result.push_back(path);
			return;
		}
		for (int i = startIndex; i < s.size(); i++) {
			if (isPalindrome(s, startIndex, i)) {   // �ǻ����Ӵ�
				// ��ȡ[startIndex,i]��s�е��Ӵ�
				string str = s.substr(startIndex, i - startIndex + 1);
				path.push_back(str);
				backtracking(s, i + 1); // Ѱ��i+1Ϊ��ʼλ�õ��Ӵ�
				path.pop_back(); // ���ݹ��̣����������Ѿ����ڵ��Ӵ�
			}
		}
	}
	//����ָ�����м���
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
	// �ַ���s,�и����startIndex,�����ø���
	void dfs(string& s, int startIndex) {
		int len = s.size();
		if (startIndex == len) {
			res.push_back(tmp);
			return;
		}
		// ȷ���и��յ�
		for (int endIndex = startIndex; endIndex < len; endIndex++) {
			// [startIndex,endIndex]������
			string subs = s.substr(startIndex, endIndex - startIndex + 1);
			if (isPalindrome(subs)) {
				tmp.push_back(subs);
				dfs(s, endIndex + 1);// ��һ�ֵ��յ���Ϊ��һ�ֵ����
				tmp.pop_back();// ����
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