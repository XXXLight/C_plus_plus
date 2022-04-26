#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	int maxTrailingZeros(vector<vector<int>>& grid) {
		int n = grid.size(), m = grid[0].size();
		vector<vector<int>> f2(n + 1), g2(n + 1), f5(n + 1), g5(n + 1);
		for (int i = 0; i <= n; i++) f2[i] = g2[i] = f5[i] = g5[i] = vector<int>(m + 1);
		for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
			int x = grid[i - 1][j - 1];
			int two = 0, five = 0;
			while (x % 2 == 0) two++, x /= 2;
			while (x % 5 == 0) five++, x /= 5;
			f2[i][j] = f2[i][j - 1] + two;
			g2[i][j] = g2[i - 1][j] + two;
			f5[i][j] = f5[i][j - 1] + five;
			g5[i][j] = g5[i - 1][j] + five;
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
			// 从左边出发，到上边结束
			ans = max(ans, min(f2[i][j] + g2[i - 1][j], f5[i][j] + g5[i - 1][j]));
			// 从左边出发，到下边结束
			ans = max(ans, min(f2[i][j] + g2[n][j] - g2[i][j], f5[i][j] + g5[n][j] - g5[i][j]));
			// 从右边出发，到上边结束
			ans = max(ans, min(f2[i][m] - f2[i][j] + g2[i][j], f5[i][m] - f5[i][j] + g5[i][j]));
			// 从右边出发，到下边结束
			ans = max(ans, min(f2[i][m] - f2[i][j] + g2[n][j] - g2[i - 1][j], f5[i][m] - f5[i][j] + g5[n][j] - g5[i - 1][j]));
		}
		return ans;
	}
};





#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> m) {
	int r = m.size(), c = m[0].size();
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
class Solution {
public:
	int maxTrailingZeros(vector<vector<int>>& grid) {
		int n = grid.size(), m = grid[0].size();
		// 纵向、横向；2或者5
		vector<vector<int>> f2(n + 1), g2(n + 1), f5(n + 1), g5(n + 1);
		for (int i = 0; i <= n; i++) f2[i] = g2[i] = f5[i] = g5[i] = vector<int>(m + 1);
		for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
			int x = grid[i - 1][j - 1];
			int two = 0, five = 0;
			while (x % 2 == 0) two++, x /= 2;
			while (x % 5 == 0) five++, x /= 5;
			f2[i][j] = f2[i][j - 1] + two;
			g2[i][j] = g2[i - 1][j] + two;
			f5[i][j] = f5[i][j - 1] + five;
			g5[i][j] = g5[i - 1][j] + five;
		}
		print(f2);
		print(g2);
		print(f5);
		print(g5);
		int ans = 0;
		for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
			// 从左边出发，到上边结束
			ans = max(ans, min(f2[i][j] + g2[i - 1][j], f5[i][j] + g5[i - 1][j]));
			// 从左边出发，到下边结束
			ans = max(ans, min(f2[i][j] + g2[n][j] - g2[i][j], f5[i][j] + g5[n][j] - g5[i][j]));
			// 从右边出发，到上边结束
			ans = max(ans, min(f2[i][m] - f2[i][j] + g2[i][j], f5[i][m] - f5[i][j] + g5[i][j]));
			// 从右边出发，到下边结束
			ans = max(ans, min(f2[i][m] - f2[i][j] + g2[n][j] - g2[i - 1][j], f5[i][m] - f5[i][j] + g5[n][j] - g5[i - 1][j]));
		}
		return ans;
	}
};
