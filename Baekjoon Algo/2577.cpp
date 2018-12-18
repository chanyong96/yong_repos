#include <iostream>

using namespace std;

int main() {
	int A,B,C;
	cin >> A;
	cin >> B;
	cin >> C;

	int val = A * B*C;

	int numArr[10] = {0};
	
	while (val / 10 != 0) {
		numArr[val % 10]++;
		val /= 10;
		if (val / 10 == 0) {
			numArr[val]++;
		}
	}
	
	for (int i = 0; i < 10; i++) {
		cout << numArr[i] << endl;
	}

	return 0;
}

