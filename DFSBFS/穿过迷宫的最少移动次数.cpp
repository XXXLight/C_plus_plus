#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;


/*
������Ƚⷨ
- ����һ�������Ƚ��ȳ�����¼
- ����һ���ѱ����ļ��ϱ���ѭ��
- ���ڵ�ǰ���г�����һ�α������ƶ�������1
   - �������������ˮƽ������ֱ��Ȼ�������һ�ֿ��������������
   - һ���ҵ����򷵻ص�ǰ�ƶ������������

*/
class Solution {
private:
	// ���λ�ô��ĸ���ת��Ϊһ��long�����㷽ʽΪ (x1*100+y1)*100000 + (x2*100+y2)
	long convert(vector<int>& a)
	{
		return (long)(a[0] * 100 + a[1]) * 100000 + (long)(a[2] * 100 + a[3]);
	}

public:
	int minimumMoves(vector<vector<int>>& grid) {
		int n = grid.size();
		// ��Ե���(λ�ò��ɴ�)ֱ�ӷ���ʧ��
		if (grid[0][0] == 1 || grid[0][1] == 1 || grid[n - 1][n - 2] == 1 || grid[n - 1][n - 1] == 1)
		{
			return -1;
		}

		// �ĸ����¼���ֱ���β�͵�x��y��ͷ��x��y
		queue<vector<int>> q;
		// ���λ�ô��ĸ���ת��Ϊһ��long�����㷽ʽΪ (x1*100+y1)*100000 + (x2*100+y2)
		unordered_set<long> visited;

		// ��ʼ�����
		q.push({ 0, 0, 0, 1 });

		// Ŀ��
		vector<int> a = { n - 1, n - 2, n - 1, n - 1 };
		long target = convert(a);

		// ά�ֵ��ε��ƶ�����
		int step = 0;

		while (!q.empty())
		{
			for (int i = q.size(); i > 0; --i)
			{
				vector<int>& curr = q.front();
				// cout << step << " steo " << curr[0] << " " << curr[1] << " " << curr[2] << " " << curr[3] << endl;
				// ����ˮƽ���
				if (curr[0] == curr[2])
				{
					// ��: (x,y+1)��Ч
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
					// �� �� ˳ʱ�룺������������Ҫ��Ч
					if (curr[0] + 1 < n && grid[curr[0] + 1][curr[1]] == 0 && grid[curr[0] + 1][curr[3]] == 0)
					{
						// ��
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
						// ˳ʱ��
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
				// ������ֱ���
				if (curr[1] == curr[3])
				{
					// ��: (x+1,y)��Ч
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
					// �� �� ��ʱ�룺�ұ���������Ҫ��Ч
					if (curr[1] + 1 < n && grid[curr[0]][curr[1] + 1] == 0 && grid[curr[2]][curr[3] + 1] == 0)
					{
						// ��
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
						// ��ʱ��
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

			// ���һ����ȱ��������1
			++step;
		}

		// Ĭ��ʧ�ܷ���-1
		return -1;
	}
};

