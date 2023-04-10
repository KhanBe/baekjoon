#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;

	vector<pair<int, int>> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first;
		arr[i].second = i;
	}
	sort(arr.begin(), arr.end());

	int max = 0;
	for (int i = 0; i < n; i++) {
		int dis = arr[i].second - i;

		max = dis > max ? dis : max;
	}
	cout << max + 1;
}