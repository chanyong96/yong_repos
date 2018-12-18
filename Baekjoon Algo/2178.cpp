#include <bits/stdc++.h>

using namespace std;

int N, M;

void bfs(vector<vector<int> > &v, vector<vector<int>> &d_v) {
	queue<int> bfsx, bfsy;
	int i, j, x[] = { -1,0,1,0 }, y[] = { 0,1,0,-1 };
	bfsx.push(0);
	bfsy.push(0);
	d_v[0][0] = 1;
	while (!bfsx.empty()) {
		i = bfsx.front();
		j = bfsy.front();
		bfsx.pop();
		bfsy.pop();
		if (v[i][j]) {
			v[i][j] = 0;
			for (int k = 0; k < 4; k++) {
				if ((i + x[k] >= 0) && (i + x[k] < N) && (j + y[k] >= 0) && (j + y[k] < M)) {
					if (v[i + x[k]][j + y[k]]) {
						bfsx.push(i + x[k]);
						bfsy.push(j + y[k]);
						d_v[i + x[k]][j + y[k]] = d_v[i][j] + 1;
					}
				}
			}
		}
	}
}

int main(void) {
	int mbuf=0;
	char c;
	cin >> N >> M;
	vector<vector<int>> v(N, vector<int>(M, 0));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> c;
			v[i][j] = c - 48;
		}
	}
	vector<vector<int>> d_v(N, vector<int>(M, 0));
	//
	//for (int i = 0; i < N; ++i) {
	//	for (int j = 0; j < v[i].size(); ++j) {
	//		cout << v[i][j] << " ";
	//	}
	//	cout << "\n";
	//}
	bfs(v, d_v);
	//for (int i = 0; i < N; ++i) {
	//	for (int j = 0; j < d_v[i].size(); ++j) {
	//		cout << d_v[i][j] << " ";
	//	}
	//	cout << "\n";
	//}
	cout << d_v[N - 1][M - 1] << "\n";
	return 0;
}