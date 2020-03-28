#include<iostream>
#include<set>
#include<iomanip>
#include<algorithm>
#include <vector>
using namespace std;
int main() {
	int N, M, K;
	vector<set<int>> in;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> M;
		set<int> temp;
		for (int j = 0; j < M; j++) {
			int x;
			cin >> x;
			set<int>::iterator ret;
			ret = find(temp.begin(), temp.end(), x);
			temp.insert(x);
		}
		in.push_back(temp);
	}
	cin >> K;
	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		int nc = 0;
		int nt = 0;
		for (auto it = in[a].begin(); it != in[a].end(); it++) {
			if (in[b].find(*it) != in[b].end()) {
				nc++;
			}
		}
		nt = in[a].size() + in[b].size() - nc;
		double ans = 100.00 * nc / nt;
		cout << setiosflags(ios::fixed) << setprecision(2) << ans << '%' << endl;
	}
}