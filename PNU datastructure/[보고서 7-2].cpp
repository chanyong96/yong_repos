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
	cout << "N�� �Է��ϼ���." << "\n";
	int N, numb=1;
	cin >> N;
	priority_queue<Customer, vector<Customer>, Compare> PQ;
	cout << "�մԵ��� �̸�, �ſ��� ��/��ݾ��� �Է��ϼ���." << "\n";
	cout << "Ȥ�� �ѹ��� ó���� �ο����� �Է��ϼ���." << "\n";
	for (int i = 0; i < N; ++i) {
		Customer person;
		string nm;
		int money, grade, k;
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
				printf("�� �ſ��� : ");
				printf("%5d\t", c.grade);
				printf("�� ��/��ݾ� : ");
				printf("%10d\n", c.money);
				printf("---------------------------------------------\n");

				//cout << "�� �̸� : ";
				//cout << c.name << "\t";
				//cout << "�� �ſ��� : ";
				//cout << c.grade << "\t";
				//cout << "�� ��/��ݾ� : ";
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
		//printf("%s %s %s %d %s %d\n", "�� �̸� : ", c.name, "�� �ſ��� : ", c.grade, "�� ��/��ݾ�", c.money);
		printf("%3d��° �� �̸� : ", numb);
		cout << c.name << "\n";
		printf("�� �ſ��� : ");
		printf("%5d\t", c.grade);
		printf("�� ��/��ݾ� : ");
		printf("%10d\n", c.money);
		printf("---------------------------------------------\n");
		/*cout << "�� �̸� : ";
		cout << c.name << "\t";
		cout << "�� �ſ��� : ";
		cout << c.grade << "\t";
		cout << "�� ��/��ݾ� : ";
		cout << c.money << "\n";*/
		PQ.pop();
		numb++;
	}
	return 0;
}