#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
	int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
		sort(tiles.begin(), tiles.end());
		long long now = 0, ans = 0;
		for (int i = 0, j = 0; i < tiles.size(); i++) {
			while (j < tiles.size() && tiles[j][1] + 1 - tiles[i][0] <= carpetLen) now += tiles[j][1] - tiles[j][0] + 1, j++;
			// 毯子无法完全覆盖第 j 组瓷砖
			if (j < tiles.size()) ans = max(ans, now + max(0, tiles[i][0] + carpetLen - tiles[j][0]));
			// 毯子可以完全覆盖第 j 组瓷砖
			else ans = max(ans, now);
			now -= tiles[i][1] - tiles[i][0] + 1;
		}
		return ans;
	}
};

