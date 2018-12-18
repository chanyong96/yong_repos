#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

int main(void) {
	ifstream input;
	ofstream output;
	input.open("shopping.inp");
	output.open("shopping.out");

	int N, k;
	input >> N >> k;
	vector<int> customer_num, customer_item_num, total;
	for (int i = 0; i < N; i++) {
		int ctm_num, ctm_itemNum;
		input >> ctm_num >> ctm_itemNum;
		customer_num.push_back(ctm_num);
		customer_item_num.push_back(ctm_itemNum);
	}
	
	vector<queue<int>> q_cus(k), q_time(k);
	vector<int> sum; // 누적시간 저장
	for (int i = 0; i < N; i++) {
		if (i < k) {
			q_cus[i].push(customer_num[i]);
			q_time[i].push(customer_item_num[i]);
			sum.push_back(customer_item_num[i]);
		}
		else {
			// sum[0], sum[1], ... , sum[k-1] 중 가장 작은 수가 들은 인덱스 찾기
			int cmp = 1001, idx = 0;
			for (int j = 0; j < k; j++) {
				if (sum[j] < cmp)
					cmp = sum[j];
			}
			for (int j = 0; j < k; j++) {
				if (cmp == sum[j]) {
					idx = j;
					break;
				}
			}			
			q_cus[idx].push(customer_num[i]);
			q_time[idx].push(q_time[idx].back()+customer_item_num[i]);
			sum[idx]+=customer_item_num[i];
		}
	}
	if (N < k) {
		for (int i = N; i < k; i++) {
			q_time[i].push(1001);
		}
	}
	
	int cnt = N;
	while (cnt != 0) {
		int mini=1000, flag = 0;
		for (int i = 0; i < q_time.size(); i++) {
			if (mini > q_time[i].front()) {
				mini = q_time[i].front();
			}
		}
		for (int i = q_time.size()-1; i >= 0; i--) {
			if (mini == q_time[i].front()) {
				flag = i;
				break;
			}
		}

		total.push_back(q_cus[flag].front());
		q_cus[flag].pop();
		q_time[flag].pop();
		if (q_time[flag].size() == 0)
			q_time[flag].push(1001);
		cnt--;
	}
	for (int i = 0; i < N; i++) {
		output << total[i] << "\n";
	}
		
	input.close();
	output.close();
	return 0;
}