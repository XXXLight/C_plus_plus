#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
	vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
		vector<int> res;
		map<int, int> mp;
		for (auto& e : flowers) {
			mp[e[0]]++;
			mp[e[1] + 1]--;
		}

		auto it1 = mp.begin(), it2 = mp.end();
		int i = 0, n = persons.size();
		int sum = 0;
		while (it1 != it2 && i < n) {

			if (persons[i] < it1->first) {
				res[i] = sum;
				i++;
			}
			sum += it1->second;
			it1++;
		}
		return res;
	}
};


int main() {
	vector<vector<int>> v = {{1, 6}, {3, 7}, {9, 12}, {4, 13}};
	vector<int> v1 = {2, 3, 7, 11};
	Solution().fullBloomFlowers(v, v1);
	return 0;
}