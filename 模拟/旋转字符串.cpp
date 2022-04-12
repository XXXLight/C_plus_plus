#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool rotateString(string A, string B) {
		if (A.size() != B.size()) return false;
		int len = A.size();
		if (len == 0) return true;
		for (int i = 0; i < len; i++) {
			bool flag = true;
			int k = i;
			for (int j = 0; j < len; j++) {
				int index = (j + k) % len;
				if (B[index] != A[j])
					flag = false;
			}
			if (flag == true) return true;
		}
		return false;
	}
};


// Á½±¶³¤¶È
class Solution {
public:
	bool rotateString(string A, string B) {
		if (A.size() != B.size()) {
			return false;
		}
		string C = A;
		C += A;
		return C.find(B) != string::npos;
	}
};

