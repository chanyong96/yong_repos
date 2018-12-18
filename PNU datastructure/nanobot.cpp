/*
좌표 입력 -> 좌표 내 해당 값 출력
정수 입력 -> 정수가 들어있는 배열의 좌표 출력
*/

#include <iostream>
#include <string.h>
using namespace std;

//int nanobot[1001][1001];

int main() {
	int n, m;
	ios::sync_with_stdio(false);
	cin >> n >> m;
	int x, y;
	cin >> x >> y;
	int k;
	cin >> k;

	int** nanobot = new int*[m];
	for (int i = 0; i < m; i++) {
		nanobot[i] = new int[n];
		memset(nanobot[i], 0, sizeof(int)*n);
	}
	//// 원소값 출력
	for (int j = 0; j < n; j++) {
		for (int k = 0; k < m; k++) {
			cout << nanobot[j][k] << "\n";
		}
	}

	for (int j = 0; j < m; j++) {
		delete [] nanobot[j];
	}
	delete[] nanobot;
	//int count = 0;
	//// 하->상
	//for (int i = 0; i<m; i++) {
	//	count++;
	//	nanobot[1000 - i][0] = count;
	//}
	//// 좌->우
	//for (int i = 1; i<n; i++) {
	//	count++;
	//	nanobot[1001 - m][i] = count;
	//}
	//// 상->하
	//for (int i = m - 2; i >= 0; i--) {
	//	count++;
	//	nanobot[1000 - i][n - 1] = count;
	//}
	//// 우->좌
	//for (int i = n - 2; i >= 1; i--) {
	//	count++;
	//	nanobot[1000][i] = count;
	//}

	//for (int i = 1; i <= m - 2; i++) {
	//	count++;
	//	nanobot[1000 - i][1] = count;
	//}
	//// 원소값 출력
	///*for (int j = m - 1; j >= 0; j--) {
	//	for (int k = 0; k < n; k++) {
	//		cout << nanobot[1000-j][k] << "\n";
	//	}
	//}*/
	//while (count < n*m) {
	//	for (int i = 2; i<n-1; i++) {
	//		count++;
	//		nanobot[1002 - m][i] = count;
	//	}
	//	if (count == n * m) {
	//		break;
	//	}
	//	// 상->하
	//	for (int i = m - 3; i >= 1; i--) {
	//		count++;
	//		nanobot[1000 - i][n - 2] = count;
	//	}
	//	if (count == n * m) {
	//		break;
	//	}
	//}
	return 0;
}
