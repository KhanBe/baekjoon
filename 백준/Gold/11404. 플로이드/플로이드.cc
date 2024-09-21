#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX 987654321

int city[101][101];
int n = 0;
int m = 0;

void floyd() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				city[i][j] = min(city[i][j], city[i][k] + city[k][j]);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	cin >> m;
	
	for (int i = 1; i <= n; i++) {//fill
		for (int j = 1; j <= n; j++) {
			if (i == j) city[i][j] = 0;
			else city[i][j] = MAX;
		}
	}


	for (int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		city[a][b] = min(city[a][b], w);
	}

	floyd();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (city[i][j] == MAX) cout << "0 ";
			else cout << city[i][j] << " ";
		}
		cout << "\n";
	}
}