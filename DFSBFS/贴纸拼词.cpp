#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
	int minStickers(vector<string>& stickers, string target) {
		int n = target.size();
		queue<int> que;
		set<int> record;
		// state��ʾ������״̬Ϊstateʱ����С��ֽ��������ÿһλ��Ϊ1��ʱ��Ϊ����Ҫ���صĽ��
		que.push(0);
		record.insert(0);
		int step = 0;
		while (!que.empty()) {
			int sz = que.size();
			for (int i = 0; i < sz; i++) {
				int base = que.front();
				if (base == (1 << n) - 1) {
					// cout << (bitset<6>)base << " "<<endl;
					return step;
				}
				que.pop();
				// ÿһ�ִ�stickers��ժȡ�ַ�
				for (auto sticker : stickers) {
					int state = base; //��ǰ������base��һ����Ϊ��׼��ʼ��ɢ
					// cout << (bitset<6>)state << " "<<endl;
					int cnt[26] = { 0 };
					for (auto ch : sticker) {
						cnt[ch - 'a']++;
					}
					for (int i = 0; i < n; i++) {
						char c = target[i];
						//��ǰ�ַ���s�г��ֹ���target���ڵ�λû�б����
						if (cnt[c - 'a'] > 0 && (state & 1 << i) == 0) {
							cnt[c - 'a']--;
							state |= 1 << i; //���
						}
					}
					if (!record.count(state)) {
						que.push(state);
						record.insert(state);
					}
				}
			}
			step++;
		}
		return -1;
	}
};

