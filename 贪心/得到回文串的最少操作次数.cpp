#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	int minMovesToMakePalindrome(string s) {
		int n = s.size(), ans = 0;
		for (int i = 0, j = n - 1; i < j; i++) {
			for (int k = j; i != k; k--) if (s[i] == s[k]) {
				// ��ĸ����ż���ε������ģ�⽻��
				for (; k < j; k++) swap(s[k], s[k + 1]), ans++;
				j--;
				goto OK;
			}
			// ��ĸ���������ε�����������������м仹�ж��پ���
			ans += n / 2 - i;
		OK: continue;// ѧϰgoto��ʹ�÷���
		}
		return ans;
	}
};


// ����ȽϺ����
class Solution {
public:
	int minMovesToMakePalindrome(string s) {
		if (s.size() <= 2) return 0;
		int cnt = 0, idx = 0;
		char ch = s[0];
		s.erase(s.begin());
		if (s.find(ch) == -1) cnt = s.size() / 2;  //ch�ĸ���ֻ��1����s����ԭ��������
		else
		{
			idx = s.find_last_of(ch);  //�ҵ����sĩλ��ch���±�
			s.erase(s.begin() + idx);  //�����chɾ��
			cnt = s.size() - idx;  //����ch��sĩλ�Ľ���������δɾ��ǰ��������Ϊs.size()-idx-1
		}
		return cnt + minMovesToMakePalindrome(s);  //��β��ch�����꣬�ݹ�����Ӵ�
	}
};