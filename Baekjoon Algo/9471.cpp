#include <bits/stdc++.h>

using namespace std;

long long Fibo(int n, int M) {
	long long a = 0;
	long long b = 1;
	long long tmp;
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else {
		for (int i = 0; i < n-1; ++i) {
			tmp = b;
			b = a + b;
			a = tmp;
		}
	}

	return (b % M);
}

int main(void) {
	int P;
	cin >> P;
	vector<int> testNum;
	vector<long long> mod;
	for (int i = 0; i < P; ++i) {
		int N;
		long long M;
		cin >> N;
		testNum.push_back(N);
		cin >> M;
		mod.push_back(M);
	}
	vector<long long> res;
	for (int i = 0; i < P; ++i) {
		
	}

	//Ãâ·ÂºÎ
	for (int i = 0; i < P; ++i) {
		cout << testNum[i] << " " << res[i] << "\n";
	}

	return 0;
}