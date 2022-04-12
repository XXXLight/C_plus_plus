#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int minCut(string s) {
		int len = s.size();
		vector<vector<bool>> isPal(len, vector<bool>(len)); //存所有j到i之间，是否是回文。花费n2空间与时间。
		for (int i = 0; i < len; ++i) {
			for (int j = 0; j <= i; ++j) {//要纪录所有包含自己单个字母的情况，所以两头都是闭区间
			//首尾相等是必要条件，再加一个要么二者间夹的字母小于2  或者 二者间的字段确定是回文，构成充分条件。
				if (s[i] == s[j] && (i - j <= 1 || isPal[j + 1][i - 1]))//这里查找isPal是能确定i-1时已经存储了结果
					isPal[j][i] = true;
			}
		}

		vector<int> dp(len);
		for (int i = 0; i < len; ++i) {
			if (isPal[0][i])
				dp[i] = 0;//先看最好不用分割的情况，不行，再两头遍历夹逼找所有情况。 O(n2)
			else {
				dp[i] = i;//刀刀切，最坏的情况
				for (int j = 1; j <= i; ++j) {
					if (isPal[j][i])// 0不可能了，从1到i开始遍历所有可能缩短切割的可能
						dp[i] = min(dp[i], dp[j - 1] + 1);// 一旦找到最短配合，那就是之前的最短加上这一次的1
				}
			}
		}
		return dp[len - 1];
	}
};

