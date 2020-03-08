class Solution {
public:
	int stack[2];
	string generateTheString(int n) {
		string ans = "";
		int temp = n;
		int flag = 0;
		if (n % 2 == 0) {
			stack[0] = n - 1;
			stack[1] = 1;
		}
		else {
			flag = 1;
		}
		if (flag) {
			for (int i = 0; i < n; i++) {
				ans = ans + "a";
			}
		}
		else {
			for (int i = 0; i < n - 1; i++) {
				ans = ans + "a";
			}
			ans += "b";
		}
		return ans;
	}
};