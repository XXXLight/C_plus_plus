#include<bits/stdc++.h>
using namespace std;

int main() {

	vector<int>  v= { 1,2,2,2,3,3,3,8,9,10 };
	int i = upper_bound(v.begin(), v.end(), 3) - v.begin();
	cout << i << endl;
	return 0;
}