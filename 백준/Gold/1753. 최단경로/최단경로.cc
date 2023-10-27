#include<iostream>
#include<vector>
#include<queue>

#define INT_MAX 987654321

using namespace std;

vector<pair<int, int>> node[20001];
vector<int> weight;

struct compare {
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
		return a.first > b.first;
	}
};


void dijkstra(int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare>pq;

	pq.push(make_pair(0, start));// first = weight / second node
	weight[start] = 0;

	while (!pq.empty()) {
		int curWeight = pq.top().first;
		int curNode = pq.top().second;
		pq.pop();

		for (int i = 0; i < node[curNode].size(); i++) {
			int NextNode = node[curNode][i].first;
			int NextWeight = node[curNode][i].second;

			if (weight[NextNode] > curWeight + NextWeight) {
				
				weight[NextNode] = curWeight + NextWeight;
				pq.push({ weight[NextNode], NextNode });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V, E, start;

	cin >> V >> E;
	cin >> start;


	int from, to, w;



	for (int i = 0; i < E; i++) {
		cin >> from >> to >> w;// u -> v = w 

		node[from - 1].push_back(make_pair(to - 1, w));
	}

	weight.assign(V, INT_MAX);

	dijkstra(start - 1);

	for (int i = 0; i < weight.size(); i++) {
		if (weight[i] == INT_MAX) cout << "INF\n";
		else cout << weight[i] << "\n";
	}

	return 0;
}