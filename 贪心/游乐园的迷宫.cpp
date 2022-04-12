#include<bits/stdc++.h>
using namespace std;




class Solution {
private:
	pair<int, int> Sub(pair<int, int> a, pair<int, int> b) {
		// ��� a ���� b ������
		return make_pair(a.first - b.first, a.second - b.second);
	}

	int Cross(pair<int, int> a, pair<int, int> b) {
		// ������ a ������ b ���������
		return a.first * b.second - a.second * b.first;
	}
public:
	vector<int> visitOrder(vector< vector<int> >& points, string dir) {
		int n = points.size();
		vector<bool> used(n, false);  // ��¼��ı�������� Falseδ���� / True�ѱ���
		vector< pair<int, int> > point;
		vector<int> order; // ��¼���ؽ��

		for (int i = 0; i < n; ++i) {
			point.push_back(make_pair(points[i][0], points[i][1]));
		}

		// ��������ĵ���Ϊ ��ʼ��
		int start = 0;
		for (int i = 1; i < n; ++i) {
			if (point[i] < point[start]) {
				start = i;
			}
		}
		used[start] = true;
		order.push_back(start);

		for (int i = 0; i < dir.size(); ++i) {
			int next = -1;
			if (dir[i] == 'L') {
				// ת����Ϊ L��ѡ����Է������ҵĵ�
				for (int j = 0; j < n; ++j) {
					if (!used[j]) {
						if (next == -1 || Cross(Sub(point[next], point[start]), Sub(point[j], point[start])) < 0) {
							next = j;
						}
					}
				}
			}
			else if (dir[i] == 'R') {
				// ת����Ϊ R��ѡ����Է�������ĵ�
				for (int j = 0; j < n; ++j) {
					if (!used[j]) {
						if (next == -1 || Cross(Sub(point[next], point[start]), Sub(point[j], point[start])) > 0) {
							next = j;
						}
					}
				}
			}
			// ���ؽ������ѡ��ĵ㣬������һ��ת������
			used[next] = true;
			order.push_back(next);
			start = next;
		}
		// ������һ��ʣ���
		for (int i = 0; i < n; ++i) {
			if (used[i] == false) {
				order.push_back(i);
			}
		}
		return order;
	}
};

