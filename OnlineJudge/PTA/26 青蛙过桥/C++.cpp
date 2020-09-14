#include<iostream>
#include<algorithm>
using namespace std;
int dp[150010][2];
int a[150010];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i <= n; i++) {
		cin >> a[i];
	}
	dp[n - 1][0] = a[n - 1];
	dp[n - 1][1] = -1;
	dp[n - 2][0] = a[n - 2];
	dp[n - 2][1] = -1;
	dp[n][0] = a[n];
	dp[n][1] = -1;
	for (int i = n - 3; i >= 0; i--) {
		dp[i][0] = min(min(dp[i + 1][0], dp[i + 2][0]), dp[i + 3][0]);
		if (dp[i][0] == dp[i + 1][0]) {
			dp[i][1] = i + 1;
		}
		else if (dp[i][0] == dp[i + 2][0]) {
			dp[i][1] = i + 2;
		}
		else if (dp[i][0] == dp[i + 3][0]) {
			dp[i][1] = i + 3;
		}
		dp[i][0] += a[i];
	}
	cout << dp[0][0] << endl;
	int flag = 0;
	cout << 0;
	while (flag <= n && flag >= 0) {
		if (dp[flag][1] >= 0) {
		cout << ' ' << dp[flag][1];
		}
		flag = dp[flag][1];
	}
}