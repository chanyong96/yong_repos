#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int T;
	ios::sync_with_stdio(false);
	cin >> T;

	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;
		long* arr_init = new long[N];
		for (int j = 0; j < N; j++) {
			cin >> arr_init[j];
		}
		sort(arr_init, arr_init + N);
		
		int arr_sz = N;
		long* arr_sorted = new long[N];
		int center;		// 배열의 중간위치 인덱스 변수 선언
		if (N % 2 == 0) {
			center = (N + 1) / 2;
		}
		else if (N % 2 == 1) {
			center = (N - 1) / 2;
		}
		arr_sz--;
		arr_sorted[center] = arr_init[arr_sz];

		int center_to_left = center;
		int center_to_right = center;
		
		while (arr_sz > 0) {
			arr_sz--;
			center_to_left--;
			arr_sorted[center_to_left] = arr_init[arr_sz];
			if (arr_sz == 0) {
				break;
			}

			arr_sz--;
			center_to_right++;
			arr_sorted[center_to_right] = arr_init[arr_sz];
			if (arr_sz == 0) {
				break;
			}
		}

		int max = 0;
		max = abs(arr_sorted[0]-arr_sorted[N - 1]);
		for (int k = 0; k < N - 1;k++) {
			if (max < abs(arr_sorted[k] - arr_sorted[k + 1])) {
				max = abs(arr_sorted[k] - arr_sorted[k + 1]);
			}
		}	
		cout << max << "\n";
	}
	return 0;
}