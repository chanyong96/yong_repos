//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//void Eratos(vector<bool>& base, const int N, const int K) {
//	int counter = 0;
//	for (int i = 2; i <= N; i++) {
//		if (base[i]) {
//			counter++;
//			if (counter == K) {
//				cout << i << "\n";
//				return;
//			}
//			for (int j = 2; i*j <= N; j++) {
//				if (base[i*j]) {
//					counter++;
//					base[i*j] = false;
//					if (counter == K) {
//						cout << i*j << "\n";
//						return;
//					}
//				}
//			}
//		}
//	}
//
//}
//
//int main()
//{
//	int N, K;
//	cin >> N;
//	cin >> K;
//
//	vector<bool> v(N + 1, true);
//	Eratos(v, N, K);
//
//	return 0;
//}

