#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, c;
	int w[110];
	int v[110];
	int dp[1010] = { 0 };
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> w[i] >> v[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = c; j >= w[i]; j--) {
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
		}
	}
	int ans = -1;
	for (int i = 0; i <= c; i++) {
		if (dp[i] > ans) {
			ans = dp[i];
		}
	}
	cout << ans << endl;
}