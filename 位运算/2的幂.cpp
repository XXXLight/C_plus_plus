#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:
	bool isPowerOfTwo(int n) {
		return (n > 0) && ((n&(n - 1)) == 0);
	}
};