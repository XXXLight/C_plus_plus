#include<bits/stdc++.h>
using namespace std;

//只有插入和查找两个接口
class WordDictionary {
private:
	struct Trie {//建立前缀树
		Trie *children[26]{ nullptr };//26个孩子节点
		bool is_string = false;//尾部标志
	};
	Trie *root;
public:
	/** Initialize your data structure here. */
	WordDictionary() {
		root = new Trie();
	}

	/** Adds a word into the data structure. */
	void addWord(string word) {
		Trie *note = root;
		for (const auto &w : word)
		{
			if (note->children[w - 'a'] == nullptr)
				note->children[w - 'a'] = new Trie();
			note = note->children[w - 'a'];
		}
		note->is_string = true;
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {
		return dfs(root, word, 0);
	}

	bool dfs(Trie* root, string word, int i)
	{
		if (root == nullptr)return false;
		if (i == word.size())return root->is_string;//递归边界，深度与单词长度相同
		if (word[i] != '.')//该字符不为点.
		{
			if (root->children[word[i] - 'a'] != nullptr)
				return dfs(root->children[word[i] - 'a'], word, i + 1);//该字符在前缀树中，继续深度优先搜索
			else return false;//该字符不再前缀树中，直接返回false
		}
		for (int j = 0; j < 26; ++j)//遍历出root的后所有字符串路径，只要有一条字符串路径满足就返回true
		{
			if (root->children[j] && dfs(root->children[j], word, i + 1))
				return true;
		}
		return false;
	}
};



