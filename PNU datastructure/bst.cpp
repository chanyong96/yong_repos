#include <bits/stdc++.h>

using namespace std;

struct Node {
	string name, left_child="", right_child="";
	int depth=1;
	bool is_node =false, is_leaf=true;
};

int main(void) {
	//ifstream input;
	//ofstream output;
	//input.open("bst.inp");
	//output.open("bst.out");

	int N;
	cin >> N;
	vector<Node> bst(N);
	
	for (int i = 0; i < N; ++i) {
		string oper;
		Node nd;
		cin >> oper;
		if (oper == "+") {
			string s;
			cin >> s;
			for (int j = 0; j < bst.size(); ++j) {
				if (bst[j].name == s)	
					break;
				else if (j == bst.size() - 1) {		// BST�� ���ٸ� leaf ��ġ�� �߰�!
					nd.name = s;
					bst.push_back(nd);
				}
			}
			
			// �Է¹��� string�� leaf ��ġ�� ����
		}
		else if (oper == "-") {
			string s;
			cin >> s;
			// �Է¹��� string ��Ʈ ���� �� ���ġ
		}
		else if (oper == "depth") {
			int k;
			cin >> k;
			// depth�� k�� ��� ��� ���
		}
		else if (oper == "leaf") {
			// leaf ���� ���!!
		}
		else
			cout << "Enter right instruction!!" << "\n";
	}
	//input.close();
	//output.close();

	return 0;
}