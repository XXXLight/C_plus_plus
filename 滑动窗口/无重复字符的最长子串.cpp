#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int lenS = s.size();
		if (lenS == 0) return 0;//边界条件处理
		unordered_map<char, int> window;//窗口
		int maxLen = INT_MIN;//存储结果
		int p1 = 0, p2 = 0;
		while (p2 < lenS) {
			//加入窗口，指针右移，窗口变大
			char c1 = s[p2];
			window[c1]++;
			p2++;
			//加入窗口，指针右移，窗口变大
			while (window[c1] > 1) {//移出窗口直到满足条件
				//移出窗口，指针右移，缩小窗口
				char c2 = s[p1];
				window[c2]--;
				p1++;
				//移出窗口，指针右移，缩小窗口
			}
			maxLen = max(maxLen, p2 - p1);//外面已经满足所有都只出现一次的条件
		}
		return maxLen;
	}
};