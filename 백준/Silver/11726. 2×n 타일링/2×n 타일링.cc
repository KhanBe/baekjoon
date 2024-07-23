#include <iostream>
#include <vector>

using namespace std;

long dp[1001] = { 0, 1, 2, 3, 5 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	int n = 0;
	cin >> n;
	for (int i = 5; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}

	cout << dp[n];
}
