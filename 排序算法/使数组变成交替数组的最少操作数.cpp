#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	unordered_map<int, int> mp1, mp2;
	int minimumOperations(vector<int>& nums) {
		if (nums.size() == 1) return 0;
		vector<int> v1, v2;
		for (int i = 0; i < nums.size(); i++) {
			if (i & 1) mp1[nums[i]]++;
			else mp2[nums[i]]++;
		}
		vector<vector<int>> vv1, vv2;
		for (auto&[u, v] : mp1) {
			vv1.push_back({ u,v });
		}
		for (auto&[u, v] : mp2) {
			vv2.push_back({ u,v });
		}
		sort(vv1.begin(), vv1.end(), [&](auto& e1, auto& e2) {
			return e1[1] > e2[1];
		});
		sort(vv2.begin(), vv2.end(), [&](auto& e1, auto& e2) {
			return e1[1] > e2[1];
		});
		// 注意一：不加引用会超时
		//sort(vv1.begin(), vv1.end(), [](auto e1, auto e2) {
		//	return e1[1] > e2[1];
		//});
		//sort(vv2.begin(), vv2.end(), [](auto e1, auto e2) {
		//	return e1[1] > e2[1];
		//});
		// 注意二：
		// 排序的时候加等号会报错
		/*sort(vv1.begin(), vv1.end(), [](auto& e1, auto& e2) {
			return e1[1] >= e2[1];
		});
		sort(vv2.begin(), vv2.end(), [](auto& e1, auto& e2) {
			return e1[1] >= e2[1];
		});*/
		//Line 1034: Char 9 : runtime error : reference binding to misaligned address 0xbebebebebebebec2 for type 'int', which requires 4 byte alignment(stl_vector.h)
		//	0xbebebebebebebec2 : note : pointer points here
		//	<memory cannot be printed>

		int cnt = 0;
		if (vv1.size() == 1 && vv2.size() == 1) {
			if (vv1[0][0] == vv2[0][0]) {
				cnt = max(vv1[0][1], vv2[0][1]);
			}
			else {
				cnt = vv1[0][1] + vv2[0][1];
			}
		}
		else if (vv1.size() == 1 && vv2.size() >= 1) {
			if (vv1[0][0] == vv2[0][0]) {
				cnt = vv1[0][1] + vv2[1][1];
			}
			else {
				cnt = vv1[0][1] + vv2[0][1];
			}
		}
		else if (vv2.size() == 1 && vv1.size() >= 1) {
			if (vv1[0][0] == vv2[0][0]) {
				cnt = vv2[0][1] + vv1[1][1];
			}
			else {
				cnt = vv1[0][1] + vv2[0][1];
			}
		}
		else {
			if (vv1[0][0] != vv2[0][0]) {
				cnt = vv1[0][1] + vv2[0][1];
			}
			else {
				cnt = max({ vv1[1][1] + vv2[0][1],vv1[0][1] + vv2[1][1] });
			}
		}
		return nums.size() - cnt;
	}
};