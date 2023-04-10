#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio;
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<int> arr(n + 1, 0);

	for (int i = 0; i < n; i++) cin >> arr[i];

	int answer = n + 1;
	int start = 0;
	int end = 0;
	int sum = arr[0];

	while (end < n && start <= end) {
		if (sum < m) {
			sum += arr[++end];
		}
		else if (sum >= m) {
			answer = answer > (end - start + 1) ? (end - start + 1) : answer;
			sum -= arr[start++];
		}
	}
	
	if (answer == n + 1) answer = 0;
	cout << answer;
}