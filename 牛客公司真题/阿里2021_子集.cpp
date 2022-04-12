// 题目链接：https://www.nowcoder.com/question/next?pid=30440638&qid=1664955&tid=46302077

#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

// 求最长上升子序列的接口
int lengthOfLIS(vector<int>& nums) {
	int len = nums.size();
	vector<int> res;
	res.push_back(nums[0]);
	for (int i = 1; i < len; i++) {
		if (nums[i] > res.back()) {
			res.push_back(nums[i]);
		}
		else {
			// 找>=nums[i]的index
			int index = lower_bound(res.begin(), res.end(), nums[i]) - res.begin();
			res[index] = nums[i];
		}
	}
	return res.size();
}
int LIS(vector<vector<int>>& v) {
	// 这里的排序要对
	sort(v.begin(), v.end(), [](auto e1, auto e2) {
		if (e1[0] != e2[0]) return e1[0] < e2[0];
		else return e1[1] > e2[1];
	});
	vector<int> help;
	for (int i = 0; i < v.size(); i++) help.push_back(v[i][1]);
	int res = lengthOfLIS(help);
	return res;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		// 这里看每一组的输入就好了
		int m;
		cin >> m;
		// 理解为m 个数组
		vector<vector<int>> v(m, vector<int>(2, 0));
		for (int i = 0; i < m; i++) {
			int a;
			cin >> a;
			v[i][0] = a;
		}
		for (int i = 0; i < m; i++) {
			int b;
			cin >> b;
			v[i][1] = b;
		}
		// 输出要满足要求
		cout << LIS(v) << endl;
	}
	return 0;
}