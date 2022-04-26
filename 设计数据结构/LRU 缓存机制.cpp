#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;


// LRU��Ӧ�ã���׿�ֻ��ĺ�̨����


// ˫����Ľڵ� 
struct DLinkedNode {
	int key, value;
	DLinkedNode* prev;
	DLinkedNode* next;
	DLinkedNode() : key(0), value(0), prev(nullptr), next(nullptr) {}
	DLinkedNode(int _key, int _value) : key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
	unordered_map<int, DLinkedNode*> cache;
	DLinkedNode* head;// αͷ���ڵ�
	DLinkedNode* tail;// αβ���ڵ㣬���Խڵ���������ڵ��м�
	int size;// �����е�Ԫ������
	int capacity;// LRU������
public:
	LRUCache(int _capacity) : capacity(_capacity), size(0) {
		// ʹ��αͷ����αβ���ڵ㣬��϶������������
		head = new DLinkedNode();
		tail = new DLinkedNode();
		head->next = tail;
		tail->prev = head;
	}
	int get(int key) {
		if (!cache.count(key)) {
			return -1;
		}
		// ��� key ���ڣ���ͨ����ϣ��λ�����Ƶ�ͷ��
		DLinkedNode* node = cache[key];
		moveToHead(node);
		return node->value;
	}
	void put(int key, int value) {
		if (!cache.count(key)) {
			// ��� key �����ڣ�����һ���µĽڵ�
			DLinkedNode* node = new DLinkedNode(key, value);
			// ��ӽ���ϣ��
			cache[key] = node;
			// �����˫�������ͷ��
			addToHead(node);
			++size;
			if (size > capacity) {
				// �������������ɾ��˫�������β���ڵ�
				DLinkedNode* removed = removeTail();
				// ɾ����ϣ���ж�Ӧ����
				cache.erase(removed->key);
				// ��ֹ�ڴ�й©
				delete removed;
				--size;
			}
		}
		else {
			// ��� key ���ڣ���ͨ����ϣ��λ�����޸� value�����Ƶ�ͷ��
			DLinkedNode* node = cache[key];
			node->value = value;
			moveToHead(node);
		}
	}
	// ���ڵ��ƶ���˫�����ͷ������ͼ������⣬��ǰ�ýڵ��Ѿ��������ж��������ˣ���Ϊ����removeNode(node);����
	void addToHead(DLinkedNode* node) {
		node->prev = head;
		node->next = head->next;
		head->next->prev = node;
		head->next = node;
	}
	// ɾ��˫����Ľڵ㣬��ͼ�ܺ����
	void removeNode(DLinkedNode* node) {
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	// ���ڵ��Ƶ�˫�����ͷ�����Ƚ��ڵ�������ж����������ٲ���
	void moveToHead(DLinkedNode* node) {
		removeNode(node);
		addToHead(node);
	}
	// ɾ��β���ڵ㣬������β���ڵ��ָ����Ϊ����
	DLinkedNode* removeTail() {
		DLinkedNode* node = tail->prev;
		removeNode(node);
		return node;
	}
};




// ������Լ������
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
struct DLinkedNode {
	int key, value;
	DLinkedNode* prev;
	DLinkedNode* next;
	DLinkedNode() : key(0), value(0), prev(nullptr), next(nullptr) {}
	DLinkedNode(int _key, int _value) : key(_key), value(_value), prev(nullptr), next(nullptr) {}
};
// ��ӡ˫����
void printV(DLinkedNode* node) {
	while (node) {
		cout << node->key << " " << node->value << "/";
		node = node->next;
	}
	cout << endl;
}
class LRUCache {
private:
	unordered_map<int, DLinkedNode*> cache;
	DLinkedNode* head;
	DLinkedNode* tail;
	int size;
	int capacity;
public:
	LRUCache(int _capacity) : capacity(_capacity), size(0) {
		// ʹ��αͷ����αβ���ڵ�
		head = new DLinkedNode();
		tail = new DLinkedNode();
		head->next = tail;
		tail->prev = head;
	}
	int get(int key) {
		if (!cache.count(key)) {
			return -1;
		}
		// ��� key ���ڣ���ͨ����ϣ��λ�����Ƶ�ͷ��
		DLinkedNode* node = cache[key];
		moveToHead(node);
		cout << "get" << key << ":";
		printV(head);
		return node->value;
	}
	void put(int key, int value) {
		if (!cache.count(key)) {
			// ��� key �����ڣ�����һ���µĽڵ�
			DLinkedNode* node = new DLinkedNode(key, value);
			// ��ӽ���ϣ��
			cache[key] = node;
			// �����˫�������ͷ��
			addToHead(node);
			++size;
			if (size > capacity) {
				// �������������ɾ��˫�������β���ڵ�
				DLinkedNode* removed = removeTail();
				// ɾ����ϣ���ж�Ӧ����
				cache.erase(removed->key);
				// ��ֹ�ڴ�й©
				delete removed;
				--size;
			}
		}
		else {
			// ��� key ���ڣ���ͨ����ϣ��λ�����޸� value�����Ƶ�ͷ��
			DLinkedNode* node = cache[key];
			node->value = value;
			moveToHead(node);
		}
		cout << "put" << key << ":";
		printV(head);
	}
	// �ѽڵ��Ȱᵽ�ƶ����λ�ñȽϺ����
	void addToHead(DLinkedNode* node) {
		node->prev = head;
		node->next = head->next;
		head->next->prev = node;
		head->next = node;
	}
	void removeNode(DLinkedNode* node) {
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	void moveToHead(DLinkedNode* node) {
		removeNode(node);
		addToHead(node);
	}
	DLinkedNode* removeTail() {
		DLinkedNode* node = tail->prev;
		removeNode(node);
		return node;
	}
};





class LRUCache {
	int size;
	list<pair<int, int>> li;    //������˫��������
	unordered_map<int, list<pair<int, int>>::iterator> map; //valueֵ��list�ĵ�������ʽ
public:
	LRUCache(int capacity) : size(capacity) {}  //��ʼ��size��С

	int get(int key) {
		if (map.find(key) == map.end())  return -1;  //���keyֵ������,ֱ�ӷ���-1
		else
		{
			li.splice(li.begin(), li, map[key]);        //key���������key��Ӧ�Ļ��浽list��ͷ��
			return map[key]->second;
		}
	}

	void put(int key, int value) {
		if (get(key) != -1)  map[key]->second = value;//key����,����getʱ�ѽ������Ƶ�ͷ�����ٸ���map
		else
		{   //key������
			if (li.size() == size)  //�����Ƿ�����,ɾ�����δʹ�����ݣ�map��ҲҪɾ��
			{
				int delKey = li.back().first;
				li.pop_back();
				map.erase(delKey);
			}
			li.emplace_front(key, value); //���key�����ڣ���ͷ�������µĻ���   
			map[key] = li.begin();
		}
	}
};
