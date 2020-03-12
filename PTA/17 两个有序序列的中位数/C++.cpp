#include<iostream>
using namespace std;
int x[100010];
int y[100010];
int a[200010];
int main() {
	int N = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> y[i];
	}
	int i = 0;
	int j = 0;
	for (int k = 0; k < 2 * N; k++) {
		if (x[i] <= y[j]) {
			a[k] = x[i];
			i++;
		}
		else {
			a[k] = y[j];
			j++;
		}
	}
	cout << a[(2 * N - 1) / 2];
}