#include <iostream>

using namespace std;

/*
�Է����� ���� �� ���ǵ��� ������ ��ƿ �� �ִ� ���Թ��� ������ ����ȿ� �� �� �ִ� ����� �� ���ϱ�
*/
void MAX_WORTH (const int item_weight[], const int item_worth[], const int n, const int k) {
	int case_insertitem[n];
	
}

int main() {
	int N, K;
	cin >> N >> K;
	int* ITEM_WEIGHT = new int[N];
	int* ITEM_WORTH = new int[N];

	for (int i = 0; i < N; i++) {
		int W, V;
		cin >> W >> V;
		ITEM_WEIGHT[i] = W;
		ITEM_WORTH[i] = V;
	}
	MAX_WORTH(ITEM_WEIGHT, ITEM_WORTH, N, K);
	
	return 0;
}