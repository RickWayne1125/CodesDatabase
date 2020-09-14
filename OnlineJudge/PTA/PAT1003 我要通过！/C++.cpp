#include <iostream>

using namespace std;

bool judge(string str) {
    bool ans = true;
    int l = 0;
    int flagl = 0;
    int r = 0;
    int flagr = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] != 'A' && str[i] != 'P' && str[i] != 'T') {
            return false;
        }
        if (str[i] == 'A') continue;
        else if (str[i] == 'P') {
            if (flagl == 0) {
                l = i;
                flagl = 1;
            } else return false;
        } else if (str[i] == 'T') {
            if (flagr == 0) {
                r = i;
                flagr = 1;
            } else return false;
        } else return false;
    }
    if (l < r) {
        int cntl = l;
        int cntm = r - l - 1;
        int cntr = str.size() - r - 1;
        if (cntl * cntm == cntr && cntm != 0) return true;
        else return false;
    } else return false;
}

int main() {
    int N;
    cin >> N;
    while (N--) {
        string str;
        cin >> str;
        if (judge(str)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}

