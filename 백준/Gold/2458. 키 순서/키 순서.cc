#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> taller_node[501];
vector<int> shorter_node[501];
bool taller_visited[501];
bool shorter_visited[501];
int taller = 0, shorter = 0;
int answer = 0;

void taller_bfs(int start) {
	queue<int> q;

	taller_visited[start] = true;
	taller = 0;
	q.push(start);

	while (!q.empty()) {
		int CurNode = q.front();
		q.pop();

		for (int i = 0; i < taller_node[CurNode].size(); i++) {
			int NextNode = taller_node[CurNode][i];

			if (taller_visited[NextNode]) continue;
			taller_visited[NextNode] = true;
			taller++;
			q.push(NextNode);
			//cout << "-- : " << NextNode << "\n";
		}
	}
	//cout << "톨러 : " << taller << "\n";
}

void shorter_bfs(int start) {
	queue<int> q;

	shorter_visited[start] = true;
	shorter = 0;
	q.push(start);

	while (!q.empty()) {
		int CurNode = q.front();
		q.pop();

		for (int i = 0; i < shorter_node[CurNode].size(); i++) {
			int NextNode = shorter_node[CurNode][i];

			if (shorter_visited[NextNode]) continue;
			shorter_visited[NextNode] = true;
			shorter++;
			q.push(NextNode);
			//cout << "-- : " << NextNode << "\n";
		}
	}
	//cout << "쇼터 : " << shorter << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	
	int n, k;
	cin >> n >> k;
	
	for (int i = 0; i < k; i++) {
		int from, to;
		cin >> from >> to;

		taller_node[from].push_back(to);
		shorter_node[to].push_back(from);
	}
	
	for (int i = 1; i <= n; i++) {
		taller_bfs(i);
		shorter_bfs(i);
		if (taller + shorter == n - 1) answer++;
		//cout << "------------\n";
		for (int j = 0; j <= n; j++) {
			taller_visited[j] = false;
			shorter_visited[j] = false;
		}
	}
	
	cout << answer;
	return 0;
}