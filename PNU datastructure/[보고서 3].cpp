#include <iostream>
#include <vector>

using namespace std;

int decide_seat(int n) {


}

int main(void) {
	int N;
	cin >> N;

	vector<vector<int>> v(N);
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v.size(); j++) {
			v[i].push_back(0);
		}
	}
	int cnt=1, x = 0, y = 0;

	// 1, 2~3, 4~6, ... 
	for (int i = 0; i < N * 2 - 1; i++) {
		if (i % 2 == 0) {
			if (i == 0) {
				v[x][y] = cnt;
			}
			else {
				x++;
				for (int j = 0; ; ++j) {

				}
			}

				
		}
		
		else {
			if (i == N * 2 - 1) {
				y++;
				v[x][y] = cnt;
			}
			else {
				y++;
				v[x][y] = cnt;
				
			}

		}

	}

	vector<int> person;
	for (int i = 0; i < 3; i++) {
		int num;
		cin >> num;
		person.push_back(num);
	}
	for (int i = 0; i < 3; i++) {
		if (person[i] > N*N)
			cout << "0" << "\n";
		else
			decide_seat(person[i]);
	}

	return 0;
}