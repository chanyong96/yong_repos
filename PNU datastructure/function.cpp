#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <fstream>

using namespace std;

bool IsDeadlock(stack<string> _st, string cp_s) {
	stack<string> cmp_s(_st);
	for (int i = 0; i < cmp_s.size(); i++) {
		if (cmp_s.top() == cp_s) {
			return true;
		}
		cmp_s.pop();
	}
	return false;
}

bool f_IsFunc(const vector<vector<string>> vec, const int _N, const int a, const int b) {
	bool isFunc = false;
	for (int i = 0; i < _N; i++) {
		if (vec[a][b] == vec[i][0]) {
			isFunc = true;
			break;
		}
	}
	return isFunc;
}

int FuncIndex(const vector<vector<string>> vec, const string str) {
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i][0] == str) {
			return i;
		}
	}
}

int main(void) {
	ifstream input;
	ofstream output;
	input.open("ev5-h.inp");
	output.open("function.out");

	int N, k1, k2;
	input >> N >> k1 >> k2;
	vector<vector<string>> v(N);
	for (int i = 0; i < N; i++) {
		string s;
		while (true) {
			input >> s;
			v[i].push_back(s);
			if (s == "$") {
				break;
			}
		}
	}
	input.close();

	//DEADLOCK인지 아닌지 먼저 판별!
	int count_test = 0;
	int row_test = 0, column_test = 0;
	int max_count = 0;
	for (int i = 0; i < v.size(); i++) {
		max_count += v[i].size();
	}
	stack<string> str_test;
	stack<int> row_test_t, column_test_t;
	bool isDeadlock[10][30] = { 0, };
	int* f_cnt = new int[N];
	for (int i = 0; i < N; i++)
		f_cnt[i] = 0;
	int f_count = 0;
	for (int i = 0; i < N; i++) {
		// 함수 v[i][0] 중 그 함수 내부에 함수이름이 하나라도 없으면 일반 string으로 취급하기!!
		for (int j = 1; j < v[i].size(); j++) {
			for (int k = 0; k < N; k++) {
				if (v[i][j] == v[k][0])
					f_cnt[i]++;
			}
		}
	}
	for (int i = 0; i < N; i++)
		cout << f_cnt[i] << "\n";



	bool DL = false;
	while (!(row_test == 0 && column_test == v[0].size() - 1)) {
		count_test++;
		if (f_IsFunc(v, N, row_test, column_test)) {
			if (IsDeadlock(str_test, v[row_test][column_test])) {
				DL = true;
				break;
			}
			else {
				str_test.push(v[row_test][column_test]);
				row_test_t.push(row_test);
				column_test_t.push(column_test);
				row_test = FuncIndex(v, v[row_test][column_test]);
				column_test = 1;
			}
		}
		else {
			column_test++;
			if (f_IsFunc(v, N, row_test, column_test)) {
				if (IsDeadlock(str_test, v[row_test][column_test])) {
					DL = true;
					break;
				}
				else {
					str_test.push(v[row_test][column_test]);
					row_test_t.push(row_test);
					column_test_t.push(column_test);
					row_test = FuncIndex(v, v[row_test][column_test]);
					column_test = 1;
				}
			}
		}

		if (str_test.size() != 0 && v[row_test][column_test] == "$") {
			if (row_test == 0 && column_test == v[0].size() - 1) {
				break;
			}
			else {
				row_test = row_test_t.top();
				column_test = column_test_t.top() + 1;
				str_test.pop();
				row_test_t.pop();
				column_test_t.pop();
			}
		}
	}
	if (DL) {
		output << "DEADLOCK" << "\n";
	}
	else {
		if (count_test <= k1)
			output << "NONE" << "\n";
		else {
			int count_k1 = 0;
			int row_k1 = 0, column_k1 = 0;
			stack<string> str_st1;
			stack<int> row_st1, column_st1;

			while (!(row_k1 == 0 && column_k1 == v[0].size() - 1)) {
				count_k1++;
				if (f_IsFunc(v, N, row_k1, column_k1)) {
					str_st1.push(v[row_k1][column_k1]);
					row_st1.push(row_k1);
					column_st1.push(column_k1);
					row_k1 = FuncIndex(v, v[row_k1][column_k1]);
					column_k1 = 1;
				}
				else {
					column_k1++;
					if (f_IsFunc(v, N, row_k1, column_k1)) {
						str_st1.push(v[row_k1][column_k1]);
						row_st1.push(row_k1);
						column_st1.push(column_k1);
						row_k1 = FuncIndex(v, v[row_k1][column_k1]);
						column_k1 = 1;
					}
				}

				if (str_st1.size() != 0 && v[row_k1][column_k1] == "$") {
					row_k1 = row_st1.top();
					column_k1 = column_st1.top() + 1;
					str_st1.pop();
					row_st1.pop();
					column_st1.pop();
				}
				if (count_k1 == k1) {
					output << v[row_k1][0] << "-" << v[row_k1][column_k1] << "\n";
					break;
				}
			}
		}
		
		
		if (count_test <= k2) {
			output << "NONE" << "\n";
		}
		else {
			int count_k2 = 0;
			int row_k2 = 0, column_k2 = 0;
			stack<string> str_st2;
			stack<int> row_st2, column_st2;

			while (!(row_k2 == 0 && column_k2 == v[0].size() - 1)) {
				count_k2++;
				if (f_IsFunc(v, N, row_k2, column_k2)) {
					str_st2.push(v[row_k2][column_k2]);
					row_st2.push(row_k2);
					column_st2.push(column_k2);
					row_k2 = FuncIndex(v, v[row_k2][column_k2]);
					column_k2 = 1;
				}
				else {
					column_k2++;
					if (f_IsFunc(v, N, row_k2, column_k2)) {
						str_st2.push(v[row_k2][column_k2]);
						row_st2.push(row_k2);
						column_st2.push(column_k2);
						row_k2 = FuncIndex(v, v[row_k2][column_k2]);
						column_k2 = 1;
					}
				}

				if (str_st2.size() != 0 && v[row_k2][column_k2] == "$") {
					row_k2 = row_st2.top();
					column_k2 = column_st2.top() + 1;
					str_st2.pop();
					row_st2.pop();
					column_st2.pop();
				}
				if (count_k2 == k2) {
					output << v[row_k2][0] << "-" << v[row_k2][column_k2] << "\n";
					break;
				}
			}
		}
	}
	output.close();

	return 0;
}