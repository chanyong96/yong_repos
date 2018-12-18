#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream input, log;
	ofstream output;
	input.open("log.inp");
	log.open("syslog.txt");
	output.open("log.out");

	int K;
	input >> K;

	int* date_start = new int[K];
	int* time_start = new int[K];
	int* date_end = new int[K];
	int* time_end = new int[K];
	int* result_arr = new int[K];
	
	for (int i = 0; i < K; i++) {
		input >> date_start[i] >> time_start[i] >> date_end[i] >> time_end[i];
	}

	int N;
	log >> N;
	int* log_TimeCount = new int[N]; // 
	for (int i = 0; i < N; i++) {
		log_TimeCount[i] = 0;
	}

	// 가로 : 10,000  세로 : N인 2차원 배열 생성!
	int** log_arr = new int*[N];
	for (int i = 0; i < N; i++) {
		log_arr[i] = new int[1000];
	}

	// syslog내용 입력받아들이기
	for (int i = 0; i < N; i++) {
		int A = 0;
		while (true) {
			log >> log_arr[i][A];
			if (log_arr[i][A] == 0) {
				break;
			}
			else
				A++;
		}
		log_TimeCount[i] += (A-1);
		if (i > 0) {
			log_TimeCount[i] += log_TimeCount[i - 1];
		}
	}

	for (int i = 0; i < K; i++) {
		int ds_ind=0, de_ind=0, count = 0;
		int ts_ind=1, te_ind = 1;

		while (true) { // ds, ts 잡아주는 루프
			if (date_start[i] < log_arr[ds_ind][0]  ) { // log_date[ds_ind]
				break;
			}
			else if (date_start[i] == log_arr[ds_ind][0]) { // log_arr[ds_ind][0]
				if (ds_ind==0){
					if (time_start[i] > log_arr[ds_ind][log_TimeCount[ds_ind]]) {
						ts_ind = log_TimeCount[ds_ind]+1;
					}
					else {
						while (time_start[i] > log_arr[ds_ind][ts_ind]) { 
							ts_ind++;
							
						}
					}	
				}
				else {
					if (time_start[i] > log_arr[ds_ind][(log_TimeCount[ds_ind] - log_TimeCount[ds_ind - 1])]) {
						ts_ind = (log_TimeCount[ds_ind] - log_TimeCount[ds_ind - 1] + 1);
					}
					else {
						while (time_start[i] > log_arr[ds_ind][ts_ind]) { 
							ts_ind++;
						}
					}
				}
				
				break;
			}
			else if (date_start[i] > log_arr[ds_ind][0]) { // log_arr[ds_ind][0]
				if (ds_ind == N-1) {
					result_arr[i] = 0;
					break;
				}
				ds_ind++;
			}

		}
		while (true) { // de, te 잡아주는 루프
			if (date_end[i] > log_arr[de_ind][0]) {				// log_arr[de_ind][0]
				if (de_ind == N-1) {
					 te_ind = log_TimeCount[de_ind]-log_TimeCount[de_ind-1]+1;
					break;
				}
				de_ind++;
			}
			else if (date_end[i] == log_arr[de_ind][0]) { // log_arr[de_ind][0]
				// 아래 while문 대체할 if문
				if (de_ind==0){
					if (time_end[i] > log_arr[de_ind][log_TimeCount[0]]) {
						te_ind = log_TimeCount[de_ind] + 1;
					}
					else {
						while (time_end[i] > log_arr[de_ind][te_ind]) {
							te_ind++;
						}
					}
					
				}
				else {
					if (time_end[i] > log_arr[de_ind][(log_TimeCount[de_ind] - log_TimeCount[de_ind - 1])]) {
						te_ind = (log_TimeCount[de_ind] - log_TimeCount[de_ind - 1]) + 1;
					}
					else {
						while (time_end[i] > log_arr[de_ind][te_ind]) {
							te_ind++;
						}
					}
				}
				
				if (time_end[i] < log_arr[de_ind][te_ind]) {
					te_ind--;
				}
				else if (log_arr[de_ind][te_ind] == 0) {
					te_ind--;
				}
				break;
			}
			else if (date_end[i] < log_arr[de_ind][0]) { // log_arr[de_ind][0]
				if (de_ind == 0) {
					result_arr[i] = 0;
					break;
				}
				else {
					de_ind--;
					te_ind = log_TimeCount[de_ind] - log_TimeCount[de_ind - 1] + 1;
					break;
				}
			}
		}
		// cout << "de_ind = " << de_ind << ", te_ind : " << te_ind << "\n";
		 if (ds_ind > de_ind || date_start[i] > log_arr[N-1][0] || date_end[i] < log_arr[0][0]) { // 오류 처리
		 }

		 else if (ds_ind == de_ind) {
			 if (time_end[i] < log_arr[de_ind][1]) {

			 }
			 else
				  count += (te_ind - ts_ind)+1;
		 }
		 else if (de_ind - ds_ind == 1) {
			 if (ds_ind == 0) {
				 count += log_TimeCount[0] - (ts_ind - 1);
			 }
			 else
				  count+=log_TimeCount[ds_ind]-log_TimeCount[ds_ind-1]-(ts_ind-1);

			 if (log_arr[de_ind][te_ind] == 0) {
				 count += (te_ind - 1);
			 }
			 else {
				 count += te_ind;
			 }
		 }
		 else if (de_ind - ds_ind > 1) {
			 // 1. ds_ind인덱스의 시간들 count , 2. for() , 3. de_ind인덱스의 시간들 count
			 if (ds_ind == 0) {
				 count += log_TimeCount[0] - (ts_ind - 1);
			 }
			 else
				 count += (log_TimeCount[ds_ind] - log_TimeCount[ds_ind - 1] - (ts_ind - 1));

			 count = count + (log_TimeCount[de_ind-1] - log_TimeCount[ds_ind]);
			 
			 if (log_arr[de_ind][te_ind] == 0) {
				 count += (te_ind - 1);
			 }
			 else {
				 count += te_ind;
			 }

		 }
		 result_arr[i] = count;
	}


	for (int i = 0; i < K; i++) {
		output << result_arr[i] << "\n";
	}

	// 동적할당시킨 배열들 해제
	delete[] date_start;
	delete[] time_start;
	delete[] date_end;
	delete[] time_end;
	delete[] result_arr;
	delete[] log_TimeCount;

	for (int i = 0; i < N; i++) {
		delete[] log_arr[i];
	}

	delete[] log_arr;

	input.close();
	log.close();
	output.close();
	return 0;
}
