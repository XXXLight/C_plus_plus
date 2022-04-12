//#include<bits/stdc++.h>
//#include<unordered_map>
//#include<queue>
//#include "cout_elements.h"
//#include "Linked_list.h"
//#include "Union_Find.h"
//#include "presum.h"
//using namespace std;
//
//vector<int> lis(vector<int>&a) {
//	int dp[10000];
//	int ret;
//	vector<int>ans; ///存储路径
//	int t;
//	int n = a.size();
//	for (int i = 0; i < n; i++)
//		dp[i] = 1; ///dp数组初始化为1
//
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < i; j++) {
//			if (a[j] <= a[i]) dp[i] = max(dp[i], dp[j] + 1);
//		}
//		ret = max(ret, dp[i]);
//		if (ret == dp[i])t = i; ///求出最长的上升子序列的最后一个数的下标
//	}
//	cout << ret << endl; ///输出长上升子序列的长度
//
//	/*打印路径*/
//	ans.push_back(a[t]);
//	int k = a[t], j = t;
//	for (int i = t - 1; i >= 0; i--) {
//		if (a[i] <= k && dp[i] == dp[j] - 1) {
//			ans.push_back(a[i]);
//			k = a[i];
//			j = i;
//		}
//	}
//	reverse(ans.begin(), ans.end());
//	/*for (int i = ans.size() - 1; i >= 0; i--)
//		ans.push_back(ans[i]);*/
//	return ans;
//}
//
//int bestTeamScore(vector<int>& scores, vector<int>& ages) {
//	
//	vector<int> v;
//	vector<int> d = lis(v);
//	int sum = 0;
//	for (auto e : d) sum += e;
//	return sum;
//}
//
//int main() {
//	vector<int> scores = { 4,5,6,5 };
//	vector<int> ages = { 2,1,2,1};
//	int res = bestTeamScore(scores, ages);
//	return 0;
//}