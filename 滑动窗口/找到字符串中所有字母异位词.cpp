#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

//�� ��С�����Ӵ� �Ļ�������΢�Ķ�����
class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		vector<int> res;//�����
		int lenS = s.size(), lenP = p.size(); //�ַ����ĳ���
		int p1 = 0, p2 = 0; //˫ָ���γɻ�������[p1,p2)
		int match = 0; //��ǰƥ����ĸ����
		int start = 0, minLen = INT_MAX; //Ϊ�˼�¼���
		unordered_map<char, int> window, needs; //window��¼�����еĴ���
		for (auto e : p) needs[e]++; //��Ҫ�Ĵ���
		while (p2 < lenS) { //ֱ���ַ������ұ߽磬��������p2==lenS��֤��p2���ұ߽�
			//���ұߵļ��봰�ڣ�ͬʱ����ָ��
			char c1 = s[p2];
			window[c1]++;
			p2++;
			//���ұߵļ��봰�ڣ�ͬʱ����ָ��
			if (needs.count(c1) && window[c1] == needs[c1]) {//�����е���ĸ���ִ����ﵽҪ��
				match++;
			}
			while (match == needs.size()) {//ƥ������С��ߵĴ���
				//�н��������
				if (p2 - p1 == lenP) {
					res.push_back(p1);
				}
				//�н��������
				//��С���ڣ�ָ������
				char c2 = s[p1];
				window[c2]--;
				p1++;
				//��С���ڣ�ָ������
				if (needs.count(c2) && window[c2] < needs[c2]) match--;
			}
		}
		return res;
	}
};