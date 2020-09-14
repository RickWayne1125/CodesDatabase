#include <iostream>
using namespace std;
int n;
char con[22][22];
int ans[22], used[22];
bool dfs(int x, int u) {
    ans[x] = u;
    if (x == n) {
        if (con[u][1] == 'W' || con[1][u] == 'L')
            return 1;
        else
            return 0;
    }
    int flag = 0;
    for (int i = 1; i <= n; i++) {
        if (!used[i] && (con[i][1] == 'W' || con[1][i] == 'L')) {
            flag = 1;
            break;
        }
    }
    if (!flag) return 0;
    used[u] = 1;
    for (int i = 1; i <= n; i++) {
        if (!used[i] && (con[u][i] == 'W' || con[i][u] == 'L')) {
            if (dfs(x + 1, i))
                return 1;
        }
    }
    used[u] = 0;
    return 0;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> con[i][j];
        }
    }
    if (dfs(1, 1)) {
        for (int i = 1; i <= n; i++) {
            if (i != 1)
                cout << ' ';
            cout << ans[i];
        }
    }
    else cout << "No Solution" << endl;
    return 0;
}