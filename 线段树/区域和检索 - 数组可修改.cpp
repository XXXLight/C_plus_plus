#include<bits/stdc++.h>
using namespace std;


class NumArray {
public:
	vector<int> Bit, _nums; // 树状数组 Binary Indexed Tree
	int lowbit(int x) {
		return x & -x;
	}
	// 返回原始数组_nums的前x项之和，即[0,i-1]项之和
	int getSum(int x) {
		int ans = 0;
		while (x >= 1) {
			ans += Bit[x];
			x -= lowbit(x);
		}
		return ans;
	}
	// 单点修改，传入原始数组的index+1作为k
	void add(int k, int v) {
		while (k < Bit.size()) {
			Bit[k] += v;
			k += lowbit(k);
		}
	}
	// 其他接口的功能在构造函数里进行测试
	NumArray(vector<int>& nums) {
		Bit.resize(nums.size() + 1);// 树状数组的下标从1开始
		for (int i = 0; i < nums.size(); i++) {
			// 单点修改，原始树状数组nums[i]=0
			add(i + 1, nums[i]);
			_nums.push_back(nums[i]);
		}
		// C[1] = A[1];
		// C[2] = A[1] + A[2];
		// C[3] = A[3];
		// C[4] = A[1] + A[2] + A[3] + A[4];
		// C[5] = A[5];
		// C[6] = A[5] + A[6];
		// C[7] = A[7];
		// C[8] = A[1] + A[2] + A[3] + A[4] + A[5] + A[6] + A[7] + A[8];
				// _nums就是原始数组
				// for(auto e:_nums) cout<<e<<" ";
				// cout<<endl;
				// // Bit是树状数组，下标从1开始
				// for(auto e:Bit) cout<<e<<" ";
				// cout<<endl;
				// 从打印结果可以验证两者间的关系

				// update(1,9);
				// for(auto e:_nums) cout<<e<<" ";
	}
	// 原始数组的index位置修改为val
	// 原始数组是A[i],i=[0,n-1],进行add操作，也就是A[index]+=val-_nums[index]
	void update(int index, int val) {
		// 修改原数组index位置等价于修改树状数组index+1位置的数据，由_nums[index]--->val，增加了val-nums[index]
		add(index + 1, val - _nums[index]); // 下标从1开始
		// 单点修改
		_nums[index] = val;
	}

	int sumRange(int left, int right) {
		return getSum(right + 1) - getSum(left);
		// 想象一下前缀和的公式就很好理解了
	}
};