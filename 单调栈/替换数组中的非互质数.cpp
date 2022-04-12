#include<bits/stdc++.h>
using namespace std;

//   ������������ӽ��е��ԣ�[899, 23, 20677]
//   [3,2,3,2,3,2,12]�������
class Solution {
public:
	vector<int> replaceNonCoprimes(vector<int> &nums) {
		vector<int> s = { nums[0] };
		for (int i = 1; i < nums.size(); ++i) {
			s.push_back(nums[i]);
			while (s.size() > 1) {
				int x = s.back(), y = s[s.size() - 2];// ȥ��ջ��������Ԫ��
				int g = gcd(x, y);// �����С������
				if (g == 1) break; // ����ֱ��break
				s.pop_back();// ���򵯳�β��Ԫ��
				s.back() = (long)x * y / g;// ���µ�ֵ����
			}
		}
		return s;
	}
};

// ֻ��__gcdû��__lcm.
class Solution {
public:
	vector<int> replaceNonCoprimes(vector<int>& nums) {
		vector<int> res;
		res.push_back(nums[0]);
		for (int i = 1; i < nums.size(); i++) {
			res.push_back(nums[i]);
			// ����ȷ��ÿ��ջ�ڿ϶��д��ڵ�������Ԫ��
			while (res.size() > 1) {
				int st0 = res.back();// ȡջ������Ԫ��
				int st1 = res[res.size() - 2];
				if (gcd(st0, st1) > 1) {
					res.pop_back();
					res.pop_back();
					res.push_back(lcm(st0, st1));
				}
				else {
					break;
				}
			}
		}
		return res;
	}
};