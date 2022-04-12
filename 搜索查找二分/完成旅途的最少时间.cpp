#include<bits/stdc++.h>
using namespace std;


// ˼·2������ break
class Solution {
public:
	long long minimumTime(vector<int>& time, int totalTrips) {
		long long l = 1, r = 1e16;
		while (l < r) {// [l,r)
			long long m = (l + r) >> 1, cnt = 0;
			for (int i = 0; i < time.size(); ++i) {
				cnt += m / (long long)time[i];
				if (cnt >= totalTrips) {
					r = m;// [l,m)��[m,r)
					break;
				}
			}
			if (cnt < totalTrips) {
				l = m + 1;
			}
		} 
		// �˳�ѭ����������l=r,����return l/r������
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




// ����д������������������Ӻÿ�
class Solution {
public:
	long long minimumTime(vector<int>& time, int totalTrips) {
		// �ж� t ʱ�����Ƿ������� totalTrips ����;
		auto check = [&](long long t) -> bool {
			long long cnt = 0;
			for (int period : time) {
				cnt += t / period;
			}
			return cnt >= totalTrips;
		};

		// ���ֲ����½����Ͻ�
		long long l = 1;
		long long r = (long long)totalTrips * *max_element(time.begin(), time.end());
		// ���ֲ���Ѱ������Ҫ�����С�� t
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
