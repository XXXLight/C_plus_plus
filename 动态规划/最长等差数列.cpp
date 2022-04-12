#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

//   k i j
// dp[i][j]=dp[][]
//  使用memset()函数初始化二维数组时要千万小心：
//	1.二维整型数组利用memset()函数初始化时，只能初始化为0或者 - 1，否则二维整型数组的值将为随机数。
//	2.二维char数组利用memset()函数初始化时不受限制，可初始化为任意字符。
class Solution {
public:
	int longestArithSeqLength(vector<int>& A) {
		unordered_map<int, int> mp;
		int n = A.size();
		vector<vector<int>> dp(n, vector<int>(n, 2));
		int ans = 0;
		// 是右上三角区域，要从0开始
		for (int i = 0; i < n; i++) {
			// 此时的dp [0,i-1]
			for (int j = i + 1; j < n; j++) {
				int target = 2 * A[i] - A[j];  // 等差数列公式，2*A[i]=A[k]+A[j]
				// if (mp.count(target))该条件不能少
				// 只有满足关系才更新dp数组，其他dp不动
				if (mp.count(target)) dp[i][j] = dp[mp[target]][i] + 1;
				ans = max(ans, dp[i][j]);
			}
			mp[A[i]] = i;
		}
		return ans;
	}
};