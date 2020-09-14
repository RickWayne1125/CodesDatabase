#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main() {
	int N;
	int ans = 0;
	cin >> N;
	int rec[100001];
	vector<int> dis[100001];
	int temp, K;
	for (int i = 1; i <= N; i++) {
		rec[i] = 0;
	}
	for (int i = 1; i <= N; i++) {
		cin >> K;
		for (int j = 0; j < K; j++) {
			cin >> temp;
			dis[i].push_back(temp);
			rec[temp] = 1;
		}
	}
	int root;
	// find root
	for (int i = 1; i <= N; i++) {
		if (rec[i] == 0)	root = i;
	}
	queue<int> q;
	q.push(root);
	while (q.empty() == false) {
		temp = q.front();
		q.pop();
		ans = temp;
		for (int i = 0; i < dis[temp].size(); i++) {
			q.push(dis[temp][i]);
		}
	}
	cout << ans << endl;
}