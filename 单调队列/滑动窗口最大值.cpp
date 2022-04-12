#include<bits/stdc++.h>
using namespace std;

// �������еķ���
class MonotonicQueue {
private:
	// ����
	deque<int> data;
public:
	// �����ݵĲ���
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
			if (i < k - 1) { //���������ڵ�ǰ k - 1
				window.push(nums[i]);
			}
			else { // ������ǰ����
				window.push(nums[i]);
				res.push_back(window.max());
				window.pop(nums[i - k + 1]);
			}
		}
		return res;
	}
};

// ���ȶ��У�����ѣ�
class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		int n = nums.size();
		if (n == 0) return {};
		priority_queue<pair<int, int>> q;
		for (int i = 0; i < k; ++i) {
			// �� [ֵ����] ѹ�룬��ֵ����
			q.emplace(nums[i], i);
		}
		// �Ѷ�Ԫ��Ϊ���ֵ��firstΪֵ
		vector<int> ans = { q.top().first };
		for (int i = k; i < n; ++i) {
			q.emplace(nums[i], i);
			// ������Ķ�Ԫ���ƻ��˴����ڵ���ֵ��Ӧɾ��
			// ���������� 7 6 5 4 3 2 1����
			while (q.top().second <= i - k) {
				q.pop();
			}
			ans.push_back(q.top().first);
		}
		return ans;
	}
};

