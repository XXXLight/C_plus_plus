#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;


// LRU的应用：安卓手机的后台程序


// 双链表的节点 
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
	DLinkedNode* head;// 伪头部节点
	DLinkedNode* tail;// 伪尾部节点，所以节点夹在两个节点中间
	int size;// 链表中的元素数量
	int capacity;// LRU的容量
public:
	LRUCache(int _capacity) : capacity(_capacity), size(0) {
		// 使用伪头部和伪尾部节点，结合动画来加以理解
		head = new DLinkedNode();
		tail = new DLinkedNode();
		head->next = tail;
		tail->prev = head;
	}
	int get(int key) {
		if (!cache.count(key)) {
			return -1;
		}
		// 如果 key 存在，先通过哈希表定位，再移到头部
		DLinkedNode* node = cache[key];
		moveToHead(node);
		return node->value;
	}
	void put(int key, int value) {
		if (!cache.count(key)) {
			// 如果 key 不存在，创建一个新的节点
			DLinkedNode* node = new DLinkedNode(key, value);
			// 添加进哈希表
			cache[key] = node;
			// 添加至双向链表的头部
			addToHead(node);
			++size;
			if (size > capacity) {
				// 如果超出容量，删除双向链表的尾部节点
				DLinkedNode* removed = removeTail();
				// 删除哈希表中对应的项
				cache.erase(removed->key);
				// 防止内存泄漏
				delete removed;
				--size;
			}
		}
		else {
			// 如果 key 存在，先通过哈希表定位，再修改 value，并移到头部
			DLinkedNode* node = cache[key];
			node->value = value;
			moveToHead(node);
		}
	}
	// 将节点移动到双链表的头部，画图加深理解，此前该节点已经从链表中独立出来了，因为做了removeNode(node);操作
	void addToHead(DLinkedNode* node) {
		node->prev = head;
		node->next = head->next;
		head->next->prev = node;
		head->next = node;
	}
	// 删除双链表的节点，画图很好理解
	void removeNode(DLinkedNode* node) {
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	// 将节点移到双链表的头部，先将节点从链表中独立出来，再操作
	void moveToHead(DLinkedNode* node) {
		removeNode(node);
		addToHead(node);
	}
	// 删除尾部节点，并保留尾部节点的指针作为备份
	DLinkedNode* removeTail() {
		DLinkedNode* node = tail->prev;
		removeNode(node);
		return node;
	}
};




// 输出调试加深理解
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
// 打印双链表
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
		// 使用伪头部和伪尾部节点
		head = new DLinkedNode();
		tail = new DLinkedNode();
		head->next = tail;
		tail->prev = head;
	}
	int get(int key) {
		if (!cache.count(key)) {
			return -1;
		}
		// 如果 key 存在，先通过哈希表定位，再移到头部
		DLinkedNode* node = cache[key];
		moveToHead(node);
		cout << "get" << key << ":";
		printV(head);
		return node->value;
	}
	void put(int key, int value) {
		if (!cache.count(key)) {
			// 如果 key 不存在，创建一个新的节点
			DLinkedNode* node = new DLinkedNode(key, value);
			// 添加进哈希表
			cache[key] = node;
			// 添加至双向链表的头部
			addToHead(node);
			++size;
			if (size > capacity) {
				// 如果超出容量，删除双向链表的尾部节点
				DLinkedNode* removed = removeTail();
				// 删除哈希表中对应的项
				cache.erase(removed->key);
				// 防止内存泄漏
				delete removed;
				--size;
			}
		}
		else {
			// 如果 key 存在，先通过哈希表定位，再修改 value，并移到头部
			DLinkedNode* node = cache[key];
			node->value = value;
			moveToHead(node);
		}
		cout << "put" << key << ":";
		printV(head);
	}
	// 把节点先搬到移动后的位置比较好理解
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
	list<pair<int, int>> li;    //数据用双向链表保存
	unordered_map<int, list<pair<int, int>>::iterator> map; //value值是list的迭代器形式
public:
	LRUCache(int capacity) : size(capacity) {}  //初始化size大小

	int get(int key) {
		if (map.find(key) == map.end())  return -1;  //如果key值不存在,直接返回-1
		else
		{
			li.splice(li.begin(), li, map[key]);        //key存在需更新key对应的缓存到list的头部
			return map[key]->second;
		}
	}

	void put(int key, int value) {
		if (get(key) != -1)  map[key]->second = value;//key存在,调用get时已将缓存移到头部，再更新map
		else
		{   //key不存在
			if (li.size() == size)  //缓存是否满了,删除最久未使用数据，map中也要删除
			{
				int delKey = li.back().first;
				li.pop_back();
				map.erase(delKey);
			}
			li.emplace_front(key, value); //如果key不存在，在头部加入新的缓存   
			map[key] = li.begin();
		}
	}
};
