#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
		int n = plants.size(), ans = 0, a = capacityA, b = capacityB;
		// ���Ĵ��ļ�鷽ʽ
		for (int i = 0, j = n - 1; i < j; ++i, --j) {
			if (a < plants[i]) a = capacityA, ++ans;
			a -= plants[i];
			if (b < plants[j]) b = capacityB, ++ans;
			b -= plants[j];
		}
		if (n & 1 && max(a, b) < plants[n / 2]) ++ans;
		return ans;
	}
};


class Solution {
public:
	int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
		int res = 0;   // ����ˮ�޴���
		int n = plants.size();   // ����λ��
		int posa = 0, posb = n - 1;   // ����ʣ��ˮ��
		int vala = capacityA, valb = capacityB;
		// ģ������ǰ�Ľ�ˮ����
		while (posa < posb) {
			if (vala < plants[posa]) {
				++res;
				vala = capacityA - plants[posa];
			}
			else {
				vala -= plants[posa];
			}
			++posa;
			if (valb < plants[posb]) {
				++res;
				valb = capacityB - plants[posb];
			}
			else {
				valb -= plants[posb];
			}
			--posb;
		}
		// ģ����������ܵĽ�ˮ����
		if (posa == posb) {
			if (vala >= valb && vala < plants[posa]) {
				++res;
			}
			if (vala < valb && valb < plants[posb]) {
				++res;
			}
		}
		return res;
	}
};
