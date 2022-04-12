#include<bits/stdc++.h>
using namespace std;

class MagicDictionary {
public:
	vector<string> help;
	bool minDistance(string word1, string word2) {
		int cnt = 0;
		if (word1.size() != word2.size()) return false;
		for (int i = 0; i < word1.size(); i++) {
			if (word1[i] != word2[i]) cnt++;
		}
		if (cnt == 1) return true;
		else return false;
	}
	MagicDictionary() {

	}

	void buildDict(vector<string> dictionary) {
		help = dictionary;
	}

	bool search(string searchWord) {
		for (auto& e : help) {
			if (minDistance(e, searchWord)) return true;
		}
		return false;
	}
};




// 构造前缀树节点
class Trie {
public:
	bool isWord;
	vector<Trie*> children;
	Trie() : isWord(false), children(26, nullptr) {}

	void insert(const string& str) {
		Trie* node = this;
		for (auto& ch : str) {
			if (node->children[ch - 'a'] == nullptr) {
				node->children[ch - 'a'] = new Trie();
			}
			node = node->children[ch - 'a'];
		}
		node->isWord = true;
	}
};
class MagicDictionary {
private:
	Trie* root;
	bool dfs(Trie* root, string& word, int i, int edit) {
		if (root == nullptr) {
			return false;
		}

		if (root->isWord && i == word.size() && edit == 1) {
			return true;
		}

		if (i < word.size() && edit <= 1) {
			bool found = false;
			for (int j = 0; j < 26 && !found; ++j) {
				int next = (j == word[i] - 'a') ? edit : edit + 1;
				found = dfs(root->children[j], word, i + 1, next);
			}

			return found;
		}

		return false;
	}

public:
	/** Initialize your data structure here. */
	MagicDictionary() {
		root = new Trie();
	}

	void buildDict(vector<string> dictionary) {
		for (auto& word : dictionary) {
			root->insert(word);
		}
	}

	bool search(string searchWord) {
		return dfs(root, searchWord, 0, 0);
	}
};

