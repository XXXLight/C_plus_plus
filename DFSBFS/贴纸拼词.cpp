#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
	int minStickers(vector<string>& stickers, string target) {
		int n = target.size();
		queue<int> que;
		set<int> record;
		// state表示二进制状态为state时的最小贴纸数量，当每一位都为1的时候，为最终要返回的结果
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
				// 每一轮从stickers中摘取字符
				for (auto sticker : stickers) {
					int state = base; //当前层是以base这一层作为基准开始扩散
					// cout << (bitset<6>)state << " "<<endl;
					int cnt[26] = { 0 };
					for (auto ch : sticker) {
						cnt[ch - 'a']++;
					}
					for (int i = 0; i < n; i++) {
						char c = target[i];
						//当前字符在s中出现过且target所在的位没有被填充
						if (cnt[c - 'a'] > 0 && (state & 1 << i) == 0) {
							cnt[c - 'a']--;
							state |= 1 << i; //填充
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

