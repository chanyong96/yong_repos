#include <iostream>

using namespace std;

// 2���� �迭�� ��� ���Ұ� ������ �״�� ���� �ϳ��� �ٸ��� 9����ϱ�
// 9����Ͽ� �ٽ� ��
// A�� �迭�� ��������, B�� �迭�� ������

int** arr;
int minus_paper, zero_paper, one_paper = 0;

void DividePaper(int A, int B, int size) {
	
	for (int c = A; c < A+size; c++) {
		for (int d = B; d < B+size; d++) {
			if (arr[A][B] != arr[c][d]) {
				for (int e = 0; e < 3; e++)
					for (int f = 0; f < 3; f++)
						DividePaper(A+(size/3)*e, B+(size/3)*)
				

				// N*(0/3)~N*

				// if���� ������ ����ϱ�
				
			}

		}

	}
}

int main()
{
	int N;
	cin >> N;
	int** arr = new int*[N];
	for (int i = 0; i < N; ++i) {
		arr[i] = new int[N];
	}

	
	for (int a = 0; a < N; a++) {
		for (int b = 0; b < N; b++) {
			cin >> arr[a][b];
		}
	}
	DividePaper(0, 0, N);
	

	
	
	return 0;
}