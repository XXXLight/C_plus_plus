#include<bits/stdc++.h>
using namespace std;


//无向图or有向图?
//邻接矩阵(n*n)还是邻接表？
//入度还是出度？
//DFS还是BFS
class Solution {
public:
	int minTrioDegree(int n, vector<vector<int>>& edges) {
		vector<vector<bool>> d(n, vector<bool>(n));//构造邻接矩阵
		vector<int> deg(n);//度数
		for (auto &e : edges) {
			d[e[0] - 1][e[1] - 1] = d[e[1] - 1][e[0] - 1] = true;//两点之间存在边
			deg[e[0] - 1]++;//度数加1
			deg[e[1] - 1]++;//度数加1
		}
		int ans = INT_MAX;
		//暴力枚举三元组
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

