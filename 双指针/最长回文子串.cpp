#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	pair<int, int> expandAroundCenter(const string& s, int left, int right) {
		while (left >= 0 && right < s.size() && s[left] == s[right]) {
			--left;
			++right;
		}
		return { left + 1, right - 1 };
	}

	string longestPalindrome(string s) {
		int start = 0, end = 0;
		for (int i = 0; i < s.size(); ++i) {
			auto[left1, right1] = expandAroundCenter(s, i, i);
			auto[left2, right2] = expandAroundCenter(s, i, i + 1);
			if (right1 - left1 > end - start) {
				start = left1;
				end = right1;
			}
			if (right2 - left2 > end - start) {
				start = left2;
				end = right2;
			}
		}
		return s.substr(start, end - start + 1);
	}
};


// ������չ��
class Solution {
public:
	string longestPalindrome(string s) {
		int len = s.size();
		if (len <= 1) return s;
		string res;
		int resLen = 0;
		int start = 0;
		for (int i = 0; i < len; i++) {
			// bab������,&&
			if ((i + 2 < len) && s[i] == s[i + 2]) { // ע��&&���������������ȷ�ǰ��
				int l = i, r = i + 2;
				while (l >= 0 && r < len&&s[l] == s[r]) {
					// ��ʱ���ǻ��Ĵ����ȸ��´𰸣����ƶ�ָ��,����Ҫ�����Ƚ�
					if (r - l + 1 > resLen) {
						resLen = r - l + 1;
						start = l;
					}
					l--; r++;
				}
			}
			// bb������
			if ((i + 1) < len&& s[i] == s[i + 1]) {
				int l = i, r = i + 1;
				while (l >= 0 && r < len&&s[l] == s[r]) {
					// ��ʱ���ǻ��Ĵ����ȸ��´𰸣����ƶ�ָ��
					if (r - l + 1 > resLen) {
						resLen = r - l + 1;
						start = l;
					}
					l--; r++;
				}
			}
		}
		if (resLen == 0) return s.substr(0, 1);
		return s.substr(start, resLen);
	}
};



class Solution {
public:
	string longestPalindrome(string s) {
		int len = s.size();
		if (len == 1) return s;
		int st = 0, maxLen = 0;	// ��substr��ϣ�substr���ص����ַ�����st��ʾ��㣬maxLen��ʾ����
		// bb��
		for (int i = 1; i < len; i++) {
			if (s[i - 1] == s[i]) {
				int l = i - 1, r = i;
				while (l >= 0 && r < len&&s[l] == s[r]) {
					//�ȸ��½�������ƶ�ָ��
					if (r - l + 1 > maxLen) {
						st = l;
						maxLen = r - l + 1;
					}
					l--;r++;
				}
			}
		}
		// aba��
		for (int i = 1; i < len - 1; i++) {
			if (s[i - 1] == s[i + 1]) {
				int l = i - 1, r = i + 1;
				while (l >= 0 && r < len&&s[l] == s[r]) {
					//�ȸ��½�������ƶ�ָ��
					if (r - l + 1 > maxLen) {
						st = l;
						maxLen = r - l + 1;
					}
					l--;r++;
				}
			}
		}
		if (maxLen == 0) return s.substr(0, 1);
		return s.substr(st, maxLen);
	}
};