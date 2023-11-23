#include <iostream>
#include <vector>
#include <algorithm>


#define INF 987654321

using namespace std;

int V, E;
int city[101][101];

void floyd() {
	for (int k = 1; k <= V; k++) {
		for (int i = 1; i <= V; i++) {
			for (int j = 1; j <= V; j++) {
				city[i][j] = min(city[i][j], city[i][k] + city[k][j]);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> V;
	cin >> E;

	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			if (i == j) city[i][j] = 0;
			else city[i][j] = INF;
		}
	}
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		city[a][b] = min(city[a][b], c);
	}

	floyd();

	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			if (city[i][j] == INF) cout << "0 ";
			else cout << city[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}