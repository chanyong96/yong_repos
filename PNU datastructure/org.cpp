#include <bits/stdc++.h>

using namespace std;

struct researcher {
	string name;	// 연구원 이름 : 알파벳으로 표현
	int sub_num = 0;	// 부하직원의 수
	int boss_num = 0;// 직속상관의 수
};

// 부하직원의 수를 계산하는 함수
int count_sub(vector<string> sub, vector<string> boss, string s) {
	int cnt = 0;
	for (int id = 0; id < boss.size(); ++id) {
		if (s == boss[id]) {
			cnt++;
			cnt += count_sub(sub, boss, sub[id]);
		}
	}
	return cnt;
}

// root에 얼마나 가까운지를 계산하는 함수
int distance_root(vector<string> sub, vector<string> boss, string s) {
	int boss_cnt = 0;
	for (int i = 0; i < sub.size(); ++i) {
		if (sub[i] == s) {
			boss_cnt++;
			boss_cnt += distance_root(sub, boss, boss[i]);
		}
	}
	return boss_cnt;
}

// 정렬조건
bool sub_larger(researcher A, researcher B) {
	if (A.sub_num > B.sub_num) {
		return true;
	}
	else if (A.sub_num == B.sub_num) {
		if (A.boss_num < B.boss_num) {
			return true;
		}
		else if (A.boss_num == B.boss_num) {
			if (A.name < B.name)
				return true;
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}

int main(void) {
	ifstream input;
	ofstream output;
	input.open("org.inp");
	output.open("org.out");

	int N;
	input >> N;
	vector<researcher> org;
	vector<string> v_sub, v_boss; // 크기가 N-1
	for (int i = 0; i < N - 1; ++i) {
		string sub, boss;
		input >> sub >> boss;

		v_sub.push_back(sub);
		v_boss.push_back(boss);

		researcher A, B;
		vector<researcher>::iterator it;
		for (it = org.begin(); it != org.end() && !((*it).name == sub); ++it);
		if (it == org.end()) {
			A.name = sub;
			org.push_back(A);
		}
		for (it = org.begin(); it != org.end() && !((*it).name == boss); ++it);
		if (it == org.end()) {
			B.name = boss;
			B.sub_num++;
			org.push_back(B);
		}
		else 
			(*it).sub_num++;
	}
	for (auto it = org.begin(); it != org.end(); ++it) {
		(*it).sub_num = count_sub(v_sub, v_boss, (*it).name);
		(*it).boss_num = distance_root(v_sub, v_boss, (*it).name);
	}
	sort(org.begin(), org.end(), sub_larger);
	for (int i = 0; i < org.size(); ++i) {
		output << org[i].name;
		if (i == org.size() - 1) {
			break;
		}
		output << " ";
	}

	return 0;
}