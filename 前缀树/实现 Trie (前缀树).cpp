#include<bits/stdc++.h>
using namespace std;



// 关于前缀树的几点：
//	1.前缀树的思想是用空间（树结构）换时间（查找）
//  2.几个接口写起来大同小异，可以稍微改动即可
//  3.复杂度分析：时间复杂度:(o(Len))  空间复杂度:(o(nk)),其中Len是插入或查找的字符串长度，n是节点数量，k是字符集的个数26
//  4.前缀树的应用：浏览器搜索


//前缀树是N叉树的一种
class Trie
{
public:
	bool is_string = false;//该节点是否能表示一个完整的字符串,尾部标志
	Trie* next[26] = { nullptr };//每个节点有26个链接（26个孩子节点）
public:
	Trie() {}

// insert/search/startsWith这几个接口写法差别不大，可以直接copy一份到另一份进行修改
	void insert(const string& word)//插入单词
	{
		Trie* root = this;	//当前树的地址
		for (const auto& w : word) {
			if (root->next[w - 'a'] == nullptr)root->next[w - 'a'] = new Trie();//root的next为空，为其申请一个空间
			root = root->next[w - 'a'];//root的next节点不为空，就不用插入字符，root更新为next节点
		}
		root->is_string = true;//尾部标志
	}

	bool search(const string& word)//查找单词
	{
		Trie* root = this;
		for (const auto& w : word) {
			if (root->next[w - 'a'] == nullptr)return false;//w字符不在前缀树中，返回false
			root = root->next[w - 'a'];
		}
		return root->is_string;//该单词在前缀树中是否为一个完整的字符串，尾部标志
	}

	bool startsWith(string prefix)//查找前缀
	{
		Trie* root = this;
		for (const auto& p : prefix) {
			if (root->next[p - 'a'] == nullptr)return false;//w字符不在前缀树中，返回false
			root = root->next[p - 'a'];
		}
		return true;//前缀的所有字符都在前缀中，返回true
	}
};


//前缀树的遍历
vector<vector<char>> res;
vector<char> tmp;
void DFS(Trie *trie) {
	if (trie == nullptr) return;
	if (trie->is_string == true) {
		res.push_back(tmp);
		tmp.clear();//清空tmp
		return;
	}
	for (int i = 0; i < 26; i++) {
		if (trie->next[i] != nullptr) {
			tmp.push_back(i + 'a');
			DFS(trie->next[i]);
		}
	}
}