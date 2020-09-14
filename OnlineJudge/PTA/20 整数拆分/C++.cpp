#include <iostream>
#include <algorithm>
using namespace std;
int dp[1000010];
int main() {
	int n;
	cin >> n;
	while (n-- != 0) {
		int x;
		cin >> x;
		dp[0] = 1;
		dp[1] = 1;
		for (int i = 2; i <= x; i++) {
			if (i % 2 == 0) {
				dp[i] = (dp[i - 1] + dp[i / 2]) % 1000000000;
			}
			else dp[i] = dp[i - 1] % 1000000000;
		}
		cout << dp[x];
		if (n != 0) cout << ' ';
	}
}