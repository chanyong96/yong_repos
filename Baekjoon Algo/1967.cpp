#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n;

const int MAX = 10000 + 1;
bool visited[MAX];
vector<pair<int, int>> graph[MAX];

int diameter = 0;
int farthestNode = 0;

void DFS(int node, int cost) {
	if (visited[node])
		return;
	visited[node] = true;

	if (diameter < cost) {
		diameter = cost;
		farthestNode = node;
	}

	for (int k = 0; k < graph[node].size(); k++) {
		DFS(graph[node][k].first, cost + graph[node][k].second);
	}

}


int main() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int node1, node2, cost;
		cin >> node1 >> node2 >> cost;

		graph[node1].push_back(make_pair(node2, cost));
		graph[node2].push_back(make_pair(node1, cost));
	}
	memset(visited, false, sizeof(visited));
	DFS(1, 0);
	memset(visited, false, sizeof(visited));
	DFS(farthestNode, 0);
	cout << diameter << "\n";

	return 0;
}