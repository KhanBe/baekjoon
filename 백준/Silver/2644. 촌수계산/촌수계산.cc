#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 987654321

using namespace std;

int n, m;
int start, end1;
vector<int> node[101];
int visited[101];

void bfs() {
	queue<int> q;
	visited[start] = 0;
	q.push(start);

	while (!q.empty()) {
		int curNode = q.front();
		q.pop();
		
		for (int i = 0; i < node[curNode].size(); i++) {
			int nNode = node[curNode][i];
			if (visited[nNode] == 0) {
				visited[nNode] = visited[curNode] + 1;
				q.push(nNode);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	cin >> start >> end1;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		node[x].push_back(y);
		node[y].push_back(x);
	}
	
	bfs();
	//for (auto v : visited) cout << v << " ";
	if (!visited[end1]) cout << "-1";
	else cout << visited[end1];
	
	return 0;
}
