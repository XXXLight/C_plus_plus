#include<bits/stdc++.h>
using namespace std;

// 单调队列的方法，一个数据结构（deque），三个接口push,pop,max
// 单调减队列，队首元素肯定最大
// 时间复杂度：O(n)		空间复杂度：O(k)
class MonotonicQueue {
private:
	// 数据(空间换时间)
	deque<int> data;//单调队列用deque实现
public:
	// 对数据的操作,n是刚刚放进来的新数据
	void push(int n) {
		// 先弹
		while (!data.empty() && data.back() < n)	//队列尾部比刚刚放进来的n要小则弹出
			data.pop_back();
		// 再放，确保队首最大
		data.push_back(n);
	}

	int max() { return data.front(); }

	// 5 3 1这样的序列才需要弹出
	// 两种情况：3 4 5的时候，队列里是5，应该pop(3)，但是data.front() ！= 3，所以不会弹
	// 5 3 2的时候，队列里5 3 2，应该pop(5)且data.front() == 5，所以会弹出
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
			if (i < k - 1) { //先填满窗口的前 k - 1,[0,k-2]共k-1
				window.push(nums[i]);
			}
			else { // 窗口向前滑动
				window.push(nums[i]); // 窗口尾
				res.push_back(window.max());
				window.pop(nums[i - k + 1]); // 窗口首
			}
		}
		return res;
	}
};


// 优先队列（大根堆），默认是大顶堆，也就是堆顶是最大元素
//时间复杂度：O(nlog n)	空间复杂度：o(n)
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
			q.emplace(nums[i], i);//注意这句话的顺序
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

// 使用数据结构pair以及pair.first和pair.second来访问pair的元素，默认是按照pair的first进行比较
class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		int len = nums.size();
		if (len == 0) return {};
		priority_queue<pair<int, int>> p;	// 学会这种堆放pair的用法，绑定数据和索引
		vector<int> res;
		// 未形成窗口[0,k-2]  长度=k-1
		for (int i = 0; i <= k - 2; i++) {
			p.emplace(nums[i], i); // p.emplace(值，index)
		}
		// 开始形成窗口
		for (int i = k - 1; i < len; i++) {
			// 比当前小的都弹出
			while (!p.empty() && p.top().first <= nums[i]) p.pop();
			p.emplace(nums[i], i);
			// 排除窗口外元素的影响，窗口索引[i-k+1,1],所以窗口外是<=i-k
			while (!p.empty() && p.top().second <= i - k) p.pop();
			res.push_back(p.top().first);
		}
		return res;
	}
};

// 使用数据结构类来进行比较，必须重载类的<
class Solution {
public:
	// 把数据当成一个类放到队列之中，重载类的大小比较方法就可以了
	class A {
	public:
		A(int v, int i) :val(v), index(i) {};
		int val,index;
		// 理解两个const的含义，括号里的const表示对a<b的右边数据不会进行修改，函数尾部的const表示不会对类的数据进行修改
		inline bool operator <(const A &a)const {
			return val < a.val;
		}
	};
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		int n = nums.size();
		if (n == 0) return {};
		priority_queue<A> q;
		for (int i = 0; i < k; ++i) {
			// 把 [值，键] 压入，按值有序
			A a(nums[i], i);
			q.emplace(a);
		}
		// 堆顶元素为最大值，first为值
		vector<int> ans = { q.top().val };
		for (int i = k; i < n; ++i) {
			A a(nums[i], i);
			q.emplace(a);
			// 窗口外的堆元素破坏了窗口内的最值，应删除
			// 可以用特例 7 6 5 4 3 2 1来试
			while (q.top().index <= i - k) {
				q.pop();
			}
			ans.push_back(q.top().val);
		}
		return ans;
	}
};

// 使用tuple进行实现
class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		int n = nums.size();
		if (n == 0) return {};
		priority_queue<tuple<int, int>> q;
		for (int i = 0; i < k; ++i) {
			// 把 [值，键] 压入，按值有序
			tuple<int, int> a(nums[i], i);
			q.emplace(a);
		}
		// 堆顶元素为最大值，first为值
		vector<int> ans = { get<0>(q.top()) };// 访问tuple的元素使用get方法
		for (int i = k; i < n; ++i) {
			tuple<int, int> a(nums[i], i);
			q.emplace(a);
			// 窗口外的堆元素破坏了窗口内的最值，应删除
			// 可以用特例 7 6 5 4 3 2 1来试
			while (get<1>(q.top()) <= i - k) {
				q.pop();
			}
			ans.push_back(get<0>(q.top()));
		}
		return ans;
	}
};



// 暴力
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
