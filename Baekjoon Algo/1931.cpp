#include <iostream>


using namespace std;

int main()
{
	int N;
	cin >> N;
	int* startArr = new int[N];
	int* endArr = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> startArr[i];
		cin >> endArr[i];	
	}

	/*
	1. endArr�� ���� �� ���� ���� �� ã��
	2. ã�Ƴ� ���� ���� ���� �ε��� ã�� (K��� Ī�ϰ���)
	3. startArr[K]~endArr[K]�� ��ġ�� ȸ�� ����
	4. 

	*/
	

	return 0;
}


/*
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string A;
	cin >> A;
	cout << A << "\n";
	
	
	return 0;
}
*/