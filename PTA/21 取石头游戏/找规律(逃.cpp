#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int temp = n % 15;
	if (temp == 0 || temp == 2 || temp == 4 || temp == 6) {
		cout << 0;
	}
	else cout << 1;
}