#include<bits/stdc++.h>
using namespace std;

// continue�Ǻ������䲻ִ�м���ѭ��
// break������ѭ��
class Solution {
public:
	int numDifferentIntegers(string word) {
		int len = word.size();
		set<string> v;
		// ����ɨ��
		for (int i = 0; i < len; i++) {
			if (isalpha(word[i])) continue; // ��ĸ����
			// ����������һֱ�����ƶ�ָ��
			string s = "";
			while (isdigit(word[i]) && i < len) { // i<len������
				s += word[i];
				i++;
			}
			// ȥ��ǰ����
			while (s.size() > 0 && s[0] == '0') { // �����ǡ�0��
				s.erase(s.begin());
			}
			v.insert(s);
		}
		return v.size();
	}
};



class Solution {
public:
	int numDifferentIntegers(string word) {
		int len = word.size();
		set<string> v;
		int i = 0;
		while (i < len) {
			if (isalpha(word[i])) { i++; continue; }
			string s = "";
			while (isdigit(word[i]) && i < len) {
				s += word[i];
				i++;
			}

			while (s.size() > 0 && s[0] == '0') {
				s.erase(s.begin());
			}
			v.insert(s);
		}
		return v.size();
	}
};