#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

//�� ��С�����Ӵ� �Ļ�������΢�Ķ�����
class Solution {
public:
	bool checkInclusion(string s1, string s2) {
		int lenS1 = s1.size(), lenS2 = s2.size(); //�ַ����ĳ���
		int p1 = 0, p2 = 0; //˫ָ���γɻ�������[p1,p2)
		int match = 0; //��ǰƥ����ĸ����
		int start = 0, minLen = INT_MAX; //Ϊ�˼�¼���
		unordered_map<char, int> window, needs; //window��¼�����еĴ���
		for (auto e : s1) needs[e]++; //��Ҫ�Ĵ���
		while (p2 < lenS2) { //ֱ���ַ������ұ߽磬��������p2==lenS2��֤��p2���ұ߽�
			//���ұߵļ��봰�ڣ�ͬʱ����ָ��
			char c1 = s2[p2];
			window[c1]++;
			p2++;
			//���ұߵļ��봰�ڣ�ͬʱ����ָ��
			if (needs.count(c1) && window[c1] == needs[c1]) {//�����е���ĸ���ִ����ﵽҪ��
				match++;
			}
			while (match == needs.size()) {//ƥ������С��ߵĴ���
				//������ͬ˵���н�
				if (p2 - p1 == lenS1) {
					return true;
				}
				//������ͬ˵���н�
				//��С���ڣ�ָ������
				char c2 = s2[p1];
				window[c2]--;
				p1++;
				//��С���ڣ�ָ������
				if (needs.count(c2) && window[c2] < needs[c2]) match--;
			}
		}
		return false;
	}
};