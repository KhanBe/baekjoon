#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

	vector<int> vec;

	int answer = 0;

	int n, cash;
	cin >> n >> cash;
	
	int unit;
	for (int i = 0; i < n; i++) {
		cin >> unit;
		vec.push_back(unit);
	}

	for (int i = n - 1; i >= 0; i--) {
		unit = vec[i];
		if (cash / unit >= 1) {
			answer += cash / unit;
			cash %= unit;
		}
		if (cash == 0) break;
	}
	
	cout << answer;
}