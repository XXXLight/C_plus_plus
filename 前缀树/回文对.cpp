#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Solution {
public:
	vector<vector<int>> palindromePairs(vector<string>& words) {
		if (words.empty())return {};
		vector<vector<int>> result;
		unordered_map<string, int> m;//单词->下标
		set<int> s;//单词的长度排序

		//第一次遍历：建立map表和set表
		for (int i = 0; i < words.size(); ++i)
		{
			m[words[i]] = i;
			s.insert(words[i].size());
		}

		//第二次遍历：寻找回文对
		for (int i = 0; i < words.size(); ++i)
		{
			string word = words[i];
			int size = word.size();
			reverse(word.begin(), word.end());//反转单词
			//第一种情况：回文对就是两个长度相等的单词互为反转字符串,比如abcd与dcba,但是要排除bb这种反转后依旧是自己的字符串
			if (m.count(word) != 0 && m[word] != i) { result.push_back({ i,m[word] }); }
			//第二种情况：回文对是两个长度不一的单词，比如lls,反转后为sll,我们在set中找到长度为1的单词，减去长度1的后ll是否为回文对
			auto a = s.find(size);
			for (auto it = s.begin(); it != a; ++it)
			{
				int d = *it;//set中长度为d的单词
				//处理str=回文对+字母，比如ddcba,我们找到长度为3的单词，就判断dd是否回文，然后判断减去dd后的cba是否在map中
				if (isValid(word, 0, size - d - 1) && m.count(word.substr(size - d)))
					result.push_back({ i,m[word.substr(size - d)] });
				//处理str=字母+回文对，比如bcdaa,我们找到长度为3的单词，就判断aa是否回文，然后就判断减去aa后的bcd是否在map中
				if (isValid(word, d, size - 1) && m.count(word.substr(0, d)))
					result.push_back({ m[word.substr(0,d)],i });
			}
		}
		return result;
	}

	bool isValid(string word, int left, int right)//判断word是否为回文对
	{
		while (left < right)
		{
			if (word[left++] != word[right--])
				return false;
		}
		return true;
	}
};

