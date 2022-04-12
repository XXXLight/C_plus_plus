#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Solution {
public:
	typedef pair<int, int> PII;

	// f[i] ��ʾi�ұߵ�һ��û�б�ѯ�ʵ�λ��
	vector<int> f;

	int find(int x) {
		if (f[x] == x) return f[x];
		return f[x] = find(f[x]);
	}

	// �������䳤�ȴ�С��������
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
		// ������˵��С��������
		sort(intervals.begin(), intervals.end());
		int n = queries.size();
		// ��¼һ�²�ѯ��index
		vector<pair<int, int>> que;
		for (int i = 0; i < n; ++i) {
			que.push_back(make_pair(queries[i], i));
		}
		// ��ѯ��С��������
		sort(que.begin(), que.end());
		// ������
		vector<int> res(n);
		// ����Ѿ��в鵽��, hash��¼һ��
		unordered_map<int, int> hash;
		// �������߲�ѯ, query��С����, st����(����, ����λ��)
		set<pair<int, int>> st;
		int cur = 0;
		for (auto q : que) {
			// Ҫ��ѯ��ֵ��index
			int k = q.first, ind = q.second;
			if (hash.count(k)) {
				res[ind] = hash[k];
				continue;
			}
			// �����ܷ���Ҫ����������set (��ʼλ�� <= k)
			for (int i = cur; i < intervals.size(); ++i) {
				if (intervals[i][0] <= k) {
					st.insert({ intervals[i][1] - intervals[i][0] + 1, intervals[i][1] });
				}
				else {
					cur = i;
					break;
				}
			}
			// ����set, �������з�������������, (����λ�� >= k)
			while (!st.empty() && st.begin()->second < k) {
				st.erase(st.begin());
			}
			// set��һ����������Ҫ��������̵ķ���������Ԫ��
			hash[k] = res[ind] = st.empty() ? -1 : st.begin()->first;
		}
		return res;
	}
};

