//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//int main() {
//	long long int N; // N<=250000
//	int K;	
//	ios::sync_with_stdio(false);
//	cin >> N >> K;
//	int* arr = new int[N+1]; // 입력값들을 배열에 담는다.
//	long long sum = 0;
//	for (long long i = 1; i <= N; i++) {
//		cin >> arr[i];// 입력으로 들어오는 값 <= 65536
//	} 
//		
//	long long sum = 0;
//	for (long long j = 0; j < N-K+1; j++) {		
//		int* tmp_arr = new int[K];
//		for (int k = 0; k < K; k++) {
//			tmp_arr[k] = arr[j+k];
//		}
//		sort(tmp_arr, tmp_arr + K);
//		sum+=tmp_arr[((K + 1) / 2) - 1];
//		delete tmp_arr;
//	}
//	delete arr; 
//	cout << sum << "\n";
//
//	return 0;
//}