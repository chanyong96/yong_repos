#include <iostream>
#include <list>
#include <string>

using namespace std;

int main(void) {
	int N;
	cin >> N;
	list<long> l;
	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;
		if (s == "push_front") {
			long x;
			cin >> x;
			l.push_front(x);
		}
		else if (s == "push_back") {
			long x;
			cin >> x;
			l.push_back(x);
		}
		else if (s == "pop_front") {
			if (l.empty()) cout << "-1" << "\n";
			else {
				auto it = l.begin();
				cout << (*it) << "\n";
				l.pop_front();
			}
		}
		else if (s == "pop_back") {
			if (l.empty()) cout << "-1" << "\n";
			else {
				auto it = l.end();
				it--;
				cout << (*it) << "\n";
				l.pop_back();
			}
		}
		else if (s == "size") {
			cout << l.size() << "\n";
		}
		else if (s == "empty") {
			if (l.empty()) cout << "1" << "\n";
			else cout << "0" << "\n";
		}
		else if (s == "front") {
			if (l.empty()) cout << "-1" << "\n";
			else cout << l.front() << "\n";
		}
					
		else if (s == "back") {
			if (l.empty()) cout << "-1" << "\n";
			else cout << l.back() << "\n";
		}


	}
	return 0;
}