#include <iostream>

using namespace std;

int main() {
	cout << "Row First Access" << "\n";
	int myarray_A[3][3] = { {0, 1, 2}, {3, 4, 5}, {6, 7, 8} };
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << &myarray_A[i][j] << "\t";
		}
		cout << "\n";
	}
	cout << "\n";

	cout << "Column First Access" << "\n";
	int myarray_B[3][3] = { { 0, 1, 2 },{ 3, 4, 5 },{ 6, 7, 8 } };
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 3; i++) {
			cout << &myarray_A[i][j] << "\t";
		}
		cout << "\n";
	}
	return 0;
}