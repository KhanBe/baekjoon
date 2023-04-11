#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> arr;
vector<bool> visited;
bool arrive;

void dfs(int node, int depth) {
	visited[node] = true;

	if (5 <= depth) {
		arrive = true;
		return;
	}

	for (int i = 0; i < arr[node].size(); i++) {
		int next = arr[node][i];
		if (!visited[next]) {
			dfs(next, depth + 1);
		}
	}
	visited[node] = false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	arrive = false;
	cin >> N >> M;
	arr.resize(N);
	visited = vector<bool>(N, false);

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		//양방향
		arr[a].push_back(b);
		arr[b].push_back(a);
	}

	for (int i = 0; i < N; i++) {
		dfs(i, 1);
	}

	cout << arrive;
}