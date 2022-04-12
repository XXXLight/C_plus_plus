#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int waysToPartition(vector<int>& nums, int k) {
		int n = nums.size();
		vector<long long> prefix(n);
		prefix[0] = nums[0];
		long long ans = 0;
		for (int i = 1; i < n; ++i) {
			prefix[i] = prefix[i - 1] + nums[i];
		}
		unordered_map<long long, long long> left, right; // ������iΪ���ֵ����Ҳ�ֵ�Ĺ�ϣ��
		for (int i = 0; i < n - 1; ++i) {
			long long cnt = prefix[n - 1] - 2 * prefix[i];
			right[cnt]++;
			if (cnt == 0) {
				++ans;
			}
		}
		long long prev = ans;
		for (int i = 0; i < n; ++i) {
			long long res = prev;
			long long cnt = prefix[n - 1] - 2 * prefix[i];
			ans = max(ans, left[nums[i] - k] + right[k - nums[i]]);
			left[cnt]++; // ����ʱ����2����ϣ��
			right[cnt]--;
		}
		return ans;
	}
};

