#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

struct Customer {
	string name;
	int grade;
	int money;
};

struct Compare {
	bool operator() (Customer A, Customer B) {
		if (A.grade != B.grade)
			return (A.grade > B.grade);
		else
			return (A.money < B.money);
	}
};

int main(void) {
	cout << "N을 입력하세요." << "\n";
	int N, numb=1;
	cin >> N;
	priority_queue<Customer, vector<Customer>, Compare> PQ;
	cout << "손님들의 이름, 신용등급 입/출금액을 입력하세요." << "\n";
	cout << "혹은 한번에 처리할 인원수를 입력하세요." << "\n";
	for (int i = 0; i < N; ++i) {
		Customer person;
		string nm;
		int money, grade, k;
		cin >> nm;
		if (nm == "Call") {
			cin >> k;
			int cnt = 0;
			if (k <= PQ.size())
				cout << k << "명을 동시에 처리합니다.\n";
			while (!(PQ.empty()) && cnt < k) {
				Customer c = PQ.top();
				printf("%3d번째 고객 이름 : ", numb);
				cout << c.name << "\n";
				printf("고객 신용등급 : ");
				printf("%5d\t", c.grade);
				printf("고객 입/출금액 : ");
				printf("%10d\n", c.money);
				printf("---------------------------------------------\n");

				//cout << "고객 이름 : ";
				//cout << c.name << "\t";
				//cout << "고객 신용등급 : ";
				//cout << c.grade << "\t";
				//cout << "고객 입/출금액 : ";
				//cout << c.money << "\n";
				PQ.pop();
				cnt++;
				numb++;
			}
		}
		else {
			cin >> grade >> money;
			person.name = nm;
			person.grade = grade;
			person.money = money;
			PQ.emplace(person);
		}
	}

	while (!PQ.empty()) {
		Customer c = PQ.top();
		//printf("%s %s %s %d %s %d\n", "고객 이름 : ", c.name, "고객 신용등급 : ", c.grade, "고객 입/출금액", c.money);
		printf("%3d번째 고객 이름 : ", numb);
		cout << c.name << "\n";
		printf("고객 신용등급 : ");
		printf("%5d\t", c.grade);
		printf("고객 입/출금액 : ");
		printf("%10d\n", c.money);
		printf("---------------------------------------------\n");
		/*cout << "고객 이름 : ";
		cout << c.name << "\t";
		cout << "고객 신용등급 : ";
		cout << c.grade << "\t";
		cout << "고객 입/출금액 : ";
		cout << c.money << "\n";*/
		PQ.pop();
		numb++;
	}
	return 0;
}