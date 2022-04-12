#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;


class Solution {
public:
	int minDays(int n) {
		int ans = 0;
		queue<int> Q;
		unordered_set<int> us;// ���BFS�����г��ֵ����нڵ�
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


// дBFSʱ��Ҫ˼�������⣺
// 1�������ʲô����Ϊ���Ҫ���ȷŵ�������ȥ
// 2���յ�/�˳�������ʲô��
class Solution {
public:
	unordered_map<int, bool> mp;
	int minDays(int n) {
		queue<int> q;
		q.push(n);
		int cnt = 0;// cnt��¼����
		while (!q.empty()) {
			// BFS�漰�����������ʱ�����Ҫ�õ�forѭ������
			for (int i = q.size(); i > 0; i--) {
				int n = q.front();
				if (n == 0) return cnt; //����0�ˣ����Է��ؽ��
				q.pop();
				if (n % 2 == 0 && (not mp.count(n / 2))) { q.push(n / 2); mp[n / 2] = true; }
				if (n % 3 == 0 && (not mp.count(n / 3))) { q.push(n / 3); mp[n / 3] = true; }
				q.push(n - 1); mp[n - 1] = true;
			}
			cnt++; // BFS�Ĳ���++
		}
		return -1;
	}
};