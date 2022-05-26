#include<bits/stdc++.h>
using namespace std;



class MagicDictionary {
private:
	// 构造前缀树节点
	class Trie {
	public:
		// 一共27个分支（26字母+1flag）
		bool isWord;// 结尾标识符
		vector<Trie*> children;// 本质就是多叉树
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
	Trie* root;
	bool dfs(Trie* root, string& word, int i, int edit) {
		// 空树肯定没有替换一次word的字符串
		if (root == nullptr) {
			return false;
		}
		// 递归边界，到达字符串结尾，前缀树的flag为true且word到达末尾且修改次数是1
		if (root->isWord && i == word.size() && edit == 1) {
			return true;
		}
		// 向26个分支进行DFS
		if (i < word.size() && edit <= 1) {
			bool found = false;
			for (int j = 0; j < 26 && !found; ++j) {
				int next = (j == word[i] - 'a') ? edit : edit + 1;
				if (dfs(root->children[j], word, i + 1, next)) found = true;
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
	// 利用词库来更新字典树
	void buildDict(vector<string> dictionary) {
		for (auto& word : dictionary) {
			root->insert(word);
		}
	}

	bool search(string searchWord) {
		return dfs(root, searchWord, 0, 0);
	}
};







// 直接暴力逐个比较
class MagicDictionary {
public:
	vector<string> dic;
	/** Initialize your data structure here. */
	MagicDictionary() {

	}
	bool canchange(string d, string s) {
		if (d.length() != s.length()) return false;
		int num = 0;
		for (int i = 0; i < d.length(); i++) {
			if (s[i] != d[i]) {
				num++;
				if (num > 1) return false;
			}
		}
		return num == 1;
	}

	void buildDict(vector<string> dictionary) {
		this->dic = dictionary;
	}

	bool search(string searchWord) {
		for (int i = 0; i < dic.size(); i++) {
			if (canchange(dic[i], searchWord)) return true;
		}
		return false;

	}
};

