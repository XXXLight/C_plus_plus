#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	int minMovesToMakePalindrome(string s) {
		int n = s.size(), ans = 0;
		for (int i = 0, j = n - 1; i < j; i++) {
			for (int k = j; i != k; k--) if (s[i] == s[k]) {
				// 字母出现偶数次的情况，模拟交换
				for (; k < j; k++) swap(s[k], s[k + 1]), ans++;
				j--;
				goto OK;
			}
			// 字母出现奇数次的情况，计算它距离中间还有多少距离
			ans += n / 2 - i;
		OK: continue;// 学习goto的使用方法
		}
		return ans;
	}
};


// 这个比较好理解
class Solution {
public:
	int minMovesToMakePalindrome(string s) {
		if (s.size() <= 2) return 0;
		int cnt = 0, idx = 0;
		char ch = s[0];
		s.erase(s.begin());
		if (s.find(ch) == -1) cnt = s.size() / 2;  //ch的个数只有1个，s长度原本是奇数
		else
		{
			idx = s.find_last_of(ch);  //找到最靠近s末位的ch的下标
			s.erase(s.begin() + idx);  //把这个ch删除
			cnt = s.size() - idx;  //计算ch到s末位的交换次数，未删除前交换次数为s.size()-idx-1
		}
		return cnt + minMovesToMakePalindrome(s);  //首尾的ch处理完，递归求解子串
	}
};