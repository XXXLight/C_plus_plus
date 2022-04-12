#include<bits/stdc++.h>
using namespace std;

// 单调队列的方法
class MonotonicQueue {
private:
	// 数据
	deque<int> data;
public:
	// 对数据的操作
	void push(int n) {
		while (!data.empty() && data.back() < n)
			data.pop_back();
		data.push_back(n);
	}

	int max() { return data.front(); }

	void pop(int n) {
		if (!data.empty() && data.front() == n)
			data.pop_front();
	}
};


class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		MonotonicQueue window;
		vector<int> res;
		for (int i = 0; i < nums.size(); i++) {
			if (i < k - 1) { //先填满窗口的前 k - 1
				window.push(nums[i]);
			}
			else { // 窗口向前滑动
				window.push(nums[i]);
				res.push_back(window.max());
				window.pop(nums[i - k + 1]);
			}
		}
		return res;
	}
};

// 优先队列（大根堆）
class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		int n = nums.size();
		if (n == 0) return {};
		priority_queue<pair<int, int>> q;
		for (int i = 0; i < k; ++i) {
			// 把 [值，键] 压入，按值有序
			q.emplace(nums[i], i);
		}
		// 堆顶元素为最大值，first为值
		vector<int> ans = { q.top().first };
		for (int i = k; i < n; ++i) {
			q.emplace(nums[i], i);
			// 窗口外的堆元素破坏了窗口内的最值，应删除
			// 可以用特例 7 6 5 4 3 2 1来试
			while (q.top().second <= i - k) {
				q.pop();
			}
			ans.push_back(q.top().first);
		}
		return ans;
	}
};

