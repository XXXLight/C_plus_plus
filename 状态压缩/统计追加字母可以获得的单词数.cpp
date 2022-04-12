#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;


class Solution {
public:
	int wordCount(vector<string>& startWords, vector<string>& targetWords) {
		// �� word ת��Ϊ��ʾ������ĸ״̬�Ķ���������
		auto mask = [](const string& word) -> int {
			int res = 0;
			for (char ch : word) {
				res |= 1 << (ch - 'a');
			}
			return res;
		};

		unordered_set<int> masks;   // ���п��Ի�õ�״̬
		for (const string& start : startWords) {
			// ������ʼ���ʣ�������״ֵ̬�������п��Ի�õ�״̬
			int msk = mask(start);
			for (int i = 0; i < 26; ++i) {
				if (((msk >> i) & 1) == 0) {
					masks.insert(msk | (1 << i));
				}
			}
		}
		int cnt = 0;   // ���Ի�õĵ�����
		for (const string& target : targetWords) {
			if (masks.count(mask(target))) {
				++cnt;
			}
		}
		return cnt;
	}
};

