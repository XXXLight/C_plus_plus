#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;


// ��С�����Ӵ�û��˳��Ҫ��

// needs.count(c1)��needs.count(c2)�����仰����������
// ʱ�临�Ӷ��� O(M + N)��M �� N �ֱ����ַ��� S �� T �ĳ���
class Solution {
public:
	string minWindow(string s, string t) {
		int lenS = s.size(), lenT = t.size(); //�ַ����ĳ���
		int p1 = 0, p2 = 0; //˫ָ���γɻ�������[p1,p2)
		int match = 0; //��ǰƥ����ĸ����
		int start = 0, minLen = INT_MAX; //Ϊ�˼�¼���
		unordered_map<char, int> window, needs; //window��¼�����еĴ���
		for (auto e : t) needs[e]++; //��Ҫ�Ĵ���
		while (p2 < lenS) { //ֱ���ַ������ұ߽磬��������p2==lenS��֤��p2���ұ߽�
			//���ұߵļ��봰�ڣ�ͬʱ����ָ��
			char c1 = s[p2];
			window[c1]++;
			p2++;
			
			if (needs.count(c1) && window[c1] == needs[c1]) {//�����е���ĸ���ִ����ﵽҪ��
				match++;
			}
			while (match == needs.size()) {//ƥ������С��ߵĴ���
				//�������Ž�
				if (p2 - p1 < minLen) {
					minLen = p2 - p1;
					start = p1;
				}
				
				//��С���ڣ�ָ������
				char c2 = s[p1];
				window[c2]--;
				p1++;
				// ע�⣺window[c2] < needs[c2]�ĳ�window[c2] ��= needs[c2]�Ͳ������ˣ�why������
				if (needs.count(c2) && window[c2] < needs[c2]) match--;
			}
		}
		return minLen == INT_MAX ? "" : s.substr(start, minLen);
	}
};