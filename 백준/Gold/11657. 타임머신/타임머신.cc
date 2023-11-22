#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <climits>

using namespace std;

#define INF 2100000000
bool cycle;
long long weight[501];
vector<pair<int, int>> node[501];

void bellman_ford(int size) {
	fill(weight, weight + size + 1, INF);
	weight[1] = 0;
	
	for (int k = 1; k <= size; k++) {
		for (int i = 1; i <= size; i++) {
			for (int j = 0; j < node[i].size(); j++) {
				int nextNode = node[i][j].first;
				int nextWeight = node[i][j].second;

				if (weight[i] != INF && weight[nextNode] > weight[i] + nextWeight) {
					weight[nextNode] = weight[i] + nextWeight;

					if (k == size) cycle = true;
				}
			}
		}
	}
	if (cycle) cout << -1;
	else {
		for (int i = 2; i <= size; i++) {
			cout << (weight[i] != INF ? weight[i] : -1) << "\n";
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int from, to, time;
		cin >> from >> to >> time;
		node[from].push_back({ to, time });
	}

	bellman_ford(n);
	return 0;
}