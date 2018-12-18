#include <iostream>

using namespace std;

int main() {
	int n;
	ios::sync_with_stdio(false);
	cin >> n;

	int sum = 0;
	for (int i = 1; i <= n; n++) {
		sum += i;
	}
	cout << sum << "\n";

	return 0;
}