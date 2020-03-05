#include<iostream>
using namespace std;
int main() {
	int i, ans, flag = 0;
	char o = 'a';
	cin >> ans;
	while (o != '=') {
		cin >> o;
		if (o == '=')
			break;
		cin >> i;
		switch (o) {
		case '+':
			ans = ans + i;
			break;
		case '-':
			ans = ans - i;
			break;
		case '*':
			ans = ans * i;
			break;
		case '/':
			if (i != 0)
				ans = ans / i;
			else {
				flag = 1;
			}
			break;
		default:
			flag = 1;
		}
	}
	if (flag == 1)
		cout << "ERROR" << endl;
	else
		cout << ans << endl;
	return 0;
}