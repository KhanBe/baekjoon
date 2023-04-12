#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool endSort(pair<int, int> &a, pair<int, int> &b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<pair<int, int>> A(N);
	for (int i = 0; i < N; i++) {
		int start, end;
		cin >> start >> end;
		A[i] = { start, end };
	}

	sort(A.begin(), A.end(), endSort);

	int answer = 1;
	int start = A[0].first, end = A[0].second;
	for (int i = 1; i < N; i++) {
		if (end <= A[i].first) {
			start = A[i].first;
			end = A[i].second;
			answer++;
		}
	}

	cout << answer;
}