#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 987654321

using namespace std;

int n;
vector<pair<int, int>> v;
int dp[1001] = { 0, };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int term, value;
		cin >> term >> value;
		v.push_back({ term, value });
	}

	for (int i = n - 1; i >= 0; i--) {
		int term = v[i].first;
		int value = v[i].second;
		int deadline = i + term;
		if (deadline <= n) {// n -> 퇴사일
			dp[i] = max(dp[deadline] + value, dp[i + 1]);
		}
		else {
			dp[i] = dp[i + 1];
		}
	}
	
	cout << dp[0];
	return 0;
}
