#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	long long int str2int(string s, int l, int r) {
		// �ַ��� ת ����
		long long int res = 0;
		for (int i = l; i < r; i++) {
			res *= 10;
			res += s[i] - '0';
			if (res > 184467440737095516) // ��ֹԽ��, ���дһ���ͺ���
				return -10;
		}
		return res;
	}
	bool splitString(string s) {
		if (s.size() <= 1) return false;
		long long int arr[21][21];
		memset(arr, 0, sizeof(arr));

		// �������� arr
		for (int i = 0; i < s.size(); i++) {
			for (int j = i + 1; j <= s.size(); j++) {
				arr[i][j] = str2int(s, i, j);
			}
		}

		// �������м���ʼ��
		queue<int> q;
		queue<long long int> num;
		for (int i = 1; i < s.size(); i++) {
			q.push(i);
			num.push(arr[0][i]);
		}
		while (q.size() > 0) {
			// ÿ�δӶ���ͷ��ȡֵ
			long long int idx = q.front();
			long long int last_num = num.front();
			q.pop();
			num.pop();

			// Ѱ������������ ��һ�� �±� �� ��ֵ
			for (int i = 1; idx + i <= s.size(); i++) {
				if (arr[idx][idx + i] == last_num - 1) { // ����ҵ���
					if (idx + i == s.size()) return true; // �ж��Ƿ�ɹ�
					q.push(idx + i);        // ��Ԫ�����
					num.push(last_num - 1);
				}
				// ���û�ҵ���ʲôҲ����
			}
		}
		return false;
	}
};



class Solution
{
public:
	string s;
	int n;

	bool splitString(string s)
	{
		this->s = s;
		n = s.size();
		for (int i = 0; i < n - 1; i++)
		{
			long long x = stoll(s.substr(0, i + 1));
			if (x > 9999999999)
				break;
			if (dfs(i + 1, x) == true)
				return true;
		}
		return false;
	}

	bool dfs(int idx, long long last)
	{
		if (idx == n)
			return true;
		if (last == 0)
			return false;
		for (int i = idx; i < n; i++)
		{
			long long y = stoll(s.substr(idx, (i + 1 - idx)));
			if (y >= last)
				break;
			if (last - 1 == y)
				if (dfs(i + 1, y) == true)
					return true;
		}
		return false;
	}
};




using uint64 = unsigned long long;
class Solution {
	int sz;
	vector<uint64> level;
	bool res = false;
public:
	bool splitString(string s) {
		this->sz = s.size();
		backtracking(s, 0);
		return res;
	}
	void backtracking(string& s, int idx) {
		if (idx == sz) {
			res = true;
			return;
		}
		for (int i = idx + 1; i <= sz; ++i) {
			int len = i - idx;
			if (len >= sz)   return;
			uint64 tmpv = stoull(s.substr(idx, len));
			// ������������֮��Ϊ1,���֦
			if (!level.empty() && level.back() - tmpv != 1)  continue;
			level.push_back(tmpv);
			backtracking(s, i);
			level.pop_back();
		}
	}
};