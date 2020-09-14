#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int begin[110];
	int end[110];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> begin[i] >> end[i];
	}
	sort(begin, begin + n);
	sort(end, end + n);
	int j = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (begin[i] < end[j]) ans++;
		else j++;
	}
	cout << ans << endl;
	return 0;
}