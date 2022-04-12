#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		int len = nums.size();
		vector<int> dp(len, 1);
		for (int j = 1; j < len; j++) {
			for (int i = 0; i < j; i++) {
				// j�ǳ����ˣ�i�Ǳ�����dp[j]Ҳ�ǳ���
				if (nums[i] < nums[j]) {
					dp[j] = max(dp[j], dp[i] + 1); //����������ֵ
				}
			}
		}
		// ���Ϊʲô
		return *max_element(dp.begin(), dp.end()); //ע�ⷵ�ص���dp�����е����ֵ
	}
};


// ������
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		vector<int> d(nums.size(), INT_MAX);
		for (auto num : nums) *lower_bound(d.begin(), d.end(), num) = num;
		return lower_bound(d.begin(), d.end(), INT_MAX) - d.begin();
	}
};



// �������������ƣ����Ƕ�β��Ԫ�ض�̬ά���������������ǣ���β����Ԫ�أ���ǰ���ֱ�ӷţ���ǰ��С���ж��ֲ����±�����滻
// res��¼·��
// ��ͼ�������
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		int len = nums.size();
		vector<int> res;
		res.push_back(nums[0]);
		for (int i = 1; i < len; i++) {
			if (nums[i] > res.back()) {
				res.push_back(nums[i]);
			}
			else {
				// ��>=nums[i]��index
				int index = lower_bound(res.begin(), res.end(), nums[i]) - res.begin();// ע����������ȥres.begin()
				res[index] = nums[i];
			}
		}
		return res.size();
	}
};




// �����������ÿ�ζ�̬���µĹ���
class Solution {
public:
	void printDp(vector<int>& v) {
		for (auto e : v) cout << e << " ";
		cout << endl;
	}
	int lengthOfLIS(vector<int>& nums) {
		int len = nums.size();
		vector<int> res;
		res.push_back(nums[0]);
		for (int i = 1; i < len; i++) {
			if (nums[i] > res.back()) {
				res.push_back(nums[i]);
			}
			else {
				// ��>=nums[i]��index
				int index = lower_bound(res.begin(), res.end(), nums[i]) - res.begin();// ע����������ȥres.begin()
				res[index] = nums[i];
			}
			printDp(res);
		}
		return res.size();
	}
};