#include<bits/stdc++.h> 
using namespace std;

// sortȡ�м�
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		return nums[nums.size() / 2];
	}
};

// Ħ��ͶƱ�����������໥����
// ʱ�临�Ӷȣ�o��n�����ռ临�Ӷ�o(1)
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int x = 0, cx = 0;// x�����ѡ�ˣ�cx��ѡ�˵�Ʊ��
		for (int num : nums) {
			if (x == num) cx++;
			else if (cx == 0) x = num, cx++; // ��ǰ��Ϊ����
			else cx--;
		}
		cx = 0;
		// ��֤ x �Ƿ�Ϊ����
		for (int num : nums)
			if (num == x) cx++;
		return cx > nums.size() / 2 ? x : 0; // ��������ʱ���� 0
	}
};
