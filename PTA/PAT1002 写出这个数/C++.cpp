#include <iostream>

using namespace std;

int main() {
    int n = 0;
    string in;
    cin >> in;
    for (int i = 0; i < in.size(); i++) {
        int tmp = in[i] - '0';
        n += tmp;
    }
    string pinyin[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    int res = 0;
    string ans = "";
    while (n != 0) {
        int tmp = n % 10;
        ans = pinyin[tmp] + ans;
        n = n / 10;
        if (n != 0) {
            ans = " " + ans;
        }
    }
    cout << ans << endl;
    return 0;
}

