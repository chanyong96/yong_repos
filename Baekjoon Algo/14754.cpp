#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int n, m;
	ios::sync_with_stdio(false);
	cin >> n >> m;

	vector<vector<long>> v(n), NotErase(n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			long num;
			cin >> num;
			v[i].push_back(num);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			NotErase[i].push_back(0);
		}
	}

	// row에 대하여 판별
	for (int i = 0; i < n; i++) {
		long cmp = 0, _i=0, _j=0;
		for (int j = 0; j < m; j++) {
			if (cmp < v[i][j]) {
				cmp = v[i][j];
				_i = i;
				_j = j;
			}
		}
		NotErase[_i][_j] = cmp;
	}
		
	// column에 대하여 판별
	for (int i = 0; i < m; i++) {
		long cmp = 0, _i=0, _j=0;
		for (int j = 0; j < n; j++) {
			if (cmp < v[j][i]) {
				cmp = v[j][i];
				_i = j;
				_j = i;
			}
		}
		NotErase[_i][_j] = cmp;
	}

	long total_sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			total_sum += v[i][j];
		}
	}

	long remain_sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			remain_sum += NotErase[i][j];
		}
	}

	cout << total_sum - remain_sum << "\n";

	return 0;
}