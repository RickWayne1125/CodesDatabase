#include<iostream>
using namespace std;
int N;
int in[100011];
int flag[100011];
void swap(int x, int y) {
	int temp;
	temp = flag[x];
	flag[x] = flag[y];
	flag[y] = temp;
}
bool done() {
	for (int i = 0; i < N; i++) {
		if (flag[i] != i) {
			return false;
		}
	}
	return true;
}
int main() {
	int cnt = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> in[i];
		flag[in[i]] = i;
	}
	while (done() != true) {
		int i;
		for (i = 0; i < N; i++) {
			if (flag[i] != i) {
				while (flag[0] != 0) {
					swap(0, flag[0]);
					cnt++;
				}
				if (flag[i] != i) {
					swap(i, 0);
					cnt++;
				}
			}
		}
		if (done())	break;
		i = 0;
	}
	cout << cnt << endl;
}