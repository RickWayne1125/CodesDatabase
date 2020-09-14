#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> d[100001];
int rec[100001];	//该成员辈分
int main() {
	int n, anc, t;
	int flag = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t;
		if (t == -1) {
			anc = i;
			rec[i] = 1;
		}
		else d[t].push_back(i);
	}
	int ans = 1;
	queue<int> q;
	q.push(anc);
	while (!q.empty()) {
		anc = q.front();
		q.pop();
		if (d[anc].size() > 0)
			ans = max(rec[anc] + 1, ans);
		for (int i = 0; i < d[anc].size(); i++) {
			t = d[anc][i];
			rec[t] = rec[anc] + 1;
			q.push(t);
		}
	}
	cout << ans << endl;
	for (int i = 1; i <= n; i++) {
		if (rec[i] == ans) {
			switch (flag) {
			case 0:	cout << i; flag = 1; break;
			case 1:	cout << ' ' << i; break;
			}
		}
	}
}