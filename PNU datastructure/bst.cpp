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
				else if (j == bst.size() - 1) {		// BST에 없다면 leaf 위치에 추가!
					nd.name = s;
					bst.push_back(nd);
				}
			}
			
			// 입력받은 string을 leaf 위치에 삽입
		}
		else if (oper == "-") {
			string s;
			cin >> s;
			// 입력받은 string 노트 삭제 및 재배치
		}
		else if (oper == "depth") {
			int k;
			cin >> k;
			// depth가 k인 모든 노드 출력
		}
		else if (oper == "leaf") {
			// leaf 노드들 출력!!
		}
		else
			cout << "Enter right instruction!!" << "\n";
	}
	//input.close();
	//output.close();

	return 0;
}