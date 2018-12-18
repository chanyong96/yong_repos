#include <iostream>

using namespace std;

// 2차원 배열의 모든 원소가 같으면 그대로 쓰고 하나라도 다르면 9등분하기
// 9등분하여 다시 비교
// A는 배열의 시작지점, B는 배열의 끝지점

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

				// if문의 마지막 재귀하기
				
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