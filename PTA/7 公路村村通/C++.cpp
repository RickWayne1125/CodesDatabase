#include <iostream>
using namespace std;
#define MAX 1001
#define INF 99999;
int main(){
	int map[MAX][MAX];
	int dis[MAX];
	int visit[MAX];
	int path[MAX];

	int vcnt = 0;
	int weight_sum = 0;
	int vn, en;
	cin >> vn >> en;
	for (int i = 1; i <= vn; i++) {
		for (int j = 1; j <= vn; j++) {
			if (i == j)
				map[i][j] = 0;
			else
				map[i][j] = INF;
		}
	}
	if (en < vn - 1) {
		cout << -1 << endl;
	}
	else {
		
		// 生成图
		for (int i = 1; i <= en; i++) {
			int x, y, weight;
			cin >> x >> y >> weight;
			map[x][y] = weight;
			map[y][x] = weight;
		}

		for (int i = 1; i <= vn; i++) {
			dis[i] = map[1][i];
			visit[i] = 0;
			path[i] = 0;
		}

		visit[1] = 1;
		vcnt++;
		path[0] = 1;

		while (vcnt <= vn) {
			int min = INF;
			int k = 0;
			for (int i = 1; i <= vn; i++) {
				if (visit[i] == 0 && min > dis[i]){
					min = dis[i];
					k = i;
				}
			}
			if (k == 0)
				break;
			visit[k] = 1;
			path[vcnt] = k;
			vcnt++;
			weight_sum += dis[k];

			for (int i = 1; i <= vn; i++) {
				if (visit[i] == 0 && dis[i] > map[k][i]){
					dis[i] = map[k][i];
				}
			}
		}
		int flag=1;
		for (int i = 1; i <= vn; i++) {
			if (visit[i] != 1) {
				flag = 0;
				break;
			}
		}
		if (flag) {
			cout << weight_sum << endl;
		}
		else cout << -1 << endl;
	}
}