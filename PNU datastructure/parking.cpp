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

    int* tnum_car = new int[N]; // i+1번째 삽입했을 때의 주차장에 총 주차된 자동차 수
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

	// 슬롯 할당 및 부여해주는 배열
	int* slot_num = new int[N];
	int num = 0;
	int num_empty = 0;
	const int orig_K = K;
	// main 알고리즘
	/*
	for문
	- car_arr[i] > 0이면 주차, car_arr[i] < 0이면 출차
	- tnum_car[i] == K이면 주차장 2배 확장(여기서부터 K를 현재 주차장의 크기로 정의)
	- tnum_car[i] <= (K/3)이면 주차장 크기 반으로 줄임
	*/
	
	for (int i = 1; i < N; i++) {
		if (car_arr[i]>0) { // 입차
			if (tnum_car[i-1] == K) { // 남은 주차공간이없을 때 
				K = K * 2;
			}
			else {	// 주차공간 있을 때
				slot_num[i] = tnum_car[i]; 
			}
		}
		else if (car_arr[i]<0){ // 출차
			if (tnum_car[i-1] <= K/3) { // 주차된 차량수가 전체크기의 1/3이하일 때
				if (K < orig_K) {

				}
				else {

				}
			}
			else {

			}
		}
	}

	

   

	// N개의 차들 입력 다 들어오면 현재 주차장에 남아있는 차들과 그 차들이 
	// 주차되어있는 주차장 슬롯의 번호 출력

	delete[] car_arr;
	delete[] tnum_car;


    return 0;
}
