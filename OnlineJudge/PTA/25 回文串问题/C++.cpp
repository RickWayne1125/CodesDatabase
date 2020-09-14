#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[1200][1200];
int getLen(const string& s, const string& t) {
    int m = s.length();
    int n = t.length();
    if (m == 0 || n == 0) {
        return 0;
    }
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i-1] == t[j-1]) {
                dp[i][j] = max(dp[i][j], 1 + dp[i - 1][j - 1]);
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}
int main() {
    string S = "";
    string T = "";
    string input;
    cin >> input;
    S = input;
    reverse(input.begin(), input.end());
    T = input;
    cout << S.length()-getLen(S, T) << endl;
}