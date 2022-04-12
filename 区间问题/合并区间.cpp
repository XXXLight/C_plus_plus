#include<bits/stdc++.h>
using namespace std;

// ʱ�临�ӶȺͿռ临�Ӷ����������
// ʱ�临�Ӷȣ�o(nlog(n))
// �ռ临�Ӷȣ�o(log(n))
class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		// ����������
		sort(intervals.begin(), intervals.end());
		vector<vector<int>> res;
		// �ý������״̬��Ϊѭ������
		for (int i = 0; i < intervals.size(); i++) {
			// L,R�ǵ�ǰ����
			int L = intervals[i][0], R = intervals[i][1];
			// res.back����һ������
			if (res.empty() || res.back()[1] < L) {
				// û�н����ŵ�ǰ�ļ���
				res.push_back({ L,R });
			}
			else if (res.back()[1] >= L) {
				// �н�����������
				res.back()[1] = max(res.back()[1], R);
			}
		}
		return res;
	}
};