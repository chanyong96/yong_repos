#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	long n, m, c1, c2;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> c1 >> c2;
	vector<long> P, Q;
	for (int i = 0; i < n; i++) {
		long num;
		cin >> num;
		P.push_back(num);
	}
	for (int i = 0; i < m; i++) {
		long num;
		cin >> num;
		Q.push_back(num);
	}
	// 벡터 원소값 확인
	for (int i = 0; i < n; i++) {
		cout << P[i] << " ";
	}
	cout << "\n";
	for (int i = 0; i < m; i++) {
		cout << Q[i] << " ";
	}
	cout << "\n";

	return 0;
}