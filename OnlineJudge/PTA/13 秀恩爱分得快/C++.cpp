#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, M, K;
int x, y;
double ans1[1010];
double ans2[1010];
int sexx, sexy;	// x和y对应异性性别
int num[510];
vector<int> v[1010][2];	// v[i][0]为第i+1幅照片里的男性的非负编号

void getRelationship(double a[], int x, int sex) {
	for (int i = 0; i < M; i++) {
		int flag = 0;
		int cnt = 0;
		for (int j = 0; j < v[i][(sex + 1) % 2].size(); j++) {
			int temp = v[i][(sex + 1) % 2][j];
			if (temp == abs(x)) {
				flag = 1;
				break;
			}
		}
		//cout << "flag" << flag << endl;
		if (flag == 1) {
			for (int j = 0; j < v[i][sex].size(); j++) {
				int temp = v[i][sex][j];
				a[temp] += 1.000000 / num[i];
				//cout << temp << ' ' << a[temp] << endl;
			}
		}
	}
}

int main() {
	cin >> N >> M;
	char input[11];
	char xx[11];
	char yy[11];
	for (int i = 0; i < M; i++) {
		cin >> K;
		num[i] = K;
		for (int j = 0; j < K; j++) {
			cin >> input;
			int a = abs(atoi(input));
			if (input[0] != '-') {
				v[i][0].push_back(a);
			}
			else v[i][1].push_back(a);
		}
	}
	cin >> xx >> yy;
	x = atoi(xx);
	y = atoi(yy);
	// 获取x相关异性信息
	if (xx[0] != '-') {
		sexx = 1;
		sexy = 0;
	}
	else {
		sexx = 0;
		sexy = 1;
	}
	getRelationship(ans1, x, sexx);
	getRelationship(ans2, y, sexy);
	vector<int> bestx, besty;
	double maxx = *max_element(ans1, ans1 + N);
	double maxy = *max_element(ans2, ans2 + N);
	if (ans1[abs(y)] == maxx && ans2[abs(x)] == maxy) {
		cout << xx << ' ' << yy << endl;
	}
	else {
		for (int i = 0; i < N; i++) {
			if (ans1[i] == maxx) {
				if (sexx) {
					cout << abs(x) << " -" << i << endl;
				}
				else cout << '-' << abs(x) << ' ' << i << endl;
			}
		}
		for (int i = 0; i < N; i++) {
			if (ans2[i] == maxy) {
				if (sexy) {
					cout << abs(y) << " -" << i << endl;
				}
				else cout << '-' << abs(y) << ' ' << i << endl;
			}
		}
	}

}