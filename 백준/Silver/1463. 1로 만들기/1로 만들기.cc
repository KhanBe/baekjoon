#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 987654321

using namespace std;

int n;

void bfs(int start) {
	queue<pair<int, int>> q;
	q.push({start, 0});

	while (!q.empty()) {
		int number = q.front().first;
		int minCount = q.front().second;
		q.pop();

		if (number == 1) {
			cout << minCount;
			return;
		}

		if (number % 3 == 0) {
			q.push({ number / 3, minCount + 1 });
		}
		if (number % 2 == 0) {
			q.push({ number / 2, minCount + 1 });
		}
		q.push({ number - 1, minCount + 1 });
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;

	bfs(n);

	return 0;
}
