#include <iostream>
#include <fstream>

using namespace std;

int main(void) {
    ifstream input;
    ofstream output;

    input.open("1.inp");
    // output.open("parking.out");

    int K, N;
    input >> K >> N;
	
	int* car_arr = new int[N];
    for (int i=0;i<N;i++) {
        input >> car_arr[i];
    }

	input.close();

    int* tnum_car = new int[N]; // i+1��° �������� ���� �����忡 �� ������ �ڵ��� ��
    tnum_car[0]=1;

    for (int i=1;i<N;i++) {
        if (car_arr[i]>0) {
            tnum_car[i]=(tnum_car[i-1]+1);
        }
        else if (car_arr[i]<0){
            tnum_car[i]=(tnum_car[i-1]-1);
        }
    }

    
    /*for (int i=0; i<N ;i++) {
        cout << tnum_car[i] << "\n";
    }*/

	/*
	
	*/

	// ���� �Ҵ� �� �ο����ִ� �迭
	int* slot_num = new int[N];
	int num = 0;
	int num_empty = 0;
	const int orig_K = K;
	// main �˰���
	/*
	for��
	- car_arr[i] > 0�̸� ����, car_arr[i] < 0�̸� ����
	- tnum_car[i] == K�̸� ������ 2�� Ȯ��(���⼭���� K�� ���� �������� ũ��� ����)
	- tnum_car[i] <= (K/3)�̸� ������ ũ�� ������ ����
	*/
	
	for (int i = 1; i < N; i++) {
		if (car_arr[i]>0) { // ����
			if (tnum_car[i-1] == K) { // ���� ���������̾��� �� 
				K = K * 2;
			}
			else {	// �������� ���� ��
				slot_num[i] = tnum_car[i]; 
			}
		}
		else if (car_arr[i]<0){ // ����
			if (tnum_car[i-1] <= K/3) { // ������ �������� ��üũ���� 1/3������ ��
				if (K < orig_K) {

				}
				else {

				}
			}
			else {

			}
		}
	}

	

   

	// N���� ���� �Է� �� ������ ���� �����忡 �����ִ� ����� �� ������ 
	// �����Ǿ��ִ� ������ ������ ��ȣ ���

	delete[] car_arr;
	delete[] tnum_car;


    return 0;
}
