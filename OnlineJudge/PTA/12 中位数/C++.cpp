#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
using namespace std;
int main() {
	long long n, k;
	int list[200010];
	cin >> n >> k;
	for (int i = 0; i < n; i++)	cin >> list[i];
	sort(list, list + n);
	long long mid = n / 2;
	long long flag = mid + 1;
	long long cnt = 1;
	while (k > 0) {
		if (flag < n) {
			while (list[mid] < list[flag]) {
				list[mid]++; k -= cnt;
			}
			flag++;
			cnt++;
		}
		else {
			list[mid]++; k -= cnt;
		}
	}
	cout << list[mid] << endl;
	return 0;
}
