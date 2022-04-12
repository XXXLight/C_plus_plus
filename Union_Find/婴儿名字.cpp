#include<bits/stdc++.h>
using namespace std;


class Solution {
	unordered_map<string, string> parents;

	const string & findRoot(const string & name) {
		if (parents.count(name) == 0)
			return parents[name] = name;

		if (parents[name] != name)
			parents[name] = findRoot(parents[name]);

		return parents[name];
	}

	void join(const string & name1, const string & name2) {
		const string &r1 = findRoot(name1);
		const string &r2 = findRoot(name2);
		if (r1 < r2)
			parents[r2] = r1;
		else
			parents[r1] = r2;
	}

public:
	vector<string> trulyMostPopular(vector<string>& names, vector<string>& synonyms) {
		for (auto & name_pair : synonyms) {
			auto comma_pos = name_pair.find(',');
			join(name_pair.substr(1, comma_pos - 1),
				name_pair.substr(comma_pos + 1, name_pair.size() - comma_pos - 2));
		}

		unordered_map<string, int> name_cnt;
		for (auto & record : names) {
			auto l_pos = record.find('(');
			string name = record.substr(0, l_pos);
			int cnt = stoi(record.substr(l_pos + 1, record.size() - l_pos - 2));
			name_cnt[findRoot(name)] += cnt;
		}

		vector<string> res;
		for (auto &[name, cnt] : name_cnt)
			res.emplace_back(name + "(" + to_string(cnt) + ")");
		return res;
	}
};

