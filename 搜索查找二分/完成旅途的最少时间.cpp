#include<bits/stdc++.h>
using namespace std;


// 思路2：提早 break
class Solution {
public:
	long long minimumTime(vector<int>& time, int totalTrips) {
		long long l = 1, r = 1e16;
		while (l < r) {// [l,r)
			long long m = (l + r) >> 1, cnt = 0;
			for (int i = 0; i < time.size(); ++i) {
				cnt += m / (long long)time[i];
				if (cnt >= totalTrips) {
					r = m;// [l,m)和[m,r)
					break;
				}
			}
			if (cnt < totalTrips) {
				l = m + 1;
			}
		} 
		// 退出循环的条件是l=r,所以return l/r都可以
		return l;
	}
};





class Solution {
public:
	long long minimumTime(vector<int>& time, int totalTrips) {
		long long l = 1, r = 1e16;
		while (l <= r) {
			long long m = (l + r) >> 1, cnt = 0;
			for (int i = 0; i < time.size(); ++i) {
				cnt += m / (long long)time[i];
				if (cnt >= totalTrips) {
					r = m - 1;
					break;
				}
			}
			if (cnt < totalTrips) {
				l = m + 1;
			}
		}
		return l;
	}
};




// 这种写法更加清晰，代码更加好看
class Solution {
public:
	long long minimumTime(vector<int>& time, int totalTrips) {
		// 判断 t 时间内是否可以完成 totalTrips 趟旅途
		auto check = [&](long long t) -> bool {
			long long cnt = 0;
			for (int period : time) {
				cnt += t / period;
			}
			return cnt >= totalTrips;
		};

		// 二分查找下界与上界
		long long l = 1;
		long long r = (long long)totalTrips * *max_element(time.begin(), time.end());
		// 二分查找寻找满足要求的最小的 t
		while (l <= r) {
			long long mid = l + (r - l) / 2;
			if (check(mid)) {
				r = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}
		return l;
	}
};
