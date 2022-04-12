#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;


class Solution {
public:
	int minDays(int n) {
		int ans = 0;
		queue<int> Q;
		unordered_set<int> us;// 存放BFS过程中出现的所有节点
		Q.push(n);
		us.insert(n);

		while (!Q.empty()) {
			for (int i = Q.size(); i > 0; i--) {
				int tmp = Q.front();
				Q.pop();
				if (tmp == 0) return ans;

				if (tmp % 2 == 0 && !us.count(tmp / 2)) {
					Q.push(tmp / 2);
					us.insert(tmp / 2);
				}
				if (tmp % 3 == 0 && !us.count(tmp / 3)) {
					Q.push(tmp / 3);
					us.insert(tmp / 3);
				}
				if (!us.count(tmp - 1)) {
					Q.push(tmp - 1);
					us.insert(tmp - 1);
				}
			}
			ans++;
		}
		return 0;
	}
};


// 写BFS时需要思考的问题：
// 1、起点是什么，因为这个要首先放到队列中去
// 2、终点/退出条件是什么？
class Solution {
public:
	unordered_map<int, bool> mp;
	int minDays(int n) {
		queue<int> q;
		q.push(n);
		int cnt = 0;// cnt记录层数
		while (!q.empty()) {
			// BFS涉及到计算层数的时候就需要用到for循环遍历
			for (int i = q.size(); i > 0; i--) {
				int n = q.front();
				if (n == 0) return cnt; //减到0了，可以返回结果
				q.pop();
				if (n % 2 == 0 && (not mp.count(n / 2))) { q.push(n / 2); mp[n / 2] = true; }
				if (n % 3 == 0 && (not mp.count(n / 3))) { q.push(n / 3); mp[n / 3] = true; }
				q.push(n - 1); mp[n - 1] = true;
			}
			cnt++; // BFS的层数++
		}
		return -1;
	}
};