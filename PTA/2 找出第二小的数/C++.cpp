#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int a[10];
	int n, c;
	cin >> c;
	while (c--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a, a + n);
		int cnt = 1;
		for (int j = 0; j < n-1; j++) {
			if (a[j] != a[j + 1]) {
				cout << a[j + 1] << endl;
				cnt++;
				break;
			}
		}
		if (cnt != 2)	cout << "NO" << endl;
	}
}