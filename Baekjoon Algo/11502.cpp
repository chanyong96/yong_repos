#include <iostream>

using namespace std;

int num[1001];

// 소수 판별 함수
bool IsPrime(const int n) {
	int count = 0;
	for (int i = 1; i <= n; i++) {
		if (n % i == 0) {
			count++;
		}
	}
	if (count == 2) {
		return 1;
	}
	else
		return 0;
}

// 2부터 n까지의 숫자들 중 소수들 찾기
int num_PrimeNum(int n) {
	int p_count = 0;
	for (int k = 2; k <= n; k++) {
		if (IsPrime(k)) {
			// num[k]
			p_count++;
		}
	}
	return p_count;
}
// 

int main(void) {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int K;
		cin >> K;
		cout << num_PrimeNum(K) << "\n";
		// IsPrime(K);
	}

	
	return 0;
}