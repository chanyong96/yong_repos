#include <iostream>

using namespace std;
/*
 2���� �迭�� ���������� ���������ν�
 ���� ���� 0���� �ʱ�ȭ
 */
int arr[501][501];

int main() {
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> arr[i][j];
		}
	}
	
	for (int k = 1; k <= n; k++) {
		for (int l = 1; l <= k; l++) {
			if (arr[k - 1][l - 1] < arr[k - 1][l])
				arr[k][l] += arr[k - 1][l];
			else
				arr[k][l] += arr[k - 1][l - 1];
		}
	}

	// arr[n][1]~arr[n][n] �� �ִ밪 ã��
	int max = 0;
	for (int A = 1; A <= n; A++) {
		if (max <= arr[n][A])
			max = arr[n][A];
	}
	cout << max << endl;

	return 0;
}