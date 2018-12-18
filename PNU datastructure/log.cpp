#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

//typedef struct {
//	vector<int> sname;
//	long long start;
//	long long end;
//
//}Xnode;
//
//int main(void) {
//	/*
//	ifstream input;
//	ofstream output;
//	input.open("log.inp");
//	output.open("log.out");
//	*/
//	
//	long N;
//	int K;
//	cin >> N >> K;
//	list<Xnode> log(N);
//	list<Xnode>::iterator it = log.begin();
//	for (int i = 0; i < N; ++i) {
//		int user_num;
//		long long time_start, time_end;
//		cin >> user_num;
//		(*it).sname.push_back(user_num);
//		cin >> time_start >> time_end;
//		(*it).start = time_start;
//		(*it).end = time_end;
//		it++;
//	}
//	for (int i = 0; i < K; ++i) {
//		long long time_sch;
//		cin >> time_sch;
//	}
//	for (auto iter = log.begin(); iter != log.end(); ++iter) {
//		cout << (*iter).sname[0] << " ";
//		cout << (*iter).start << " ";
//		cout << (*iter).end << "\n";
//	}
//	return 0;
//}

typedef struct {
	int sname;
	long long start;
	long long end;

}Xnode;

int main(void) {
	
	ifstream input;
	ofstream output;
	input.open("log.inp");
	output.open("log.out");

	long N;
	int K;
	input >> N >> K;
	list<Xnode> log(N);
	list<Xnode>::iterator it = log.begin();
	for (int i = 0; i < N; ++i) {
		int user_num;
		long long time_start, time_end;
		input >> user_num;
		(*it).sname = user_num;
		input >> time_start >> time_end;
		(*it).start = time_start;
		(*it).end = time_end;
		it++;
	}
	vector<long long> time_ques;
	for (int i = 0; i < K; ++i) {
		long long time_sch;
		input >> time_sch;
		time_ques.push_back(time_sch);
	}
	vector<vector<int>> log_v(K);
	for (int i = 0; i < K; ++i) {
		int cnt = 0;
		for (auto iter = log.begin(); iter != log.end(); ++iter) {
			if (time_ques[i] >= (*iter).start && time_ques[i] <= (*iter).end) {
				log_v[i].push_back((*iter).sname);
				cnt++;
			}
		}
		if (cnt == 0) log_v[i].push_back(0);
		else sort(log_v[i].begin(), log_v[i].end());
	}

	for (int i = 0; i < K; ++i) {
		for (int j=0;j<log_v[i].size();++j)
			output << log_v[i][j] << " ";
		output << "\n";
	}
	
	return 0;
}