#include<iostream>
#include<vector>
#include<queue>

#define INF 987654321

using namespace std;

vector<int> weight;
vector<pair<int, int>> node[805];

struct compare {
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
		return a.first > b.first;
	}
};

void dijkstra(int start) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

	pq.push({ 0, start });
	weight[start] = 0;

	while (!pq.empty()) {
		int curWeight = pq.top().first;
		int curNode = pq.top().second;
		pq.pop();

		for (int i = 0; i < node[curNode].size(); i++) {
			int nextWeight = node[curNode][i].second;
			int nextNode = node[curNode][i].first;

			if (weight[nextNode] > nextWeight + curWeight) {
				weight[nextNode] = nextWeight + curWeight;
				pq.push({ weight[nextNode], nextNode });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long int answer = 0, answer1 = 0, answer2 = 0;

	int N, E;
	cin >> N >> E;
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		node[a - 1].push_back({ b - 1, c });
		node[b - 1].push_back({ a - 1, c });
	}

	int v1, v2;
	cin >> v1 >> v2;

	long long int v1_1, v1_v2, v1_n, v2_1, v2_n;

	weight.assign(N, INF);
	dijkstra(v1 - 1);
	v1_1 = weight[0];
	v1_v2 = weight[v2 - 1];
	v1_n = weight[N - 1];

	weight.assign(N, INF);

	dijkstra(v2 - 1);
	v2_1 = weight[0];
	v2_n = weight[N - 1];

	answer1 = v1_1 + v1_v2 + v2_n;
	answer2 = v2_1 + v1_v2 + v1_n;

	answer = answer1 < answer2 ? answer1 : answer2;
	if (answer >= INF) answer = -1;

	cout << answer;

	return 0;// 확인해보기
}