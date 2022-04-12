#include<bits/stdc++.h>
using namespace std;

// ��ɽ����������չ
// a&&b,���b��������a��������a��ǰ��
class Solution {
public:
	int longestMountain(vector<int>& arr) {
		int len = arr.size();
		if (len <= 2) return 0;
		int res = 0;
		for (int i = 1; i < len - 1; i++) {
			int l = 0, r = 0;
			// ɽ���������ߣ��������Ϊ��ɽ�Ĺ���
			if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {//�ȶ�λ��ɽ��
				l = i - 1;
				r = i + 1;
				// ��ɽ
				while (l >= 1 && arr[l] > arr[l - 1]) l--; // ��������������ǰ�棬���Ƽ��ջ��empty()
				while (r <= len - 2 && arr[r] > arr[r + 1]) r++; // ��������������ǰ�棬���Ƽ��ջ��empty()
			}
			// ָ���ߵ�ɽ���ˣ����´�λ��
			res = max(res, r - l + 1);
		}
		if (res == 1) return 0;
		return res;
	}
};



class Solution {
public:
	int longestMountain(vector<int>& arr) {
		int len = arr.size();
		int res = 0;
		for (int i = 1; i < len - 1; i++) {
			// �ҵ�ɽ�� 
			if (arr[i] > arr[i + 1] && arr[i] > arr[i - 1]) {
				int l = i - 1, r = i + 1;
				// ����ɽ��������
				while (l >= 1 && arr[l] > arr[l - 1]) l--;
				// ����ɽ��������
				while (r<len - 1 && arr[r]>arr[r + 1]) r++;
				//ָ���Ƶ����ٸ��½��
				res = max(res, r - l + 1);
			}
		}
		return res;
	}
};



class Solution {
public:
	int longestMountain(vector<int>& A) {
		int maxLength = 0;
		int i = 1;

		while (i < A.size()) {
			int increasing = 0, decreasing = 0;

			while (i < A.size() && A[i - 1] < A[i]) i++, increasing++;
			while (i < A.size() && A[i - 1] > A[i]) i++, decreasing++;

			if (increasing > 0 && decreasing > 0)
				maxLength = max(maxLength, increasing + decreasing + 1);

			while (i < A.size() && A[i - 1] == A[i]) i++;
		}
		return maxLength;
	}
};

