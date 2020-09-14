#include <iostream>
#include <algorithm>
using namespace std;
int qw[110];
int tj[110];
int main() {
	int n;
	while (cin >> n) {
		for (int i = 0; i < n; i++) {
			cin >> qw[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> tj[i];
		}
		if (n % 2 == 0) {
			sort(qw, qw + n);
			sort(tj, tj + n);
			int flag1 = 0;
			int flag2 = 0;
			for (int i = 0; i < n / 2; i++) {
				if (qw[i] < tj[i + n / 2]) {
					flag1++;
				}
			}
			for (int i = 0; i < n / 2; i++) {
				if (tj[i] < qw[i + n / 2]) {
					flag2++;
				}
			}
			if (flag1 == n / 2 && flag2 == n / 2)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
		else
			cout << "NO" << endl;
	}

}