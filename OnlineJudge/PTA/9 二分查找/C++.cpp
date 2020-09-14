#include <iostream>
using namespace std;
void insert(int A[], int n, int m, int x) {	// 将A[x]插入至A[m]位置
	int tmp = A[x];
	for (int i = x - 1; i >= m; i--) {
		A[i + 1] = A[i];
	}
	A[m] = tmp;
}
void search(int A[], int n, int x) {	// 从小到大排序
	int left = 0;
	int right = n - 1;
	int mid = 0;
	int cnt = 0;
	int flag = 0;
	while (left <= right) {
		cnt++;
		mid = (left + right) / 2;
		if (x < A[mid]) {
			right = mid - 1;
		}
		else if (x == A[mid]) {
			flag = 1;
			break;
		}
		else if (x > A[mid]) {
			left = mid + 1;
		}
	}
	if (flag) {
		cout << mid << endl << cnt << endl;
	}
	else {
		cout << -1 << endl << cnt << endl;
	}
}

int main() {
	int n;
	int A[1001];
	int x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	cin >> x;
	search(A, n, x);
}
