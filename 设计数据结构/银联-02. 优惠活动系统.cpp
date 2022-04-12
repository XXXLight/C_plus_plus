#include<bits/stdc++.h>
using namespace std;


struct act {
	int id, p, dis, number, ul;
	int left;
	map<int, int> user;

	act() {}
	act(int _id, int _p, int _dis, int _number, int _ul) {
		id = _id, p = _p, dis = _dis, number = _number, ul = _ul;
		left = number;
	}
};

class DiscountSystem {
public:
	DiscountSystem() {

	}

	void addActivity(int actId, int priceLimit, int discount, int number, int userLimit) {
		m[actId] = act(actId, priceLimit, discount, number, userLimit);
	}

	void removeActivity(int actId) {
		m.erase(actId);
	}

	int consume(int userId, int cost) {
		int maxDis = 0, id = -1;
		for (auto &e : m) {
			act &a = e.second;
			if (a.p <= cost && a.left > 0) {
				auto it = a.user.find(userId);
				if ((it == a.user.end() || it->second < a.ul) && a.dis > maxDis) {
					maxDis = a.dis;
					id = e.first;
				}
			}
		}
		if (id != -1) {
			m[id].left--;
			m[id].user[userId]++;
		}
		return cost - maxDis;
	}

	map<int, act> m;
};
