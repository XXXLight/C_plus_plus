#include<bits/stdc++.h>
using namespace std;

class MapSum {
public:
	MapSum *children[26];//ǰ׺�������ݽṹ���洢ÿ�����ʵ���ĸ
	int word;
	/** Initialize your data structure here. */
	MapSum() {
		memset(children, 0, sizeof(children));
		word = 0;
	}

	void insert(string key, int val) {//������ĵ��ʣ��������У�ÿ����ĸ����һƬ�ռ䣩
		MapSum *node = this;// thisָ��ָ����������ǰ׺��
		for (auto tmp : key) {
			if (node->children[tmp - 'a'] == NULL) {
				node->children[tmp - 'a'] = new MapSum();
			}
			node = node->children[tmp - 'a'];
		}
		node->word = val;//���ʴ���󣬰���������ִ浽ĩβ
	}

	int sum(string prefix) {
		int sum = 0;
		MapSum *node = this;// ȡ�����õ�ǰ׺��
		for (auto tmp : prefix) {
			if (node->children[tmp - 'a'] == NULL)
				return 0;
			node = node->children[tmp - 'a'];
		}
		//�Ȱѵ�ǰ��prefix�����꣬��������ǰ׺��Ȼ������һ����ĸ������������ͬǰ׺�����ּ���
		//�õݹ�ķ�ʽ����ȱ�����
		return getSum(node);
	}

	int getSum(MapSum *node) {
		if (node == NULL)return 0;
		int res = node->word;//�Ȱѵ���ǰ��ĸ��ֵ������������еĻ���
		for (auto tmp : node->children) {//��������ڵ�������ӽڵ�
			res += getSum(tmp);//���ӽڵ��ֵ���㼯����
		}
		return res;
	}
};

