#include<bits/stdc++.h>
using namespace std;

// �������еķ�����һ�����ݽṹ��deque���������ӿ�push,pop,max
// ���������У�����Ԫ�ؿ϶����
// ʱ�临�Ӷȣ�O(n)		�ռ临�Ӷȣ�O(k)
class MonotonicQueue {
private:
	// ����(�ռ任ʱ��)
	deque<int> data;//����������dequeʵ��
public:
	// �����ݵĲ���,n�ǸոշŽ�����������
	void push(int n) {
		// �ȵ�
		while (!data.empty() && data.back() < n)	//����β���ȸոշŽ�����nҪС�򵯳�
			data.pop_back();
		// �ٷţ�ȷ���������
		data.push_back(n);
	}

	int max() { return data.front(); }

	// 5 3 1���������в���Ҫ����
	// ���������3 4 5��ʱ�򣬶�������5��Ӧ��pop(3)������data.front() ��= 3�����Բ��ᵯ
	// 5 3 2��ʱ�򣬶�����5 3 2��Ӧ��pop(5)��data.front() == 5�����Իᵯ��
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
			if (i < k - 1) { //���������ڵ�ǰ k - 1,[0,k-2]��k-1
				window.push(nums[i]);
			}
			else { // ������ǰ����
				window.push(nums[i]); // ����β
				res.push_back(window.max());
				window.pop(nums[i - k + 1]); // ������
			}
		}
		return res;
	}
};


// ���ȶ��У�����ѣ���Ĭ���Ǵ󶥶ѣ�Ҳ���ǶѶ������Ԫ��
//ʱ�临�Ӷȣ�O(nlog n)	�ռ临�Ӷȣ�o(n)
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
			q.emplace(nums[i], i);//ע����仰��˳��
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

// ʹ�����ݽṹpair�Լ�pair.first��pair.second������pair��Ԫ�أ�Ĭ���ǰ���pair��first���бȽ�
class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		int len = nums.size();
		if (len == 0) return {};
		priority_queue<pair<int, int>> p;	// ѧ�����ֶѷ�pair���÷��������ݺ�����
		vector<int> res;
		// δ�γɴ���[0,k-2]  ����=k-1
		for (int i = 0; i <= k - 2; i++) {
			p.emplace(nums[i], i); // p.emplace(ֵ��index)
		}
		// ��ʼ�γɴ���
		for (int i = k - 1; i < len; i++) {
			// �ȵ�ǰС�Ķ�����
			while (!p.empty() && p.top().first <= nums[i]) p.pop();
			p.emplace(nums[i], i);
			// �ų�������Ԫ�ص�Ӱ�죬��������[i-k+1,1],���Դ�������<=i-k
			while (!p.empty() && p.top().second <= i - k) p.pop();
			res.push_back(p.top().first);
		}
		return res;
	}
};

// ʹ�����ݽṹ�������бȽϣ������������<
class Solution {
public:
	// �����ݵ���һ����ŵ�����֮�У�������Ĵ�С�ȽϷ����Ϳ�����
	class A {
	public:
		A(int v, int i) :val(v), index(i) {};
		int val,index;
		// �������const�ĺ��壬�������const��ʾ��a<b���ұ����ݲ�������޸ģ�����β����const��ʾ�����������ݽ����޸�
		inline bool operator <(const A &a)const {
			return val < a.val;
		}
	};
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		int n = nums.size();
		if (n == 0) return {};
		priority_queue<A> q;
		for (int i = 0; i < k; ++i) {
			// �� [ֵ����] ѹ�룬��ֵ����
			A a(nums[i], i);
			q.emplace(a);
		}
		// �Ѷ�Ԫ��Ϊ���ֵ��firstΪֵ
		vector<int> ans = { q.top().val };
		for (int i = k; i < n; ++i) {
			A a(nums[i], i);
			q.emplace(a);
			// ������Ķ�Ԫ���ƻ��˴����ڵ���ֵ��Ӧɾ��
			// ���������� 7 6 5 4 3 2 1����
			while (q.top().index <= i - k) {
				q.pop();
			}
			ans.push_back(q.top().val);
		}
		return ans;
	}
};

// ʹ��tuple����ʵ��
class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		int n = nums.size();
		if (n == 0) return {};
		priority_queue<tuple<int, int>> q;
		for (int i = 0; i < k; ++i) {
			// �� [ֵ����] ѹ�룬��ֵ����
			tuple<int, int> a(nums[i], i);
			q.emplace(a);
		}
		// �Ѷ�Ԫ��Ϊ���ֵ��firstΪֵ
		vector<int> ans = { get<0>(q.top()) };// ����tuple��Ԫ��ʹ��get����
		for (int i = k; i < n; ++i) {
			tuple<int, int> a(nums[i], i);
			q.emplace(a);
			// ������Ķ�Ԫ���ƻ��˴����ڵ���ֵ��Ӧɾ��
			// ���������� 7 6 5 4 3 2 1����
			while (get<1>(q.top()) <= i - k) {
				q.pop();
			}
			ans.push_back(get<0>(q.top()));
		}
		return ans;
	}
};



// ����
class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		if (nums.size() == 0) return {};
		vector<int> res;
		for (int i = 0; i <= nums.size() - k; i++) {
			int max_ = INT_MIN;
			for (int j = i; j < i + k; j++) {
				if (nums[j] > max_)
					max_ = nums[j];
			}
			res.push_back(max_);
		}
		return res;
	}
};
