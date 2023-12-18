#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	vector<pair<int, bool>> v(9);

	int sum = 0;
	for (int i = 0; i < 9; i++) {
		cin >> v[i].first;
		v[i].second = true;

		sum += v[i].first;
	}
	sum -= 100;
	sort(v.begin(), v.end());

	bool found = false;
	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (v[i].first + v[j].first == sum) {
				v[i].second = false;
				v[j].second = false;
				found = true;
				break;
			}
		}
		if (found) break;
	}

	for (int i = 0; i < 9; i++) {
		if (v[i].second) cout << v[i].first << "\n";

	}

	return 0;
}