#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	/*
	模拟退火 算法 :

	一个可以尽量达到全局最优的算法

	每次随机交换序列中的两个位置 来判断当前的序列是否可以比原始序列更优

	1. 若比原始序列更优,则保留交换
	2. 否则按一定概率保留交换 (这样才有机会达到全局最优)

	*/
	int b, n;
	vector<int> w;
	int ans;
	int cal() {
		int res = 0;
		int s = 0;
		for (int i = 0; i < w.size(); i++) {
			s += w[i];
			if (s % b == 0) {
				res++;
				s = 0;
			}
		}
		if (s > 0) res++;
		ans = max(ans, res);
		return res;
	}
	// 模拟退火 算法
	void simulate_anneal() {
		random_shuffle(w.begin(), w.end());
		// 初始化一个序列

		for (double t = 1e6; t > 1e-5; t *= 0.97) {
			// 模拟退火的过程 t 为 温度 慢慢下降的过程
			// 越到后面整个状态要更趋于稳定
			// 即当 t 越低 保留操作概率下降
			int i = rand() % n;
			int j = rand() % n;
			int x = cal();// 原先序列的 "值"
			swap(w[i], w[j]);// 交换两个位置
			int y = cal();// 交换后序列的 "值"
			int delta = y - x;// 评价函数
			if (delta < 0 && (exp(delta / t) != (double)rand() / RAND_MAX)) {
				// 当 y 小于 x 时 , 一定概率 exp(-1 * delta / t) 保留操作
				swap(w[i], w[j]);
			}
		}
		return;
	}
	int maxHappyGroups(int b_, vector<int>& g) {
		b = b_;
		if (b == 1) return g.size();
		w.clear();
		// 小的优化，在序列中不加入 取模后为 0 的数
		int res = 0;
		for (auto& i : g) {
			if (i % b == 0) res++;
			else w.push_back(i % b);
		}
		n = w.size();
		if (n < 2) return res + n;
		ans = 0;
		for (int i = 0; i < 30; i++) {
			simulate_anneal();
			// 循环多次模拟退火算法
		}
		return ans + res;
	}
};

