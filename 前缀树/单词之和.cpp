#include<bits/stdc++.h>
using namespace std;

class MapSum {
public:
	MapSum *children[26];//前缀树的数据结构，存储每个单词的字母
	int word;
	/** Initialize your data structure here. */
	MapSum() {
		memset(children, 0, sizeof(children));
		word = 0;
	}

	void insert(string key, int val) {//把输入的单词，放入树中（每个字母开辟一片空间）
		MapSum *node = this;// this指针指向所建立的前缀树
		for (auto tmp : key) {
			if (node->children[tmp - 'a'] == NULL) {
				node->children[tmp - 'a'] = new MapSum();
			}
			node = node->children[tmp - 'a'];
		}
		node->word = val;//单词存完后，把随带的数字存到末尾
	}

	int sum(string prefix) {
		int sum = 0;
		MapSum *node = this;// 取出建好的前缀树
		for (auto tmp : prefix) {
			if (node->children[tmp - 'a'] == NULL)
				return 0;
			node = node->children[tmp - 'a'];
		}
		//先把当前的prefix遍历完，走完所有前缀。然后从最后一个字母出发，把所有同前缀的数字加上
		//用递归的方式，深度遍历树
		return getSum(node);
	}

	int getSum(MapSum *node) {
		if (node == NULL)return 0;
		int res = node->word;//先把到当前字母的值存下来（如果有的话）
		for (auto tmp : node->children) {//遍历这个节点的所有子节点
			res += getSum(tmp);//把子节点的值都汇集起来
		}
		return res;
	}
};

