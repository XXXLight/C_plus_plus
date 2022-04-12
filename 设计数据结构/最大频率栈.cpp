#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class FreqStack {
public:
	FreqStack() : max_freq(0) {
	}

	void push(int x) {
		// ��ǰֵx�ĳ���Ƶ��+1
		++freq_map[x];
		// �������Ƶ��
		max_freq = max(max_freq, freq_map[x]);
		// x��Ƶ��������1��Ҳ����˵Ƶ��Ϊfreq_map[x]��ֵ�ֶ���һ��x
		groups[freq_map[x]].push(x);
	}

	int pop() {
		// �ҵ�����Ƶ������һϵ��ֵ��pop��������push��һ����Ҳ����ջ��
		int x = groups[max_freq].top();
		groups[max_freq].pop();
		// x��Ӧ��Ƶ��Ҫ-1
		freq_map[x]--;
		// Ƶ��Ϊmax_freq�����ּ�����һ�������Ƶ��Ϊmax_freq�����ֶ��Ѿ���������ʣ��ֵ�����Ƶ��Ϊ max_freq - 1
		if (groups[max_freq].size() == 0)
			--max_freq;
		return x;
	}
private:
	// ÿ��Ԫ�أ��Լ������ֵ�Ƶ��
	unordered_map<int, int> freq_map;
	// key��Ƶ�ʣ�value��Ƶ��Ϊkey������value����stack���棬������֤ͬ��Ƶ���£� �������
	unordered_map<int, stack<int>> groups;
	int max_freq = 0;
};

