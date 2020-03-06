#include <iostream>
using namespace std;
int main() {
	int N1, N2, item;
	char op;
	int S1[1001], S2[1001];
	int C1, C2;
	C1 = 0;
	C2 = 0;
	cin >> N1 >> N2;
	// 最大为主存
	if (N1 > N2) {
		int temp = N1;
		N1 = N2;
		N2 = temp;
	}
	while (cin >> op) {
		if (op == 'T')	break;
		else if (op == 'A') {
			cin >> item;
			if (C1 == N1) {
				cout << "ERROR:Full" << endl;
			}
			else S1[++C1] = item;
		}
		else if (op == 'D') {
			if (C2) cout << S2[C2--] << endl;
			else if (C1) {
				while (C1) S2[++C2] = S1[C1--];
				cout << S2[C2--] << endl;
			}
			else cout << "ERROR:Empty" << endl;
		}
		if (C2 == 0 && C1 == N1) {    // S1满后转移至S2
			while (C1) S2[++C2] = S1[C1--];
		}
	}
}