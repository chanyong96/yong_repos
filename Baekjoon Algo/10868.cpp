#include <iostream>

using namespace std;

int main() {
	int N;
	ios::sync_with_stdio(false);
	cin >> N;

	int M;
	ios::sync_with_stdio(false);
	cin >> M;

	int* numArr = new int[N]; // N���� ������ ���� �迭
	for (int i = 1; i <= N; i++) {
		cin >> numArr[i];
	}

	for (int _x = 0; _x < M; _x++) {

	}

	/*
	int* aArr = new int[M];		// M���� �׽�Ʈ ������ �� ���������鸸 ���� �迭
	int* bArr = new int[M];		// M���� �׽�Ʈ ������ �� ���������鸸 ���� �迭
	for (int j = 0; j < M; j++) {
		cin >> aArr[j];	
		cin >> bArr[j];
	}
	
	for (int k = 0; k < M; k++) {
		int min = numArr[aArr[k]];
		for (int l = aArr[k]; l < bArr[k]; l++) { 
			if (numArr[l] <= numArr[l + 1]) {
				min = numArr[l];
			}
			else {
				min = numArr[l + 1];
			}
		}
		cout << min << endl;
	}
	*/

	return 0;
}