/*
��ǥ �Է� -> ��ǥ �� �ش� �� ���
���� �Է� -> ������ ����ִ� �迭�� ��ǥ ���
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
	//// ���Ұ� ���
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
	//// ��->��
	//for (int i = 0; i<m; i++) {
	//	count++;
	//	nanobot[1000 - i][0] = count;
	//}
	//// ��->��
	//for (int i = 1; i<n; i++) {
	//	count++;
	//	nanobot[1001 - m][i] = count;
	//}
	//// ��->��
	//for (int i = m - 2; i >= 0; i--) {
	//	count++;
	//	nanobot[1000 - i][n - 1] = count;
	//}
	//// ��->��
	//for (int i = n - 2; i >= 1; i--) {
	//	count++;
	//	nanobot[1000][i] = count;
	//}

	//for (int i = 1; i <= m - 2; i++) {
	//	count++;
	//	nanobot[1000 - i][1] = count;
	//}
	//// ���Ұ� ���
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
	//	// ��->��
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
