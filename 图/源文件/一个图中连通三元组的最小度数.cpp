#include<bits/stdc++.h>
using namespace std;


//����ͼor����ͼ?
//�ڽӾ���(n*n)�����ڽӱ�
//��Ȼ��ǳ��ȣ�
//DFS����BFS
class Solution {
public:
	int minTrioDegree(int n, vector<vector<int>>& edges) {
		vector<vector<bool>> d(n, vector<bool>(n));//�����ڽӾ���
		vector<int> deg(n);//����
		for (auto &e : edges) {
			d[e[0] - 1][e[1] - 1] = d[e[1] - 1][e[0] - 1] = true;//����֮����ڱ�
			deg[e[0] - 1]++;//������1
			deg[e[1] - 1]++;//������1
		}
		int ans = INT_MAX;
		//����ö����Ԫ��
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j) {
				if (!d[i][j])
					continue;
				for (int k = j + 1; k < n; ++k) {
					if (d[i][k] && d[j][k])
						ans = min(ans, deg[i] + deg[j] + deg[k] - 6);
				}
			}
		return ans == INT_MAX ? -1 : ans;
	}
};

