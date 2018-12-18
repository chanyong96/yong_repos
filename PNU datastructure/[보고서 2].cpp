#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	vector<vector<int>> v(5);
	for (int i = 0; i < 5; i++) {
		while (true) {
			int num;
			cin >> num;
			v[i].push_back(num);
			if (num == 0)
				break;
		}	
	}
	for (int i = 0; i < 5; ++i) {
		sort(v[i].begin(), v[i].end());
		v[i].erase(unique(v[i].begin(), v[i].end()), v[i].end());
		v[i].erase(v[i].begin());				
	}

	vector<int> s1, s2; // s1 : 2차원 벡터의 모든 원소들, s2 : 2차원 벡터의 원소들 중 중복되는 원소들
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < v[i].size(); ++j) {
			if (find(s2.begin(), s2.end(), v[i][j]) != s2.end())
				s1.push_back(v[i][j]);
			else
				s2.push_back(v[i][j]);
		}
	}
	sort(s1.begin(), s1.end());
	s1.erase(unique(s1.begin(), s1.end()), s1.end());
	for (int i = 0; i < s1.size(); i++)
		cout << s1[i] << " ";
	cout << "\n";
	return 0;
}