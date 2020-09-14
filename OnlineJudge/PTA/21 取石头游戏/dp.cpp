#include <iostream>
#include <algorithm>
using namespace std;
int dp[10000010];
int main() {
	int n;
	cin >> n;
	if (n <= 8) {
		cout << 1 << endl;
	}
	else {
		int mod[4] = { 1,3,7,8 };
		for (int i = 1; i <= 8; i++) dp[i] = 1;
		for (int i = 9; i <= n; i++) {
			dp[i] = 0;
			for (int j = 0; j < 4; j++) {
				if (dp[i - mod[j]] == 0) {
					dp[i] = 1;
					break;
				}
			}
		}
		cout << dp[n] << endl;
	}
}