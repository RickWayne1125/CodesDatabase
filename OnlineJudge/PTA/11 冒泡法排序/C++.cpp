#include <iostream>
using namespace std;

void bubble_sort(int a[], int len, int k)
{
	int i, j;  int temp;
	int cnt = 0;
	for (i = 0; i < len - 1; i++) {
		for (j = 0; j < len - 1 - i; j++) {
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}

		}
		cnt++;
		if (cnt == k) {
			//cout << "done" << endl;
			break;
		}
	}
}
int main() {
	int N, K;
	int a[101];
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	bubble_sort(a, N, K);
	for (int i = 0; i < N - 1; i++) {
		cout << a[i] << ' ';
	}
	cout << a[N - 1];
	return 0;
}