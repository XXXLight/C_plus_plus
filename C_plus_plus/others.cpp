//for语句的一般形式：for（表达式1；表达式2；表达式3）语句
//可改写为while循环形式：
//表达式1；
//while表达式2；
//{
//语句
//表达式3
//}

#include<bits/stdc++.h>
using namespace std;

int main() {
	for (int i = 0; i < 10; i++) {
		cout << i << " ";
	}
	cout << endl;
	int i = 0;
	while (i < 10) {
		cout << i << " ";
		i++;
	}
	cout << endl;
	for (;;) {
		cout << "9999" << endl;
	}
	return 0;
}




