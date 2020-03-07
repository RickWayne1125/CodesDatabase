#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int N;
	int in[100000];
	int out[100000];
	int flag = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> in[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			out[flag] = in[i] + in[j];
			flag++;
		}
	}
	sort(out, out + flag);
	for (int i = 0; i < flag - 1; i++) {
		cout << out[i] << ' ';
	}
	cout << out[flag - 1];
}