#include <iostream>

using namespace std;

// 입력값이 클수록 scanf와 cin의 연산속도차이가 확연히 커진다
int main() {
	int N;
	scanf("%d", &N);
	
	for (int i = 1; i <= N; i++) {
		printf("%d\n", i);
	}

	return 0;
}
