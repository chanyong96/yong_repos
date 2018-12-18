#include <bits/stdc++.h>

using namespace std;

int virus(vector<vector<char>> &v, int x, int y) {
	queue<int> bfs_x, bfs_y;
	int i, j, cnt = 0;
	bfs_x.push(x);
	bfs_y.push(y);
	while (!bfs_x.empty()) {
		i = bfs_x.front();
		j = bfs_y.front();
		bfs_x.pop();
		bfs_y.pop();
		if (v[i][j] == '#') {
			v[i][j] = '_';
			cnt++;
			if (i == 0) {
				if (j == 0) {
					if (v[i][j + 1] == '#') { // ��
						bfs_x.push(i);
						bfs_y.push(j + 1);
					}
					if (v[i + 1][j] == '#') { // �� 
						bfs_x.push(i + 1);
						bfs_y.push(j);
					}

				}
				else if ((unsigned)j == v[i].size() - 1) {
					if (v[i][j - 1] == '#') { // ��
						bfs_x.push(i);
						bfs_y.push(j - 1);
					}
					if (v[i + 1][j] == '#') { // �� 
						bfs_x.push(i + 1);
						bfs_y.push(j);
					}
				}
				else { // �� �� ��
					if (v[i][j - 1] == '#') { // ��
						bfs_x.push(i);
						bfs_y.push(j - 1);
					}
					if (v[i][j + 1] == '#') { // ��
						bfs_x.push(i);
						bfs_y.push(j + 1);
					}
					if (v[i + 1][j] == '#') { // �� 
						bfs_x.push(i + 1);
						bfs_y.push(j);
					}
				}

			}
			else if ((unsigned)i == v.size() - 1) {
				if (j == 0) { // �� ��
					if (v[i - 1][j] == '#') { // ��
						bfs_x.push(i - 1);
						bfs_y.push(j);
					}
					if (v[i][j + 1] == '#') { // ��
						bfs_x.push(i);
						bfs_y.push(j + 1);
					}
				}
				else if ((unsigned)j == v[i].size() - 1) { // �� ��
					if (v[i - 1][j] == '#') { // ��
						bfs_x.push(i - 1);
						bfs_y.push(j);
					}
					if (v[i][j - 1] == '#') { // ��
						bfs_x.push(i);
						bfs_y.push(j - 1);
					}
				}
				else { // �� �� ��
					if (v[i - 1][j] == '#') { // ��
						bfs_x.push(i - 1);
						bfs_y.push(j);
					}
					if (v[i][j - 1] == '#') { // ��
						bfs_x.push(i);
						bfs_y.push(j - 1);
					}
					if (v[i][j + 1] == '#') { // ��
						bfs_x.push(i);
						bfs_y.push(j + 1);
					}
				}
			}
			else {
				if (j == 0) { // �� �� ��
					if (v[i - 1][j] == '#') { // ��
						bfs_x.push(i - 1);
						bfs_y.push(j);
					}
					if (v[i + 1][j] == '#') { // ��
						bfs_x.push(i + 1);
						bfs_y.push(j);
					}
					if (v[i][j + 1] == '#') { // ��
						bfs_x.push(i);
						bfs_y.push(j + 1);
					}
				}
				else if ((unsigned)j == v[i].size() - 1) { // �� �� ��
					if (v[i - 1][j] == '#') { // ��
						bfs_x.push(i - 1);
						bfs_y.push(j);
					}
					if (v[i + 1][j] == '#') { // �� 
						bfs_x.push(i + 1);
						bfs_y.push(j);
					}
					if (v[i][j - 1] == '#') { // ��
						bfs_x.push(i);
						bfs_y.push(j - 1);
					}
				}
				else { // �� �� �� ��
					if (v[i - 1][j] == '#') { // ��
						bfs_x.push(i - 1);
						bfs_y.push(j);
					}
					if (v[i + 1][j] == '#') { // �� 
						bfs_x.push(i + 1);
						bfs_y.push(j);
					}
					if (v[i][j - 1] == '#') { // ��
						bfs_x.push(i);
						bfs_y.push(j - 1);
					}
					if (v[i][j + 1] == '#') { // ��
						bfs_x.push(i);
						bfs_y.push(j + 1);
					}

				}
			}

		}

	}
	// ���� �ٱ���(�׵θ�)�� �ִ� ���ҵ鸸 ���� ����ó��
	return cnt;
}


int main(void) {
	ifstream input("micro.inp");
	ofstream output("micro.out");

	int N, M, k;
	input >> N >> M >> k;
	vector<vector<char>> v;
	
	for (int i = 0; i < M; ++i) {
		vector<char> tmp;
		for (int j = 0; j < N; ++j) {
			char ip;
			input >> ip;
			tmp.push_back(ip);
		}
		v.push_back(tmp);
	}
	vector<int> vir;
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			// ���� �ٱ���(�׵θ�)�� �ִ� ���ҵ鸸 ���� ����ó��
			int vs = virus(v, i, j);
			if (vs >= k)
				vir.push_back(vs);
		}
	}	
	
	int max_size = 0;
	for (int i = 0; i < vir.size(); ++i) {
		if (vir[i] >= max_size)
			max_size = vir[i];
	}
	output << vir.size() << " " << max_size << "\n";

	return 0;
}