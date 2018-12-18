#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(void) {
	ifstream input;
	ofstream output;
	input.open("rumor.inp");
	output.open("rumor.out");

	int N, x, d;
	input >> N >> x >> d;

	vector<vector<int>> v(N);
	vector<bool> b_v(N+1);
	vector<int> q_v;
	for (int i = 0; i <= N; i++)
		b_v[i] = 0;

	for (int i = 0; i < N; i++) {
		int num;
		input >> num;
		v[i].push_back(num);
		while (num != 0) {
			input >> num;
			v[i].push_back(num);
		}
	}
	for (int i = 0; i < N; i++) {
		sort(v[i].begin()+1, v[i].end());
	}	
	queue<int> q;
	q.push(x);
	q_v.push_back(x);
	b_v[x] = 1;
	int count = 0;
	while (count < d) {
		count++;
		int Q = q.size();
		for (int j = 0; j < Q; j++) {
			int qf = q.front();
			q.pop();
			int id;
			for (int i = 0; i < N; i++) {
				if (v[i][0] == qf) {
					id = i;
					break;
				}
			}
			for (int i = 2; i < v[id].size(); i++) {
				int element = v[id][i];
				if (b_v[element] == 0) {
					b_v[element] = 1;
					q.push(element);
					q_v.push_back(element);
				}
			}
		}
	}
	for (int i = 0; i < q_v.size(); i++)
		output << q_v[i] << "\n";
		
	input.close();
	output.close();
	return 0;
}