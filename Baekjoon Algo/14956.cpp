#include <iostream>

using namespace std;

//int PW(int _n) {
//	
//}

int main()
{
	int n;
	cin >> n;
	int m;
	cin >> m;

	pair<int,int>* arr = new pair<int,int>[n*n+1];
	if (n == 2) {
		arr[1].first = 1;
		arr[1].second = 1;
		arr[2].first = 1;
		arr[2].second = 2;
		arr[3].first = 2;
		arr[3].second = 2;
		arr[4].first = 2;
		arr[4].second = 1;
	}
	//// n이 4, 8, 16, ... 이라면
	else {


	}
	
	cout << arr[m].first << " " << arr[m].second << "\n";


	return 0;
}