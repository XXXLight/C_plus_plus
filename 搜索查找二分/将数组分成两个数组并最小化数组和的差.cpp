#include<bits/stdc++.h>
using namespace std;

class Solution {
	vector<int> nums;
	vector<int> v1[16], v2[16];

	void gao(int L, int R, vector<int> *v) {
		int n = R - L;
		for (int i = 0; i < (1 << n); i++) {
			int sm = 0, cnt = 0;
			for (int j = 0; j < n; j++)
				if (i >> j & 1) sm += nums[j + L], cnt++;
				else sm -= nums[j + L];
			v[cnt].push_back(sm);
		}

		for (int i = 0; i <= n; i++) sort(v[i].begin(), v[i].end());
	}

public:
	int minimumDifference(vector<int>& nums) {
		this->nums = nums;
		int n = nums.size() / 2;
		gao(0, n, v1);
		gao(n, n * 2, v2);
		// for(int i=0;i<16;i++){
		//     cout<<i<<":"<<endl;
		//     for(auto e:v1[i]){
		//         cout<<e<<" ";
		//     }
		//     cout<<endl;
		// }
		// for(int i=0;i<16;i++){
		//     cout<<i<<":"<<endl;
		//     for(auto e:v2[i]){
		//         cout<<e<<" ";
		//     }
		//     cout<<endl;
		// }

		int ans = 2e9;
		for (int i = 0; i <= n; i++) {
			for (int j = (int)v1[i].size() - 1, k = 0; j >= 0; j--) {
				while (k < v2[n - i].size() && v1[i][j] + v2[n - i][k] < 0) k++;
				if (k < v2[n - i].size()) ans = min(ans, abs(v1[i][j] + v2[n - i][k]));
				if (k - 1 >= 0) ans = min(ans, abs(v1[i][j] + v2[n - i][k - 1]));
			}
		}
		return ans;
	}
};
