#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int T;
	ios::sync_with_stdio(false);
	
	
	cin >> T;
	vector<int> nv, mv, result;

	int n, m, count=0;
	for (int i = 0; i < T; ++i) {
		cin >> n >> m;
		nv.push_back(n);
		mv.push_back(m);
	}
	for (int i = 0; i < T; ++i) {
		if (nv[i] == mv[i]) {
			result.push_back(1);
		}
		else {
			for (int i = 0; i < n; ++i) {
				for (int j = i + 1; j < m; ++j) {
					count++;
				}
			}
			result.push_back(count);
		}
	}
	for (int i = 0; i < T; ++i) {
		cout << result[i] << "\n";
	}

	
	
	return 0;
}