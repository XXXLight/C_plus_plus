#include<bits/stdc++.h>
using namespace std;


class UF {
public:
	vector<int> parent;
	UF(int n) {
		parent.resize(n);
		for (int i = 0; i < n; i++) parent[i] = i;
	}
	int find(int x) {
		while (x != parent[x]) {
			parent[x] = parent[parent[x]];
			x = parent[x];
		}
		return x;
	}
	void unionAB(int a, int b) {
		int fa = find(a);
		int fb = find(b);
		if (fa != fb) parent[fa] = fb;
	}
	bool check(int a, int b) {
		int fa = find(a);
		int fb = find(b);
		return fa == fb;
	}
};

// 注意，映射时是i*col + j，而不是i*row + j,目的是将二维数据拉成一维数据
class Solution {
public:
	vector<int> pondSizes(vector<vector<int>>& land) {
		vector<int> res;
		int row = land.size();
		int col = land[0].size();
		UF* uf = new UF(row*col);
		unordered_map<int, bool> mp2;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (land[i][j] == 0) {
					mp2[i*col + j] = true;// 注意，映射时是i*col + j，而不是i*row + j
					if (i + 1 < row&&land[i + 1][j] == 0) uf->unionAB(i*col + j, (i + 1)*col + j);
					if (i - 1 >= 0 && land[i - 1][j] == 0)  uf->unionAB(i*col + j, (i - 1)*col + j);
					if (j + 1 < col&&land[i][j + 1] == 0) uf->unionAB(i*col + j, (i)*col + j + 1);
					if (j - 1 >= 0 && land[i][j - 1] == 0)  uf->unionAB(i*col + j, (i)*col + j - 1);
					if (i + 1 < row&&j + 1 < col&&land[i + 1][j + 1] == 0) uf->unionAB(i*col + j, (i + 1)*col + j + 1);
					if (i + 1 < row&&j - 1 >= 0 && land[i + 1][j - 1] == 0) uf->unionAB(i*col + j, (i + 1)*col + j - 1);
					if (i - 1 >= 0 && j + 1 < col&&land[i - 1][j + 1] == 0) uf->unionAB(i*col + j, (i - 1)*col + j + 1);
					if (i - 1 >= 0 && j - 1 >= 0 && land[i - 1][j - 1] == 0) uf->unionAB(i*col + j, (i - 1)*col + j - 1);
				}
			}
		}
		unordered_map<int, vector<int>> mp;
		for (int i = 0; i < row*col; i++) {
			if (mp2[i])
				mp[uf->find(i)].push_back(i);
		}
		for (auto&[u, v] : mp) {
			res.push_back(v.size());
		}
		sort(res.begin(), res.end());
		return res;
	}
};