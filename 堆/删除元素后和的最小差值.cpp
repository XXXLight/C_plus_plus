#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	long long minimumDifference(vector<int>& nums) {
		int n = nums.size() / 3;
		priority_queue<int, vector<int>, greater<int>> pq(nums.begin() + n * 2, nums.end()); // Ð¡¶¥¶Ñ
		long long sum[n + 1];
		sum[n] = accumulate(nums.begin() + n * 2, nums.end(), 0l);
		for (int i = 2 * n - 1; i >= n; --i)
		{
			sum[i - n] = sum[i - n + 1];
			if (nums[i] > pq.top())
			{
				sum[i - n] -= pq.top();
				pq.pop();
				sum[i - n] += nums[i];
				pq.push(nums[i]);
			}
		}

		long long ans = LONG_MAX;
		priority_queue<int> _pq(nums.begin(), nums.begin() + n);
		long long pre = accumulate(nums.begin(), nums.begin() + n, 0l);

		for (int i = n; i <= 2 * n; ++i)
		{
			ans = min(ans, pre - sum[i - n]);
			if (nums[i] < _pq.top())
			{
				pre -= _pq.top();
				_pq.pop();
				pre += nums[i];
				_pq.push(nums[i]);
			}
		}

		return ans;
	}
};

