#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[110][110];
int getLen(const string& s, const string& t) {
    int m = s.length();
    int n = t.length();
    int len = 0;
    if (m == 0 || n == 0) {
        return 0;
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i] == t[j]) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                }
                else {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
            }
            if (dp[i][j] > len) {
                len = dp[i][j]; 
            }
        }
    }
    return len;
}
int main() {
    string S = "";
    string T = "";
    cin >> S;
    cin >> T;
    cout << getLen(S, T) << endl;
}