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
	cout << "N�� �Է��ϼ���." << "\n";
	int N;
	cin >> N;
	priority_queue<Customer, vector<Customer>, Compare> PQ;
	int numb = 1;

	cout << "�մԵ��� �̸�, ��/��ݾ��� �Է��ϼ���." << "\n";
	cout << "Ȥ�� �ѹ��� ó���� �ο����� �Է��ϼ���." << "\n";
	for (int i = 0; i < N; ++i) {
		Customer person;
		string nm;
		int money, k;
		cin >> nm;
		
		if (nm == "Call") {
			cin >> k;
			int cnt = 0;
			if (k <= PQ.size())
				cout << k << "���� ���ÿ� ó���մϴ�.\n";
			while (!(PQ.empty()) && cnt < k) {
				Customer c = PQ.top();
				printf("%3d��° �� �̸� : ", numb);
				cout << c.name << "\n";
				printf("   �� ��/��ݾ� : ");
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
		printf("%3d��° �� �̸� : ", numb);
		cout << c.name << "\n";
		printf("   �� ��/��ݾ� : ");
		printf("%10d\n", c.money);
		printf("---------------------------------------------\n");
		PQ.pop();
		numb++;
	}
	return 0;
}