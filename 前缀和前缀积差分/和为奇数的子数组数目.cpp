#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int numOfSubarrays(vector<int>& arr) {
		const int MODULO = 1000000007;
		int odd = 0, even = 1;
		int subarrays = 0;
		int sum = 0;
		int length = arr.size();
		for (int i = 0; i < length; i++) {
			sum += arr[i];
			subarrays = (subarrays + (sum % 2 == 0 ? odd : even)) % MODULO;
			if (sum % 2 == 0) {
				even++;
			}
			else {
				odd++;
			}
		}
		return subarrays;
	}
};



class Solution {
public:
	const int MOD = 1e9 + 7;
	int numOfSubarrays(vector<int>& arr) {
		int len = arr.size();
		int cntEven = 1, cntOdd = 0;
		int res = 0;
		int sum = 0;
		for (int i = 0; i < len; i++) {
			sum += arr[i];// 求解前缀和
			if (sum % 2 == 0) {// 前缀和是偶数，加上前面前缀和是奇数的个数
				res += cntOdd;
				res %= MOD;
			}
			else {
				res += cntEven;
				res %= MOD;
			}
			// 前缀和是偶数，cntEven++
			if (sum % 2 == 0) cntEven++;
			else cntOdd++;
		}
		return res;
	}
};