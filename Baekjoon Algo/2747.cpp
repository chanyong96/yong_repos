#include <bits/stdc++.h>

using namespace std;

int Fibo(int n) {
	int a = 0;
	int b = 1;
	int tmp;
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else {
		for (int i = 0; i < n - 1; ++i) {
			tmp = b;
			b = a + b;
			a = tmp;
		}
	}
	return b;
}

int main(void) {
	int n;
	cin >> n;
	int res = Fibo(n);
	cout << res << "\n";
	
	return 0;
}