#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int parent[10001];

class Edge {
private:
	int node[2];
	int weight;

public:
	Edge(int a, int b, int weight){
		this->node[0] = a;
		this->node[1] = b;
		this->weight = weight;
	}
	int getNode(int x) {
		return this->node[x];
	}
	int getWeight() {
		return this->weight;
	}
	bool operator < (Edge& Edge) {
		return this->weight < Edge.weight;
	}
};

int find(int x) {//대표집합 찾기
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void uni(int x, int y) {//같은 소속 만들기
	x = find(x);
	y = find(y);
	if (x == y) return;//같은 소속이면
	parent[y] = x;
}

bool sameParent(int x, int y) {
	x = find(x);
	y = find(y);
	return x == y ? true : false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int E = 0;
	int V = 0;
	int answer = 0;

	vector<Edge> edge;

	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge.push_back(Edge(a, b, c));
	}
	sort(edge.begin(), edge.end());

	for (int i = 1; i <= V; i++) parent[i] = i;

	for (int i = 0; i < edge.size(); i++) {
		int x = edge[i].getNode(0);
		int y = edge[i].getNode(1);
		int w = edge[i].getWeight();
		if (!sameParent(x, y)) {
			uni(x, y);
			answer += w;
		}
	}

	cout << answer;
}