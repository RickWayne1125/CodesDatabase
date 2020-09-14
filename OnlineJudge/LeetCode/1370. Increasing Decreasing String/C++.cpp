#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int num(int b[], int len) {
		int ans = 0;
		for (int i = 0; i < len; i++) {
			ans += b[i];
		}
		return ans;
	}
	string sortString(string s) {
		string res;
		int len = s.length();
		char a[501];
		int alen = 1;
		int b[501];
		int cnt = 1;
		a[0] = s[0];
		b[0] = 1;
		int flag = 0;
		for (int i = 1; i < s.length(); i++) {
			flag = 0;
			for (int j = 0; j < alen; j++) {
				if (a[j] == s[i]) {
					flag = 1;
					b[j]++;
					break;
				}
			}
			if (!flag) {
				a[cnt] = s[i];
				alen++;
				b[cnt] = 1;
				cnt++;
			}
		}
		while (num(b,alen)) {
			// sheng
			string temp = "";
			for (int i = 0; i < alen; i++) {
				if (b[i] > 0) {
					temp = temp + a[i];
					b[i]--;
				}
			}
			sort(temp.begin(), temp.end());
			res = res + temp;
			// jiang
			temp = "";
			string temp2 = "";
			for (int i = 0; i < alen; i++) {
				if (b[i] > 0) {
					temp = temp + a[i];
					b[i]--;
				}
			}
			sort(temp.begin(), temp.end());
			for (int i = temp.length() - 1; i >= 0; i--) {
				temp2 = temp2 + temp[i];
			}
			res = res + temp2;
		}

		return res;
	}
};