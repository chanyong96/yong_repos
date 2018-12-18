#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>

using namespace std;

int main(void) {
	 ifstream input;
	 ofstream output;

	input.open("card.inp");
	output.open("card.out");
	int N, K;
	input >> N >> K;

	list<int> l;

	for (int i = 1; i <= N; ++i) {
		l.push_back(i);
	}
	
	for (int i = 0; i < K; ++i) {
		string s;
		input >> s;
		if (s == "Shuffle") {
			list<int>::iterator s_range_begin = l.begin();
			list<int>::iterator s_range_end=l.begin();
			if (N % 2 == 0) {
				advance(s_range_end, N / 2);
			}
			else {
				advance(s_range_end, N / 2 + 1);
			}
			
			vector<int> s_front_tmp;
			for (auto it = s_range_begin; it != s_range_end; ++it) {
				s_front_tmp.push_back(*it);
			}
			l.erase(s_range_begin, s_range_end);

			list<int>::iterator s_back_range_begin = l.begin();
			list<int>::iterator s_back_range_end = l.end();

			vector<int> s_tmp;
			for (auto it = s_back_range_begin; it != s_back_range_end; ++it) {
				s_tmp.push_back(*it);
			}
			l.erase(s_back_range_begin, s_back_range_end);
			for (int k = 0; k < s_tmp.size(); ++k) {
				l.push_back(s_front_tmp[k]);
				l.push_back(s_tmp[k]);
			}
			if (N % 2 == 1) {
				int v_size = s_front_tmp.size();
				l.push_back(s_front_tmp[v_size - 1]);
			}
		}

		else if (s == "Cut") {
			int _start, _end;
			input >> _start >> _end;
			list<int>::iterator range_begin = l.begin();
			list<int>::iterator range_end = l.begin();
			advance(range_begin, _start-1);
			advance(range_end, _end);
			vector<int> tmp;
			for (auto it = range_begin; it != range_end; ++it) {
				tmp.push_back(*it);
			}
			l.erase(range_begin, range_end);

			for (int _i = 0; _i < tmp.size(); ++_i) {
				l.push_back(tmp[_i]);
			}
		}
	}
	input.close();

	list<int>::iterator iter = l.begin();
	output << *iter << " ";
	advance(iter, N / 2 - 1);
	output << *iter << " ";
	iter = l.end();
	iter--;
	output << *iter << "\n";
	



	output.close();
	return 0;
}