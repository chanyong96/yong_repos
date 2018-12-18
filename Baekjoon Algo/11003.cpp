#include <iostream>

using namespace std;

int main() {
	int N;
	int L;
	ios::sync_with_stdio(false);
	cin >> N;
	cin >> L;

	int* arr = new int[N];
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}


	for (int j = 1; j <= N; j++) {
		cin >> arr[j];
	}


	return 0;
}