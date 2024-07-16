#include <iostream>
#include <vector>

using namespace std;

int dp[12] = { 0, 1, 2,4};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n = 0;
	cin >> n;
	for (int i = 4; i <= 11; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
	int num = 0;
	for (int i = 0; i < n; i++) {
		cin >> num;
		cout << dp[num] << "\n";

	}
}
