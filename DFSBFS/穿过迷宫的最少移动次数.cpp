#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;


/*
广度优先解法
- 保存一个队列先进先出来记录
- 保存一个已遍历的集合避免循环
- 基于当前队列长度做一次遍历，移动次数加1
   - 考虑两种情况，水平还是竖直，然后插入下一种可能情况到队列里
   - 一旦找到，则返回当前移动次数结果即可

*/
class Solution {
private:
	// 会把位置从四个点转换为一个long，计算方式为 (x1*100+y1)*100000 + (x2*100+y2)
	long convert(vector<int>& a)
	{
		return (long)(a[0] * 100 + a[1]) * 100000 + (long)(a[2] * 100 + a[3]);
	}

public:
	int minimumMoves(vector<vector<int>>& grid) {
		int n = grid.size();
		// 边缘情况(位置不可达)直接返回失败
		if (grid[0][0] == 1 || grid[0][1] == 1 || grid[n - 1][n - 2] == 1 || grid[n - 1][n - 1] == 1)
		{
			return -1;
		}

		// 四个点记录，分别是尾巴的x和y，头的x和y
		queue<vector<int>> q;
		// 会把位置从四个点转换为一个long，计算方式为 (x1*100+y1)*100000 + (x2*100+y2)
		unordered_set<long> visited;

		// 起始点插入
		q.push({ 0, 0, 0, 1 });

		// 目标
		vector<int> a = { n - 1, n - 2, n - 1, n - 1 };
		long target = convert(a);

		// 维持档次的移动次数
		int step = 0;

		while (!q.empty())
		{
			for (int i = q.size(); i > 0; --i)
			{
				vector<int>& curr = q.front();
				// cout << step << " steo " << curr[0] << " " << curr[1] << " " << curr[2] << " " << curr[3] << endl;
				// 考虑水平情况
				if (curr[0] == curr[2])
				{
					// 右: (x,y+1)有效
					if (curr[3] + 1 < n && grid[curr[2]][curr[3] + 1] == 0)
					{
						vector<int> next = { curr[2], curr[3], curr[2], curr[3] + 1 };
						long nextLong = convert(next);
						if (nextLong == target)
						{
							return step + 1;
						}
						else if (visited.find(nextLong) == visited.end())
						{
							visited.insert(nextLong);
							q.emplace(next);
						}
					}
					// 下 或 顺时针：下面两个至少要有效
					if (curr[0] + 1 < n && grid[curr[0] + 1][curr[1]] == 0 && grid[curr[0] + 1][curr[3]] == 0)
					{
						// 下
						{
							vector<int> next = { curr[0] + 1, curr[1], curr[0] + 1, curr[3] };
							long nextLong = convert(next);
							if (nextLong == target)
							{
								return step + 1;
							}
							else if (visited.find(nextLong) == visited.end())
							{
								visited.insert(nextLong);
								q.emplace(next);
							}
						}
						// 顺时针
						{
							vector<int> next = { curr[0], curr[1], curr[2] + 1, curr[1] };
							long nextLong = convert(next);
							if (nextLong == target)
							{
								return step + 1;
							}
							else if (visited.find(nextLong) == visited.end())
							{
								visited.insert(nextLong);
								q.emplace(next);
							}
						}
					}
				}
				// 考虑竖直情况
				if (curr[1] == curr[3])
				{
					// 下: (x+1,y)有效
					if (curr[2] + 1 < n && grid[curr[2] + 1][curr[3]] == 0)
					{
						vector<int> next = { curr[2], curr[1], curr[2] + 1, curr[3] };
						long nextLong = convert(next);
						if (nextLong == target)
						{
							return step + 1;
						}
						else if (visited.find(nextLong) == visited.end())
						{
							visited.insert(nextLong);
							q.emplace(next);
						}
					}
					// 右 或 逆时针：右边两个至少要有效
					if (curr[1] + 1 < n && grid[curr[0]][curr[1] + 1] == 0 && grid[curr[2]][curr[3] + 1] == 0)
					{
						// 右
						{
							vector<int> next = { curr[0], curr[1] + 1, curr[2], curr[3] + 1 };
							long nextLong = convert(next);
							if (nextLong == target)
							{
								return step + 1;
							}
							else if (visited.find(nextLong) == visited.end())
							{
								visited.insert(nextLong);
								q.emplace(next);
							}
						}
						// 逆时针
						{
							vector<int> next = { curr[0], curr[1], curr[0], curr[1] + 1 };
							long nextLong = convert(next);
							if (nextLong == target)
							{
								return step + 1;
							}
							else if (visited.find(nextLong) == visited.end())
							{
								visited.insert(nextLong);
								q.emplace(next);
							}
						}
					}
				}

				q.pop();
			}

			// 完成一次深度遍历，则加1
			++step;
		}

		// 默认失败返回-1
		return -1;
	}
};

