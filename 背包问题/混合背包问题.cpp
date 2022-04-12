#include<bits/stdc++.h>
using namespace std;

int maxValue(int N, int V, vector<int>& s, vector<int>& v, vector<int>& w) {
	vector<int> worth, volume;
	for (int i = 0; i < N; i++) {
		int type = s[i];
		if (type > 0) { // �����ر�������ת��Ϊ 0-1 ��������
			for (int k = 1; k <= type; k *= 2) {
				type -= k;
				worth.push_back(w[i] * k);
				volume.push_back(v[i] * k);
			}
			if (type > 0) {
				worth.push_back(w[i] * type);
				volume.push_back(v[i] * type);
			}
		}
		else if (type == -1) {
			worth.push_back(w[i]);
			volume.push_back(v[i]);
		}
		else { // ������ȫ�������� worth ��ת���������
			worth.push_back(-w[i]);
			volume.push_back(v[i]);
		}
	}

	vector<int> dp(V + 1);
	for (int i = 0; i < worth.size(); i++) {
		int wor = worth[i];
		int vol = volume[i];
		if (wor < 0) { // ��ȫ��������
			for (int j = vol; j <= V; j++) {
				dp[j] = max(dp[j], dp[j - vol] - wor); // �� worth ���·�תΪ������
			}
		}
		else { // ��ԭ 0-1 ������Ʒ�� �� ���ɶ��ر���ת�ƹ����� 0-1 �������⡱
			for (int j = V; j >= vol; j--) {
				dp[j] = max(dp[j], dp[j - vol] + wor);
			}
		}
	}
	return dp[V];
}
