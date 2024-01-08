#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> &v1, pair<int, int> &v2) {
	//if (v1.second == v2.second) return v1.first < v2.first;
	return v1.second > v2.second;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<pair<int, int>> v;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int d, w;
		cin >> d >> w;
		v.push_back({d, w});
	}
	
	sort(v.begin(), v.end(), compare);

	int score[1001] = { 0, };

	for (int i = 0; i < n; i++) {
		for (int j = v[i].first; j > 0; j--) {
			if (score[j] == 0) {
				score[j] = v[i].second;
				break;
			}
		}
	}
	int answer = 0;
	for (int i = 1; i <= 1000; i++) {
		answer += score[i];
	}
	cout << answer;

	return 0;
}