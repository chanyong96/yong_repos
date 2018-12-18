#include <bits/stdc++.h>

using namespace std;

struct Customer {
	string name;
	int money;
};

struct Compare {
	bool operator() (Customer A, Customer B) {
		return (A.money < B.money);
	}
};

int main(void) {
	cout << "N을 입력하세요." << "\n";
	int N;
	cin >> N;
	priority_queue<Customer, vector<Customer>, Compare> PQ;
	int numb = 1;

	cout << "손님들의 이름, 입/출금액을 입력하세요." << "\n";
	cout << "혹은 한번에 처리할 인원수를 입력하세요." << "\n";
	for (int i = 0; i < N; ++i) {
		Customer person;
		string nm;
		int money, k;
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
				printf("   고객 입/출금액 : ");
				printf("%10d\n", c.money);
				printf("---------------------------------------------\n");
				PQ.pop();
				cnt++;
				numb++;
			}
		}
		else {
			cin >> money;
			person.name = nm;
			person.money = money;
			PQ.emplace(person);
		}
	}
	
	while (!PQ.empty()) {
		Customer c = PQ.top();
		printf("%3d번째 고객 이름 : ", numb);
		cout << c.name << "\n";
		printf("   고객 입/출금액 : ");
		printf("%10d\n", c.money);
		printf("---------------------------------------------\n");
		PQ.pop();
		numb++;
	}
	return 0;
}