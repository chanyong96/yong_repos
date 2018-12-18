#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void) {
	string s;
	cin >> s;

	stack<char> st;
	int sum = 0, tmp=1;
	
	// 곱해야 되는 경우는 곱셈 끝까지 다해서 sum에 누적시키기
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == '(')
			st.push(s[i]);
		if (s[i] == '[')
			st.push(s[i]);
		if (s[i] == '{')
			st.push(s[i]);

		if (s[i] == ')') { // 2
			if (st.empty() || st.top() != '(') {
				cout << "0" << "\n";
				return 0;
			}
			else {
				if (tmp > 1) {
					st.pop();
					if (!st.empty()) {
						tmp *= 2;
					}
					else {
						tmp *= 2;
						sum += tmp;
						tmp = 1;
					}
				}
				else {
					st.pop();
					if (!st.empty())
						tmp = tmp * 2;
					else
						sum += 2;
				}
			}
		}
			
		if (s[i] == ']') { // 3
			if (st.empty() || st.top() != '[') {
				cout << "0" << "\n";
				return 0;
			}
			else {
				if (tmp > 1) {
					st.pop();
					if (!st.empty()) {
						tmp *= 3;
					}
					else {
						tmp *= 3;
						sum += tmp;
						tmp = 1;
					}
				}
				else {
					st.pop();
					if (!st.empty())
						tmp = tmp * 3;
					else
						sum += 3;
				}
			}
		}
		if (s[i] == '}') { // 4
			if (st.empty() || st.top() != '{') {
				cout << "0" << "\n";
				return 0;
			}
			else {
				if (tmp > 1) {
					st.pop();
					if (!st.empty()) {
						tmp *= 4;
					}
					else {
						tmp *= 4;
						sum += tmp;
						tmp = 1;
					}
				}
				else {
					st.pop();
					if (!st.empty())
						tmp = tmp * 4;
					else
						sum += 4;
				}
			}
		}
	}
	if (!st.empty())
		cout << "0" << "\n";
	else
		cout << sum << "\n";
	return 0;
}