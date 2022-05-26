#include<bits/stdc++.h>
using namespace std;



struct ChthollyNode {
	int l, r;
	mutable int v;
	ChthollyNode(int l, int r, int v) : l(l), r(r), v(v) {}
	bool operator<(const ChthollyNode &o) const { return l < o.l; }
};
class RangeModule {
public:
	std::set<ChthollyNode> tr;

	std::set<ChthollyNode>::iterator split(int pos) {
		auto it = tr.lower_bound(ChthollyNode(pos, 0, 0)); // 寻找左边大于等于pos的第一个节点
		if (it != tr.end() && it->l == pos) return it;
		it--;
		int l = it->l, r = it->r, v = it->v;
		tr.erase(it);
		tr.insert(ChthollyNode(l, pos - 1, v));
		return tr.insert(ChthollyNode(pos, r, v)).first;
	}

	void assign(int l, int r, int v) {
		auto itr = split(r + 1);
		auto itl = split(l);
		tr.erase(itl, itr);
		tr.insert(ChthollyNode(l, r, v));
	}

	bool check(int l, int r) {
		auto itr = split(r + 1);
		auto itl = split(l);
		auto it = itl;
		for (; it != itr; it++) {
			if (it->v == 0) return false;
		}
		return true;
	}

	RangeModule() {
		tr.insert(ChthollyNode(1, 1e9, 0));
	}

	void addRange(int left, int right) {
		assign(left, right - 1, 1);
	}

	bool queryRange(int left, int right) {
		return check(left, right - 1);
	}

	void removeRange(int left, int right) {
		assign(left, right - 1, 0);
	}
};

