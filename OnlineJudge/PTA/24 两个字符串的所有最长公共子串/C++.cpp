#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[110][110];
vector<string> getLCSs(const string& s, const string& t) {
    vector<string> res;
    int m = s.length();
    int n = t.length();
    int index = 0;
    int len = 0;
    if (m == 0 || n == 0) {
        res.push_back("NO");
        return res;
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
            if (dp[i][j] >= len) {
                index = i;
                if (dp[i][j] > len) {
                    res.clear();
                }
                len = dp[i][j];
                res.push_back(s.substr(index - len + 1, len));
            }
        }
    }
    if (len == 0) {
        res.clear();
        res.push_back("NO");
    }
    sort(res.begin(), res.end());
    return res;
}
int main() {
    string S = "";
    string T = "";
    cin >> S;
    cin >> T;
    vector<string> ans = getLCSs(S, T);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
}