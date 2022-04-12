#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	/*
	ģ���˻� �㷨 :

	һ�����Ծ����ﵽȫ�����ŵ��㷨

	ÿ��������������е�����λ�� ���жϵ�ǰ�������Ƿ���Ա�ԭʼ���и���

	1. ����ԭʼ���и���,��������
	2. ����һ�����ʱ������� (�������л���ﵽȫ������)

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
	// ģ���˻� �㷨
	void simulate_anneal() {
		random_shuffle(w.begin(), w.end());
		// ��ʼ��һ������

		for (double t = 1e6; t > 1e-5; t *= 0.97) {
			// ģ���˻�Ĺ��� t Ϊ �¶� �����½��Ĺ���
			// Խ����������״̬Ҫ�������ȶ�
			// ���� t Խ�� �������������½�
			int i = rand() % n;
			int j = rand() % n;
			int x = cal();// ԭ�����е� "ֵ"
			swap(w[i], w[j]);// ��������λ��
			int y = cal();// ���������е� "ֵ"
			int delta = y - x;// ���ۺ���
			if (delta < 0 && (exp(delta / t) != (double)rand() / RAND_MAX)) {
				// �� y С�� x ʱ , һ������ exp(-1 * delta / t) ��������
				swap(w[i], w[j]);
			}
		}
		return;
	}
	int maxHappyGroups(int b_, vector<int>& g) {
		b = b_;
		if (b == 1) return g.size();
		w.clear();
		// С���Ż����������в����� ȡģ��Ϊ 0 ����
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
			// ѭ�����ģ���˻��㷨
		}
		return ans + res;
	}
};

