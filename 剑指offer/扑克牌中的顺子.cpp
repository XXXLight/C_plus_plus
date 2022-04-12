#include<bits/stdc++.h>
using namespace std;
//1.学习三目运算符
//2.学习！用not来代替

class Solution {
public:
	bool isStraight(vector<int>& nums) {
		set<int> st;
		int maxV = INT_MIN, minV = INT_MAX;//直接用模板
		for (auto e : nums) {
			if (e == 0) continue;//跳过不做处理
			//后面表示不会碰到0
			if (not st.count(e)) {
				st.insert(e);
			}
			else if (st.count(e)) {
				return false;
			}
			maxV = max(e, maxV);   
			minV = min(e, minV);
		}
		return (maxV - minV < 5) ? true : false;
	}
};

