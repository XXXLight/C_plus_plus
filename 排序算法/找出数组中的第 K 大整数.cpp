#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	string kthLargestNumber(vector<string>& nums, int k) {
		//���Ȳ�ͬ���ȳ��ȣ��������ַ�������
		sort(nums.begin(), nums.end(), [](const string &e1, const string &e2) {if (e1.size() != e2.size()) return e1.size() > e2.size(); else return e1 > e2; });
		return nums[k - 1];
	}
};