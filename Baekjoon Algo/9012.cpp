#include <iostream>
#include <string>
#include <stack>

using namespace std;

/*
입력한 괄호문자열들이 VPS인지 확인하는 함수
stack개념 활용
*/

bool Verify(string st) {
	int len = st.length();
	
	stack<char> s;

	for (int k = 0; k < len; k++) {
		char c = st[k];
		
		if (c == '(')
			s.push(st[k]);
		else {
			if (!s.empty())
				s.pop();
			else
				return false;
		}
	}

	return s.empty();
}

int main()
{
	int T;
	cin >> T;
	
	for (int i = 0; i < T; i++) {
		string str;
		cin >> str;
		
		if (Verify(str))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;	
	}

	return 0;
}
