#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	int minJump(vector<int>& jump) {
		int n = jump.size();

		queue< pair<int, int> > q; // ��ǰλ�� idx���������� d
		// ��ʼֵ�����Ϊ 0 �ĵ���  �������� Ϊ0
		q.emplace(0, 0);

		// ĳһ��λ���Ѿ�����չ���ˣ��Ͳ���Ҫ���ٴ���չ��BFS���·
		// ��¼ĳ��λ���Ƿ���չ����seen
		vector<bool> seen(n, false);
		seen[0] = true;


		int preidx = 1;
		// BFS
		while (!q.empty()) {
			auto[idx, d] = q.front();
			q.pop();

			// ������չ
			int next = idx + jump[idx];
			if (next > n - 1) {
				// ��������
				// BFS ���·
				return d + 1;
			}
			if (!seen[next]) {
				seen[next] = true;
				q.emplace(next, d + 1);
			}

			// ������չ��O(n^2)
			// ĳһ��λ�ü���֮ǰ����λ�ö��Ѿ�����չ������ôһ�������·������Ҫ�ٴα���չ
			// preidx����¼ĳ��λ�ü���֮ǰλ�þ��ѱ���չ��ÿ�θ���preidx ����
			// for(int i = 0; i < idx; i++) {
			//     if(!seen[i]) {
			//         seen[i] = true;
			//         q.emplace(i, d + 1);
			//     }
			// }

			while (preidx < idx) {
				// ���ֻ�����һ��ȫ��λ�� ��O(n)
				if (!seen[preidx]) {
					seen[preidx] = true;
					q.emplace(preidx, d + 1);
				}
				preidx++;
			}
		}

		// �������������У���δ���أ�˵���޷�����
		return -1;

	}
};

