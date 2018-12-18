#include <iostream>

using namespace std;

int main() {
	int arr[8];
	
	ios::sync_with_stdio(false);
	for (int i = 0; i < 8; i++) {
		cin >> arr[i];
	}

	int count = 0;
	// 배열 arr의 각 원소 값과 for문의 변수 j값 비교
	// 
	for (int j = 0; j < 8; j++) {
		if (arr[j] == j + 1)		//ascending
			count++;
		else if (arr[j] == 8 - j)	//descending	
			count--;

	}

	if (count == 8)
		printf("ascending\n");
	else if (count == -8)
		printf("descending\n");
	else
		printf("mixed\n");

	return 0;

}