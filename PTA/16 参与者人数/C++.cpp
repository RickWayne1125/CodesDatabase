#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n, m;
	vector<int> g[510];
	int nums[510];	// groupmates number for each group
	int used[510];	// to target the groups used
	cin >> n >> m;
	int s[30010];	// to target the students involved in 
	for (int i = 0; i < n; i++) {
		s[i] = 0;
	}
	for (int i = 0; i < m; i++) {
		used[i] = 0;
	}
	// input
	for (int i = 0; i < m; i++) {
		cin >> nums[i];
		for (int j = 0; j < nums[i]; j++) {
			int temp;
			cin >> temp;
			g[i].push_back(temp);
			// put target on group 0
			if (i == 0) {
				s[temp] = 1;
			}
		}
	}
	// merge
	for (int i = 1; i < m; i++) {
		if (used[i] == 0) {
			int flag = 0;
			for (int j = 0; j < nums[i]; j++) {
				if (s[g[i][j]] == 1) {
					flag = 1;
					break;
				}
			}
			if (flag) {
				for (int l = 0; l < nums[i]; l++) {
					s[g[i][l]] = 1;
				}
				//ans += nums[i] - tar;
				used[i] = 1;
				i = 0;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (s[i])	ans++;
	}
	cout << ans << endl;
}