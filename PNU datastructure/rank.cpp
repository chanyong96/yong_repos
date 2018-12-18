#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ifstream input;
	ofstream output;
	input.open("rank.inp");
	output.open("rank.out");

	int N, score;
	input >> N;
	vector<vector<int>> vec(N);
	for (int i = 0; i < N; i++) {
		score = 0;
		while (score != -1) {
			input >> score;
			vec[i].push_back(score);
		}
		sort(vec[i].begin(), vec[i].end());	
		vec[i][0] = vec[i].size();	
		vec[i].push_back(-i - 1);
	}
	input.close();
	sort(vec.begin(), vec.end());

	for (int i = N - 1; i >= 0; i--) {
		output << -vec[i].back() << "\n";
	}
	output.close();
	return 0;
}