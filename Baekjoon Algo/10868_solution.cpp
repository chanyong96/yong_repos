#include <iostream>
#include <stack>

using namespace std;

int main() {
	int n;
	ios::sync_with_stdio(false);
	cin >> n;

	int* arr_input = new int[n+1];
	
	stack<int> s1;
	stack<int> s2;

	for (int i = 1; i <= n; i++) {
		cin >> arr_input[i];
	}
	for (int j = 1; j <= n; j++) {
		s1.push(j);
	}

	while
	return 0;
}