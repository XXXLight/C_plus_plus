#include<bits/stdc++.h>
using namespace std;


// �����Լ���ֱ�����ೢ��
class Solution {
public:
	int minCost(vector<int>& start, vector<int>& home, vector<int>& r, vector<int>& c) {
		int ans = 0;
		// x�����ƶ�
		// start[1,0]==>home[2,3]
		if (start[0] < home[0]) {
			for (int i = start[0] + 1; i <= home[0]; ++i) {
				ans += r[i];
			}
		}
		else {// [2,3]=>[1,0]
			for (int i = start[0] - 1; i >= home[0]; --i) {
				ans += r[i];
			}
		}
		// y�����ƶ�
		if (start[1] < home[1]) {// [1,0]===>[2,3]
			for (int i = start[1] + 1; i <= home[1]; ++i) {
				ans += c[i];
			}
		}
		else {// [2,3]===>[1,0]
			for (int i = start[1] - 1; i >= home[1]; --i) {
				ans += c[i];
			}
		}
		return ans;
	}
};