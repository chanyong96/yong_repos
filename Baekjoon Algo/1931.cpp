#include <iostream>


using namespace std;

int main()
{
	int N;
	cin >> N;
	int* startArr = new int[N];
	int* endArr = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> startArr[i];
		cin >> endArr[i];	
	}

	/*
	1. endArr의 원소 중 가장 작은 값 찾기
	2. 찾아낸 가장 작은 값의 인덱스 찾기 (K라고 칭하겠음)
	3. startArr[K]~endArr[K]와 겹치는 회의 제거
	4. 

	*/
	

	return 0;
}


/*
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string A;
	cin >> A;
	cout << A << "\n";
	
	
	return 0;
}
*/