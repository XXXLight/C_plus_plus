#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Solution {
public:
	typedef pair<int, int> PII;

	// f[i] 表示i右边第一个没有被询问的位置
	vector<int> f;

	int find(int x) {
		if (f[x] == x) return f[x];
		return f[x] = find(f[x]);
	}

	// 按照区间长度从小到大排序
	static bool cmp(const vector<int> &a, const vector<int> &b) {
		return a[1] - a[0] < b[1] - b[0];
	}

	vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
		int n = intervals.size(), m = queries.size();
		vector<int> ans(m, -1);
		sort(intervals.begin(), intervals.end(), cmp);
		PII qs[m];
		for (int i = 0; i < m; i++) qs[i] = { queries[i], i };
		sort(qs, qs + m);
		f.resize(m + 1);
		for (int i = 0; i < m + 1; i++) f[i] = i;

		for (int i = 0; i < n; i++) {
			int left = intervals[i][0], right = intervals[i][1], len = right - left + 1;
			int l = 0, r = m;
			while (l < r) {
				int mid = l + r >> 1;
				if (qs[mid].first >= left) r = mid;
				else l = mid + 1;
			}

			while (find(f[l]) < m && qs[find(f[l])].first <= right) {
				l = find(l);
				ans[qs[l].second] = len;
				f[l] = l + 1;
			}
		}

		return ans;
	}
};


class Solution {
public:
	vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
		// 按照左端点从小到大排序
		sort(intervals.begin(), intervals.end());
		int n = queries.size();
		// 记录一下查询的index
		vector<pair<int, int>> que;
		for (int i = 0; i < n; ++i) {
			que.push_back(make_pair(queries[i], i));
		}
		// 查询从小到大排序
		sort(que.begin(), que.end());
		// 保存结果
		vector<int> res(n);
		// 如果已经有查到的, hash记录一下
		unordered_map<int, int> hash;
		// 处理离线查询, query从小到大, st保存(长度, 结束位置)
		set<pair<int, int>> st;
		int cur = 0;
		for (auto q : que) {
			// 要查询的值和index
			int k = q.first, ind = q.second;
			if (hash.count(k)) {
				res[ind] = hash[k];
				continue;
			}
			// 将可能符合要求的区间加入set (开始位置 <= k)
			for (int i = cur; i < intervals.size(); ++i) {
				if (intervals[i][0] <= k) {
					st.insert({ intervals[i][1] - intervals[i][0] + 1, intervals[i][1] });
				}
				else {
					cur = i;
					break;
				}
			}
			// 清理set, 保存所有符合条件的区间, (结束位置 >= k)
			while (!st.empty() && st.begin()->second < k) {
				st.erase(st.begin());
			}
			// set第一个就是我们要的区间最短的符合条件的元素
			hash[k] = res[ind] = st.empty() ? -1 : st.begin()->first;
		}
		return res;
	}
};

