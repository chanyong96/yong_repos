#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;

	int* arr = new int[T];

	int arr_numZero[41]; // 피보나치 함수에서 N이 0~40일때 출력하는 0의 갯수를 담은  
	arr_numZero[0] = 1;
	arr_numZero[1] = 0;
	for (int a = 2; a < 41; a++) {
		arr_numZero[a] = arr_numZero[a - 1] + arr_numZero[a - 2];
	}

	int arr_numOne[41];
	arr_numOne[0] = 0;
	arr_numOne[1] = 1;
	for (int b = 2; b < 41; b++) {
		arr_numOne[b] = arr_numOne[b - 1] + arr_numOne[b - 2];
	}

	for (int i = 0; i < T; i++) {
		cin >> arr[i];
	}
	for (int k = 0; k < T; k++) {
		cout << arr_numZero[arr[k]] << " " << arr_numOne[arr[k]] << endl;
	}

	return 0;
}