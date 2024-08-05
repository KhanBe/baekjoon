#include <iostream>
#include <vector>

using namespace std;

int arr[10001];
int dp[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);


	int left = 0, right = 0;
	int n = 0, length = 0;
	cin >> n;

	int temp = n;
	while (0 < temp) {
		temp /= 10;
		length++;
	}

	int half = length / 2;
	while (half != length) {
		int temp = n % 10;
		right += temp;
		n /= 10;
		
		half++;
	}
	
	while (0 < n) {
		int temp = n % 10;
		left += temp;
		n /= 10;

		length++;
	}

	cout << (left == right ? "LUCKY" : "READY");
}
