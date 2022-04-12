#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
	vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
		vector<vector<bool>> graph(numCourses, vector<bool>(numCourses, 0));
		// 构建图
		for (auto& p : prerequisites)
		{
			graph[p[0]][p[1]] = true;
			// cout << p[0] << " " << p[1] << endl;
		}
		for (int k = 0; k < numCourses; ++k)
			for (int i = 0; i < numCourses; ++i)
				for (int j = 0; j < numCourses; ++j)
					if (graph[i][k] && graph[k][j])  graph[i][j] = true;
		// graph[i][j] |= graph[i][k] && graph[k][j];
// 遍历quries直接从graph得到结果
		int n = queries.size();
		vector<bool> res(n);
		for (int i = 0; i < n; ++i)
		{
			// cout << "res " << i << " : " << graph[queries[i][0]][queries[i][1]] << endl;
			res[i] = graph[queries[i][0]][queries[i][1]];
		}
		return res;
	}
};





