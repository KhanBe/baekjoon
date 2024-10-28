#include <iostream>
#include <vector>

using namespace std;
int dp[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int answer = 0;
	int n = 0;
	cin >> n;
	
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int temp = 0;
		cin >> temp;
		v.push_back(temp);
		dp[i] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (v[j] < v[i]) dp[i] = max(dp[i], dp[j] + 1);
		}
	}

	for (auto a : dp) answer = max(answer, a);
	
	cout << answer;
	


	return 0;
}