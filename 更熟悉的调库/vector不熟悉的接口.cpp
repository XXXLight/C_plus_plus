#include<bits/stdc++.h>
using namespace std;

int main() {
	vector<int> v = { 1,2,3,4,5,6,7,8,9 };
	// iterator erase(const_iterator _Where),const_iterator表示迭代器如v.begin(),返回值也是迭代器
	v.erase(v.begin() + 3);
	for (auto e : v) cout << e << " "; // 1 2 3 5 6 7 8 9
	cout << endl;

	// iterator insert(const_iterator _Where, _Ty&& _Val)，学会看源代码
	v.insert(v.begin() + 2, 666);
	for (auto e : v) cout << e << " "; // 1 2 666 3 5 6 7 8 9
	cout << endl;
	return 0;
}