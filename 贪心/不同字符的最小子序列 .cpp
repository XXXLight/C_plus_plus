#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;



// string,vector�Ϳ���ģ��ջ
class Solution {
public:
	string smallestSubsequence(string s) {
		vector<bool> visited(26);       // �ж���ĸ�Ƿ��Ѿ���ջ��
		unordered_map<char, int> num;   // ��¼��ĸ���ֵĴ���
		for (char ch : s) {
			num[ch]++;
		}

		string stk;                     // string�Ϳ���ģ��ջ��
		for (char ch : s) {
			if (!visited[ch - 'a']) {   // ����ĸû�г�����ջ��

				// �� ջ��Ԫ�� > ��ǰ��ĸ��ֵ����ջ����ĸ������Ϊ0�����г�ջ����
				while (!stk.empty() && stk.back() > ch && num[stk.back()] > 0) {
					visited[stk.back() - 'a'] = false;      // ��ջ����ĸ����ջ����
					stk.pop_back();                         // ��ջ
				}
				visited[ch - 'a'] = true;                   // ��ջ����ĸ��ջ��
				stk.push_back(ch);
			}
			num[ch]--;                                      // ÿ�η��ʺ� ��ĸ���� - 1
		}
		return stk;
	}
};