#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

// 想到拓扑排序这种解决办法
class Solution {
public:
	vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
		int n = recipes.size();
		// 图，必须采用这种哈希表的处理方式，因为二维vector的index不能是字符串
		unordered_map<string, vector<string>> depend;
		// 入度统计
		unordered_map<string, int> cnt;
		for (int i = 0; i < n; ++i) {
			for (const string& ing : ingredients[i]) {
				depend[ing].push_back(recipes[i]);
			}
			cnt[recipes[i]] = ingredients[i].size();
		}

		vector<string> ans;
		queue<string> q;
		// 把初始的原材料放入队列，初始材料的入度都是0
		for (const string& sup : supplies) {
			q.push(sup);
		}
		// 拓扑排序
		while (!q.empty()) {
			string cur = q.front();
			q.pop();
			if (depend.count(cur)) {
				for (const string& rec : depend[cur]) {
					--cnt[rec];
					// 如果入度变为 0，说明可以做出这道菜
					if (cnt[rec] == 0) {
						ans.push_back(rec);
						q.push(rec);
					}
				}
			}
		}
		return ans;
	}
};

