#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int answer = 0;
	int n;
	cin >> n;

	vector<pair<int, int>> data(n);

	for (int i = 0; i < n - 1; i++) {

		cin >> data[i].first;
	}
	for (int i = 0; i < n; i++) {

		cin >> data[i].second;
	}
	
	int curLiter = data[0].second;
	for (int i = 0; i < n - 1; i++) {
		curLiter = data[i].second < curLiter ? data[i].second : curLiter;
		answer += curLiter * data[i].first;
	}

	cout << answer;

	return 0;
}