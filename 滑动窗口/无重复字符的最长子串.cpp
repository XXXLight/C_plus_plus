#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int lenS = s.size();
		if (lenS == 0) return 0;//�߽���������
		unordered_map<char, int> window;//����
		int maxLen = INT_MIN;//�洢���
		int p1 = 0, p2 = 0;
		while (p2 < lenS) {
			//���봰�ڣ�ָ�����ƣ����ڱ��
			char c1 = s[p2];
			window[c1]++;
			p2++;
			//���봰�ڣ�ָ�����ƣ����ڱ��
			while (window[c1] > 1) {//�Ƴ�����ֱ����������
				//�Ƴ����ڣ�ָ�����ƣ���С����
				char c2 = s[p1];
				window[c2]--;
				p1++;
				//�Ƴ����ڣ�ָ�����ƣ���С����
			}
			maxLen = max(maxLen, p2 - p1);//�����Ѿ��������ж�ֻ����һ�ε�����
		}
		return maxLen;
	}
};