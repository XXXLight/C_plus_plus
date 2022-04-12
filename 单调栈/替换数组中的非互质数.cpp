#include<bits/stdc++.h>
using namespace std;

//   可以用这个例子进行调试：[899, 23, 20677]
//   [3,2,3,2,3,2,12]更好理解
class Solution {
public:
	vector<int> replaceNonCoprimes(vector<int> &nums) {
		vector<int> s = { nums[0] };
		for (int i = 1; i < nums.size(); ++i) {
			s.push_back(nums[i]);
			while (s.size() > 1) {
				int x = s.back(), y = s[s.size() - 2];// 去除栈顶的两个元素
				int g = gcd(x, y);// 求出最小公倍数
				if (g == 1) break; // 互质直接break
				s.pop_back();// 否则弹出尾部元素
				s.back() = (long)x * y / g;// 用新的值覆盖
			}
		}
		return s;
	}
};

// 只有__gcd没有__lcm.
class Solution {
public:
	vector<int> replaceNonCoprimes(vector<int>& nums) {
		vector<int> res;
		res.push_back(nums[0]);
		for (int i = 1; i < nums.size(); i++) {
			res.push_back(nums[i]);
			// 这样确保每次栈内肯定有大于等于两个元素
			while (res.size() > 1) {
				int st0 = res.back();// 取栈顶两个元素
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