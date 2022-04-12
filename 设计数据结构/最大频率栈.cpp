#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class FreqStack {
public:
	FreqStack() : max_freq(0) {
	}

	void push(int x) {
		// 当前值x的出现频率+1
		++freq_map[x];
		// 更新最大频率
		max_freq = max(max_freq, freq_map[x]);
		// x的频率增加了1，也就是说频率为freq_map[x]的值又多了一个x
		groups[freq_map[x]].push(x);
	}

	int pop() {
		// 找到出现频率最大的一系列值，pop出最最新push的一个，也就是栈顶
		int x = groups[max_freq].top();
		groups[max_freq].pop();
		// x对应的频率要-1
		freq_map[x]--;
		// 频率为max_freq的数字减少了一个，如果频率为max_freq的数字都已经被弹出，剩余值中最大频率为 max_freq - 1
		if (groups[max_freq].size() == 0)
			--max_freq;
		return x;
	}
private:
	// 每个元素，以及它出现的频率
	unordered_map<int, int> freq_map;
	// key是频率，value是频率为key的所有value，用stack保存，这样保证同等频率下， 先来后出
	unordered_map<int, stack<int>> groups;
	int max_freq = 0;
};

