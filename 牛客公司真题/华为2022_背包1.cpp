#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> result;
vector<int> path;
int cnt = 0;
void backtrack(vector<int>&v, int target, int sum, int startIndex, vector<bool>& used) {
	if (sum == target) {
		result.push_back(path);
		return;
	}
	for (int i = startIndex; i < v.size() && sum + v[i] <= target; i++) {
		sum += v[i];
		path.push_back(v[i]);
		used[i] = true;
		backtrack(v, target, sum, i + 1, used);
		used[i] = false;
		sum -= v[i];
		path.pop_back();
	}
}
vector<vector<int>> help(vector<int>&v, int target) {
	vector<bool> used(v.size(), false);
	path.clear();
	result.clear();
	sort(v.begin(), v.end());
	backtrack(v, target, 0, 0, used);
	return result;
}
int main() {
	int X, M;
	cin >> X >> M;
	vector<int> prices(M);
	sort(prices.begin(), prices.end());
	for (int i = 0; i < M; i++) cin >> prices[i];
	vector<vector<int>> res = help(prices, X);
	if (res.size() == 0) cout << -1;
	else cout << res.size();
	return 0;
}