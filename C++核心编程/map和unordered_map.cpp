//#include<bits/stdc++.h>
//#include<unordered_set>
//using namespace std;
//
//int main() {
//	// map三种	set三种
//	map<int, int> mp1;   //  ordered red-black tree of {key, mapped} values, unique keys
//	unordered_map<int, int> mp2; //  hash table of {key, mapped} values, unique keys
//	set<int> st;	// ordered red-black tree of key values, unique keys
//	unordered_set<int> st2;	// hash table of key values, unique keys
//	multimap<int, int> mp3;	// ordered red-black tree of {key, mapped} values, non-unique keys
//	multiset<int> mst;	// ordered red-black tree of key values, non-unique keys
//	priority_queue<int> p;	// priority queue implemented with a _Container
//	deque<int> dq;
//
//	mp1[1] = 1;
//	mp1[2] = 2;
//	mp1[0] = 1;
//	mp1[0] = 2;
//	mp2[1] = 3;
//	mp2[2] = 2;
//	mp2[0] = 3;
//	mp2[0] = 2;
//	mp3.insert(pair<int, int>(0, 1));  // 没有重载[]的结果
//	mp3.insert(pair<int, int>(0, 2));
//	mp3.insert(pair<int, int>(1, 1));
//	mp3.insert(pair<int, int>(2, 2));
//	
//	return 0;
//}