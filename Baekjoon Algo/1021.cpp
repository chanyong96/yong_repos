
 #include <bits/stdc++.h>

using namespace std;

int main(void) {
	int N, M;
	ios::sync_with_stdio(false);

	cin >> N >> M;
	list<int> l;
	for (int i = 1; i <= N; ++i) l.push_back(i);

	vector<int> v;
	for (int i = 0; i < M; ++i) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	int cnt = 0;


	for (int i = 0; i < M; ++i) {
		list<int>::iterator iter_b = l.begin();

		int cnt_b = 0;
		while ((*iter_b) != v[i]) {
			iter_b++;
			cnt_b++;
		}

		if (cnt_b < (l.size() - cnt_b)) {
			cnt += cnt_b;
			if (cnt_b != 0) {
				list<int>::iterator iter_bg = l.begin();

				l.splice(l.end(), l, iter_bg, iter_b);
			}
			l.pop_front();
		}
		else {
			cnt += (l.size() - cnt_b);
			if ((l.size() - cnt_b) != 0) {

				l.splice(l.begin(), l, iter_b, l.end());
			}
			
			l.pop_front();
		}
	}
	cout << cnt <<"\n";

	return 0;
}