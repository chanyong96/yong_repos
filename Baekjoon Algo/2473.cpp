#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int N;
	ios::sync_with_stdio(false);
	cin >> N;

	int* arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);

	for (int j = 0; j < N-2; j++) {				// j´Â ÇÇº¿
		for (int k = j + 1, int l = N - 1;;¤¿++) {	// 

		}
	}

	return 0;
}