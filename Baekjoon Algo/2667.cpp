#include <bits/stdc++.h>

using namespace std;


int town(vector<vector<char>> &v, int x, int y) {
	queue<int> bfs_x, bfs_y;
	int i, j, cnt=0;
	bfs_x.push(x);
	bfs_y.push(y);
	while (!(bfs_x.empty())) {
		i = bfs_x.front();
		j = bfs_y.front();
		bfs_x.pop();
		bfs_y.pop();
		if (v[i][j] == '1') {
			v[i][j] = '0';
			cnt++;
			if (i == 0) {
				if (j == 0) {
					if (v[i][j + 1] == '1') { // 우
						bfs_x.push(i);
						bfs_y.push(j + 1);
					}
					if (v[i + 1][j] == '1') { // 하 
						bfs_x.push(i + 1);
						bfs_y.push(j);
					}

				}
				else if ((unsigned)j == v[i].size() - 1) {
					if (v[i][j - 1] == '1') { // 좌
						bfs_x.push(i);
						bfs_y.push(j - 1);
					}
					if (v[i + 1][j] == '1') { // 하 
						bfs_x.push(i + 1);
						bfs_y.push(j);
					}
				}
				else { // 좌 우 하
					if (v[i][j - 1] == '1') { // 좌
						bfs_x.push(i);
						bfs_y.push(j - 1);
					}
					if (v[i][j + 1] == '1') { // 우
						bfs_x.push(i);
						bfs_y.push(j + 1);
					}
					if (v[i + 1][j] == '1') { // 하 
						bfs_x.push(i + 1);
						bfs_y.push(j);
					}
				}

			}
			else if ((unsigned)i == v.size() - 1) {
				if (j == 0) { // 상 우
					if (v[i - 1][j] == '1') { // 상
						bfs_x.push(i - 1);
						bfs_y.push(j);
					}
					if (v[i][j + 1] == '1') { // 우
						bfs_x.push(i);
						bfs_y.push(j + 1);
					}
				}
				else if ((unsigned)j == v[i].size() - 1) { // 상 좌
					if (v[i - 1][j] == '1') { // 상
						bfs_x.push(i - 1);
						bfs_y.push(j);
					}
					if (v[i][j - 1] == '1') { // 좌
						bfs_x.push(i);
						bfs_y.push(j - 1);
					}
				}
				else { // 상 좌 우
					if (v[i - 1][j] == '1') { // 상
						bfs_x.push(i - 1);
						bfs_y.push(j);
					}
					if (v[i][j - 1] == '1') { // 좌
						bfs_x.push(i);
						bfs_y.push(j - 1);
					}
					if (v[i][j + 1] == '1') { // 우
						bfs_x.push(i);
						bfs_y.push(j + 1);
					}
				}
			}
			else {
				if (j == 0) { // 상 하 우
					if (v[i - 1][j] == '1') { // 상
						bfs_x.push(i - 1);
						bfs_y.push(j);
					}
					if (v[i + 1][j] == '1') { // 하
						bfs_x.push(i + 1);
						bfs_y.push(j);
					}
					if (v[i][j + 1] == '1') { // 우
						bfs_x.push(i);
						bfs_y.push(j + 1);
					}
				}
				else if ((unsigned)j == v[i].size() - 1) { // 상 하 좌
					if (v[i - 1][j] == '1') { // 상
						bfs_x.push(i - 1);
						bfs_y.push(j);
					}
					if (v[i + 1][j] == '1') { // 하 
						bfs_x.push(i + 1);
						bfs_y.push(j);
					}
					if (v[i][j - 1] == '1') { // 좌
						bfs_x.push(i);
						bfs_y.push(j - 1);
					}
				}
				else { // 상 하 좌 우
					if (v[i - 1][j] == '1') { // 상
						bfs_x.push(i - 1);
						bfs_y.push(j);
					}
					if (v[i + 1][j] == '1') { // 하 
						bfs_x.push(i + 1);
						bfs_y.push(j);
					}
					if (v[i][j - 1] == '1') { // 좌
						bfs_x.push(i);
						bfs_y.push(j - 1);
					}
					if (v[i][j + 1] == '1') { // 우
						bfs_x.push(i);
						bfs_y.push(j + 1);
					}

				}
			}

		}
		
	}
	// 가장 바깥쪽(테두리)에 있는 원소들만 따로 예외처리
	
	return cnt;
}

int main(void) {
	int N;
	cin >> N;
	vector<vector<char>> vs;
	for (int i = 0; i < N; ++i) {
		vector<char> tmp_v;
		for (int j = 0; j < N; ++j) {
			char s;
			cin >> s;
			tmp_v.push_back(s);
		}
		vs.push_back(tmp_v);
	}
	vector<int> vir;

	for (unsigned int i = 0; i < N; ++i) {
		for (unsigned int j = 0; j < N; ++j) {
			// 가장 바깥쪽(테두리)에 있는 원소들만 따로 예외처리
			if (vs[i][j] == '1') {
				int vs_l = town(vs, i, j);
				if (vs_l)
					vir.push_back(vs_l);
			}
		}
	}
	cout << vir.size() << "\n";
	if (vir.size() != 0) {
		sort(vir.begin(), vir.end());
		for (auto it = vir.begin(); it != vir.end(); ++it)
			cout << (*it) << "\n";
	}
	return 0;
}
