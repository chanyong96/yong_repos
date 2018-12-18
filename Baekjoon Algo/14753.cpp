#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(void) {
	int n;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;

	vector<int> v, max;
	for (int i = 0; i < n; i++) {
		int card_num;
		cin >> card_num;
		v.push_back(card_num);
	}
	sort(v.begin(), v.end());
	
	max.push_back(v[v.size() - 1] * v[v.size() - 2] * v[v.size() - 3]);
	max.push_back(v[v.size() - 1] * v[0] * v[1]);
	max.push_back(v[0] * v[1]);
	max.push_back(v[v.size() - 1] * v[v.size() - 2]);

	sort(max.begin(), max.end());
	cout << max[max.size() - 1] << "\n";

	return 0;
}