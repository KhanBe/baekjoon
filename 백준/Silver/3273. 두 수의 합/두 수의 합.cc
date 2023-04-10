#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio;
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n;

	vector<int> arr(n, 0);

	for (int i = 0; i < n; i++) cin >> arr[i];
	cin >> m;

	sort(arr.begin(), arr.end());

	//for (auto a : arr) cout << a << " ";

	int answer = 0;
	int start = 0;
	int end = n - 1;
	while (start < end) {
		int sum = arr[start] + arr[end];

		if (sum > m) end--;
		else if (sum < m) start++;
		else if (sum == m) {
			answer++;
			start++;
		}
	}
	cout << answer;
}