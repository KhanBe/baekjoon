#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(m, 0));

	int num = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> num;
			v[i][j] = num;
		}
	}

	int x1, y1, x2, y2;

	int k;
	cin >> k;
	for (int q = 0; q < k; q++) {
		cin >> x1 >> y1 >> x2 >> y2;
		int answer = 0;
		for (int i = x1 - 1; i < x2; i++) {
			for (int j = y1 - 1; j < y2; j++) {
				answer += v[i][j];
			}
		}
		cout << answer << "\n";
	}
}