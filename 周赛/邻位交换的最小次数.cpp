#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	int getMinSwaps(string num, int k) {
		if (num.empty())
			return 0;
		string temp(num);
		for (int i = 0; i < k; ++i)
			next_permutation(num.begin(), num.end());
		cout << num << " " << temp << " " << endl;
		int ans = 0;
		for (int i = 0; i < num.size(); ++i) {
			if (num[i] != temp[i]) {
				int j = i + 1;
				while (num[j] != temp[i]) {
					++j;
				}
				cout << i << " " << j << " " << endl;
				while (j > i) {
					swap(num[j], num[j - 1]), ++ans;
					j--;
				}
			}
		}
		return ans;
	}
};