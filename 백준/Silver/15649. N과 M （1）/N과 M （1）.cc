#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> v;
int visited[9] = { 0, };
int N = 0, M = 0;

void recur(int depth) {
	if (depth == M) {
		for (auto elements : v) cout << elements << " ";

		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (visited[i]) continue;

		v.push_back(i);
		visited[i] = true;
		recur(depth + 1);
		visited[i] = false;
		v.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		visited[i] = false;
	}

	recur(0);
}
