#include <bits/stdc++.h>

using namespace std;

int main(void) {
	vector<int> lst;
	string buf;
	int T, N, elem, rflag, it1, it2, c;
	char erase;
	cin >> T;
	for (int i = 0; i<T; i++) {
		lst.clear();
		buf.clear();
		cin >> buf >> N;
		it1 = rflag = c = 0;
		it2 = N - 1;
		//초기화

		if (N)
			for (int j = 0; j<2 * N + 1; j++) {
				if (j % 2) {
					cin >> elem;
					lst.push_back(elem);
				}
				else
					cin >> erase;
			}
		else
			cin >> erase >> erase;
		// 입력부

		for (int j = 0; j<buf.length(); j++)
			if (buf[j] == 'R')
				rflag = !rflag;
			else {
				c++;
				if (c>N) {
					cout << "error\n";
					break;
				}
				if (rflag)
					it2--;
				else
					it1++;
			}

			if (c <= N) {
				cout << '[';
				if (rflag) {
					for (int j = it2; j>it1; --j)
						cout << lst[j] << ',';
					if (N - c)
						cout << lst[it1];
				}
				else {
					for (int j = it1; j<it2; ++j)
						cout << lst[j] << ',';
					if (N - c)
						cout << lst[it2];
				}
				cout << "]\n";
			}
	}
	return 0;
}

//#include <bits/stdc++.h>
//
//using namespace std;
//
//int main(void) {
//	int T;
//	cin >> T;
//
//	vector<string> v_func, v_arr;
//	vector<long> v_arr_s;
//	string func, arr;
//	long arr_s;
//	for (int i = 0; i < T; ++i) {
//		cin >> func;
//		v_func.push_back(func);
//		cin >> arr_s;
//		v_arr_s.push_back(arr_s);
//		cin >> arr;
//		v_arr.push_back(arr);
//	}
//	list<string> l;
//	vector<string> result;
//	// for (int j = 1; j <= arr_s; ++j) l.push_back(j);
//	// 집합 원소들을 container에 담기
//	string tmp;
//	for (long j = 1; j < arr.size(); ++j) {
//		if (arr[j] == ']') {
//			l.push_back(tmp);
//			tmp.clear();
//		}
//		else if (arr[j] != ',') {
//			tmp.push_back(arr[j]);
//		}
//		else {
//			l.push_back(tmp);
//			tmp.clear();
//		}
//	}
//	long cnt_D = 0;
//	for (long j = 0; j < func.size(); ++j) {
//		if (func[j] == 'D') cnt_D++;
//	}
//	if (cnt_D > arr_s) {
//		result.push_back("error");
//		// cout << "error" << "\n";
//	}
//	else {
//		for (long j = 0; j < func.size(); ++j) {
//			if (l.empty()) {
//				result.push_back("error");
//				// cout << "error" << "\n";
//				break;
//			}
//			else if (func[j] == 'R') {
//				if (!(l.empty()))
//					l.reverse();
//				else {
//					result.push_back("error");
//					// cout << "error" << "\n";
//					continue;
//				}
//
//
//			}
//			else if (func[j] == 'D') {
//				if (!l.empty())
//					l.pop_front();
//				else {
//					result.push_back("error");
//					// cout << "error" << "\n";
//					continue;
//				}
//
//			}
//		}
//		string s_tmp;
//		s_tmp.push_back('[');
//		// cout << "[";
//		auto iter = l.end();
//		iter--;
//		for (auto it = l.begin(); it != l.end(); it++) {
//			s_tmp += (*it);
//			// cout << (*it);
//			if (it != iter) {
//				s_tmp += ',';
//			}
//		}
//		s_tmp.push_back(']');
//		result.push_back(s_tmp);
//	}
//	for (auto it = result.begin(); it != result.end();it++) {
//		cout << (*it) << "\n";
//	}
//
//	return 0;
//}